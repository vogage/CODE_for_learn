//
//  857_Minimum Cost to Hire K Workers.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/10.
//

#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

class Worker{
public:
    int quality;
    int wage;
    double ratio;
    Worker(int q,int w):quality(q),wage(w),ratio((double)wage/(double)(quality)){}
};

bool RatioCMP(Worker& w1,Worker &w2){
    return w1.ratio<w2.ratio;
}

class QualityCMP{
public:
    bool operator ()(Worker& w1,Worker& w2){
        return w1.quality<w2.quality;
    }
};
typedef priority_queue<Worker,vector<Worker>,QualityCMP> WorkerPQ;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        //constructor the ratio order vector
        vector<Worker> WorkerVec;
        for(int i=0;i<quality.size()&&i<wage.size();i++){
            WorkerVec.push_back(Worker(quality[i],wage[i]));
        }
        //sort the vec from the ratio small to big
        sort(WorkerVec.begin(),WorkerVec.end(),RatioCMP);
        //construct the priority_queue which the largets quality is in the top
        WorkerPQ PQ;
        //choose the first k num of Worker which is smallest ratio
        int quality_sum=0;
        for(int i=0;i<k;i++){
            PQ.push(WorkerVec[i]);
            quality_sum+=WorkerVec[i].quality;
        }
        double res=(double)quality_sum*WorkerVec[k-1].ratio;
        for(int i=k;i<WorkerVec.size();i++){
        //just pop the quality more than the ith worker
            if(PQ.top().quality>WorkerVec[i].quality){
                quality_sum=quality_sum-PQ.top().quality+WorkerVec[i].quality;
                PQ.pop();
                PQ.push(WorkerVec[i]);
                res=min((double)quality_sum*WorkerVec[i].ratio,res);
            }
        }
        return res;
    }
private:

};

int main(){
    Solution mysolu;
    vector<int> quality = {3,1,10,10,1};
    vector<int> wage = {4,8,2,2,7};
    int k = 3;
    
    vector<int> quality2 ={32,43,66,9,94,57,25,44,99,19};
    vector<int> wage2 ={187,366,117,363,121,494,348,382,385,262};
    int k2 = 4;
    double res=mysolu.mincostToHireWorkers(quality2, wage2, k2);
    return 0;
}

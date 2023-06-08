//
//  497_Random Point in Non-overlapping Rectangles.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/6.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<vector<int>>& rects) {
        //calcualte the area
        AreaSum=0;
        Candidates=rects;
        for(int i=0;i<rects.size();i++){
            long long area=(rects[i][3]-rects[i][1]+1)*(rects[i][2]-rects[i][0]+1);
            AreaSum+=area;
            RectArea.push_back(AreaSum);
        }
    }
    
    vector<int> pick() {
        vector<int> res(2,0);
        int Index=rand()%(AreaSum+1);// this is very important,or the areasum can not be selected!!!
        int i=0;
        while(RectArea[i]<Index) i++;
        int width=Candidates[i][2]-Candidates[i][0]+1;
        int hight=Candidates[i][3]-Candidates[i][1]+1;
        
        res[0]=Candidates[i][0]+rand()%width;
        res[1]=Candidates[i][1]+rand()%hight;
        
        return res;
    }
private:
    vector<vector<int>> Candidates;
    vector<long long> RectArea;
    long long AreaSum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

int main(){
    vector<vector<int>> rects={{-2, -2, 1, 1}, {2, 2, 4, 6}};
    vector<vector<int>> rects2={{-58953616,-40483558,-58953446,-40482555},{76369640,94978791,76371036,94979394},{80970826,-37466957,80971657,-37466388},{-79821573,-4177978,-79820536,-4177925}};
    vector<vector<int>>rects3={{82918473,-57180867,82918476,-57180863},{83793579,18088559,83793580,18088560},{66574245,26243152,66574246,26243153},{72983930,11921716,72983934,11921720}};
    vector<vector<int>>rects4={{53487036,-14015982,53487038,-14015981},{-50242787,-25148635,-50242784,-25148633},{1261120,-29805890,1261122,-29805889},{28991269,54212557,28991271,54212559}};
    Solution*obj=new Solution(rects4);
    vector<int> param_1=obj->pick();
    vector<int> param_2=obj->pick();
    vector<int> param_3=obj->pick();
    vector<int> param_4=obj->pick();
    vector<int> param_5=obj->pick();
    vector<int> param_6=obj->pick();
    return 0;
}

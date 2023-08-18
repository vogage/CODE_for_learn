//
//  850_Rectangle Area II.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/3.
//

#include <stdio.h>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Rect{
    int left;
    int right;
    int bottom;
    int top;
    Rect(int l,int r,int b,int t):left(l),right(r),bottom(b),top(t){}
};


class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long mod=1000000007;
        // use left and bottom as compare base
        map<int,map<int,vector<Rect>>> RectMap;
        long long res=0;
        for(int i=0;i<rectangles.size();i++){
            queue<Rect> temp;
            temp.push(Rect(rectangles[i][0],rectangles[i][2],rectangles[i][1],rectangles[i][3]));
            insert_rect(RectMap,temp);
            while(!temp.empty()){
                Rect candi=temp.front();
                temp.pop();
                res+=(long long)(candi.right-candi.left)*(long long)(candi.top-candi.bottom);
                res=res%mod;
                RectMap[candi.left][candi.bottom].push_back(candi);
            }
        }
        return res;
    }
private:
    void insert_rect(map<int,map<int,vector<Rect>>>& RectMap, queue<Rect>& temp){
        if(temp.size()!=1)return ;
        Rect OriginRect=temp.front();
        
        auto MaxLeftRect=RectMap.upper_bound(OriginRect.right);
        for(auto RectsLeftIndex=RectMap.begin();RectsLeftIndex!=MaxLeftRect;RectsLeftIndex++){
            auto MaxBottomRect=RectsLeftIndex->second.upper_bound(OriginRect.top);
            for(auto Rvec=RectsLeftIndex->second.begin();Rvec!=MaxBottomRect;Rvec++){
                for(auto R:Rvec->second){
                    queue<Rect> temp2;
                    while(!temp.empty()){
                        Rect candi=temp.front();
                        temp.pop();
                        cut_rect(R,candi,temp2);
                    }
                    temp=temp2;
                }
            }
        }
       
    }
private:
    void cut_rect(Rect& R,Rect& candi,queue<Rect>& temp2){
        Rect OverlapRect(max(R.left,candi.left),min(R.right,candi.right),max(R.bottom,candi.bottom),min(R.top,candi.top));
        // jude the overlap is existing
        if(!(OverlapRect.left<OverlapRect.right&&OverlapRect.top>OverlapRect.bottom)){
            temp2.push(candi);
            return;
        }
        // candi - overlap
        if(candi.left<OverlapRect.left){
            temp2.push(Rect(candi.left,OverlapRect.left,candi.bottom,candi.top));
        }
        if(candi.right>OverlapRect.right){
            temp2.push(Rect(OverlapRect.right,candi.right,candi.bottom,candi.top));
        }
        if(candi.bottom<OverlapRect.bottom){
            temp2.push(Rect(OverlapRect.left,OverlapRect.right,candi.bottom,OverlapRect.bottom));
        }
        if(candi.top>OverlapRect.top){
            temp2.push(Rect(OverlapRect.left,OverlapRect.right,OverlapRect.top,candi.top));
        }
        
    }
};

int main(){
    Solution mysolu;
    vector<vector<int>>  rectangles ={{0,0,2,2},{1,0,2,3},{1,0,3,1}};
    vector<vector<int>>  rectangles1={{93516,44895,94753,69358},{13141,52454,59740,71232},{22877,11159,85255,61703},{11917,8218,84490,36637},{75914,29447,83941,64384},{22490,71433,64258,74059},{18433,51177,87595,98688},{70854,80720,91838,92304},{46522,49839,48550,94096},{95435,37993,99139,49382},{10618,696,33239,45957},{18854,2818,57522,78807},{61229,36593,76550,41271},{99381,90692,99820,95125}};
    int res=mysolu.rectangleArea(rectangles1);
    return 0;
}

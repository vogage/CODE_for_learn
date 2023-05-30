//
//  478_Generate Random Point in a Circle.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/29.
//

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using  namespace std;

//478. Generate Random Point in a Circle

class Solution {
public:
    Solution(double radius, double x_center, double y_center) {
        rad=radius;
        x0=x_center;
        y0=y_center;
    }
    
    vector<double> randPoint() {
        //srand(time(NULL));
//        double sinv=2*((double)rand()/(double)RAND_MAX)-1;
//        double cosv=sqrt(1-sinv*sinv);
//        if(rand()%2==1) cosv=-cosv;
//        double ang = (double)rand() / RAND_MAX * 2 * M_PI;
//        double cosv=cos(ang);
//        double sinv=sin(ang);
        double sinv=2*((double)rand()/(double)RAND_MAX)-1;
      //        double cosv=sqrt(1-sinv*sinv);
        double cosv=2*((double)rand()/(double)RAND_MAX)-1;
        if(sinv*sinv+cosv*cosv>1)return randPoint();
        double radv=(double)rand()/(double)RAND_MAX*rad;
        cout<<"cosv:"<<cosv<<" sinv:"<<sinv<<" radv:"<<radv<<endl;
        vector<double> res(2,0);
       
        res[0]=x0+radv*cosv;
        res[1]=y0+radv*sinv;
        return res;
    }
private:
    double rad;
    double x0;
    double y0;
   
    
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */


int main(){
    
    Solution *obj=new Solution(0.01,-73839.1,-3289891.3);
    vector<double> para1=obj->randPoint();
    vector<double> para2=obj->randPoint();
    vector<double> para3=obj->randPoint();
    vector<double> para4=obj->randPoint();
    vector<double> para5=obj->randPoint();
    vector<double> para6=obj->randPoint();
    vector<double> para7=obj->randPoint();
    vector<double> para8=obj->randPoint();
    vector<double> para9=obj->randPoint();
    return 0;
}

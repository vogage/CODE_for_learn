//
//  331_Verify Preorder Serialization of a Binary Tree.cpp
//  leetcode
//
//  Created by qiandehou on 2021/4/2.
//

#include <stdio.h>
#include<string>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size()==0)return false;
        int n=preorder.size();
        vector<string> pv;
        //pv.push_back(preorder[0]);
        string str="";
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==','){
                if(i-1>=0&&preorder[i-1]==',')return false;
                if(str.size()!=0) {
                    pv.push_back(str);
                    str="";
                }
            }else{
                str+=preorder[i];
            }
        }
        if(str.size()) pv.push_back(str);
        stack<pair<string,int>> st;
        if(pv[0]!="#")st.push(pair<string,int>(pv[0],2));
        else if(pv.size()==1)return true;
        else return false;
        for(int i=1;i<pv.size();i++){
            if(st.empty())return false;
            if(pv[i]=="#"){
                st.top().second--;
                while(!st.empty()&&st.top().second==0){
                    st.pop();
                    if(!st.empty()) st.top().second--;
                }
            }else{
                st.push(pair<string,int>(pv[i],2));
            }
        }
        
        
        
        //while(!st.empty()&&st.top().first=='#')st.pop();
        return st.empty();
    }
   
};

class Solution2{
public:
    bool isValidSerialization(string preorder) {
        if(preorder.size()==0)return false;
        int n=preorder.size();
        vector<string> pv;
        //pv.push_back(preorder[0]);
        string str="";
        for(int i=0;i<preorder.size();i++){
            if(preorder[i]==','){
                if(i-1>=0&&preorder[i-1]==',')return false;
                if(str.size()!=0) {
                    pv.push_back(str);
                    str="";
                }
            }else{
                str+=preorder[i];
            }
        }
        if(str.size()) pv.push_back(str);
        int diff=1;
        for(int i=0;i<pv.size();i++){
            if(--diff<0)return false;
            if(pv[i]!="#") diff+=2;
        }
        return diff==0;
    }
};





int main(){
    Solution2 mysolu;
    string input="9,3,4,#,#,1,#,#,2,#,6,#,#";
    string input1="1,#";
    string input2="9,#,92,#,#";
    string input3="#";
    bool res=mysolu.isValidSerialization(input1);
    return 0;
    
}

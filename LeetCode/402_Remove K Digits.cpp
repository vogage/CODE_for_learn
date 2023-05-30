//
//  402_Remove K Digits.cpp
//  leetcode
//
//  Created by qiandehou on 2021/10/29.
//

//Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.
#include<string>
#include<stack>

using namespace std;


class Solution {
public:
    string removeKdigits(string num, int k) {
        return support_remove(num,k);
        
            
        

    }
    string support_remove(string num,int k){
        if(k==0)return num;
        int n=num.size();
        //case1
       //remove the first digit
        int i=1;
        for(;i<n;i++){
            if(num[i]=='0') continue;
            else break;
        }
        if(i==n)return "0";
        string case_num1=num.substr(i,n-1);
        
        //case2
        //remove the following digit
        string case_num2="";
        i=1;
        for(;i<n-1;i++){
            if(num[i]>num[i+1]){
                case_num2=num.substr(0,i)+num.substr(i+1,n-i-1); break;
            }
        }
        if(i==n-1) case_num2=num.substr(0,i);
        string str1=support_remove(case_num1, k-1);
        string str2=support_remove(case_num2, k-1);
        if(compare(str1, str2)){
            return str1;
        }else{
            return str2;
        }
    }
    
    //s1<s2 : output true
    bool compare(const string &s1,const string &s2){
        if(s1.size()>s2.size()) return false;
        else if(s1.size()<s2.size()) return true;
        else{
            for(int i=0;i<s1.size()&&i<s2.size();i++){
                if(s1[i]!=s2[i]) return s1[i]<s2[i];
            }
        }
        return true;
    }
};


class Solution2{
public:
    string removeKdigits(string num, int k) {
        //stack
        
        if(k==num.size())return "0";
        

        stack<char> st;
        st.push(num[0]);
        int i=1;
        while(i<num.size()){
            while(!st.empty()&&k&&st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
            
        }
        while(i<num.size()){
            st.push(num[i]);
            i++;
        };
        while(k>0){st.pop();k--;}
        string res="";
        while(!st.empty()){
            res=res+st.top();
            st.pop();
            
        }
        reverse(res.begin(), res.end());
        i=0;
        while(i<res.size()&&res[i]=='0')i++;
        res=res.substr(i,res.size()-i);
        return res.size()==0?"0":res;
    }
};

class Solution3{
public:
    string removeKdigits(string num, int k) {
        string ans="";
        for(char c:num){
            while(ans.length()&&ans.back()>c&&k){
                ans.pop_back();
                k--;
            }
            if(ans.length()||c!='0') ans.push_back(c);
        }
        while(ans.length()&&k--)ans.pop_back();
        return ans.size()==0? "0":ans;
    }
};

int main(){
    Solution3 mysolu;
    string num = "1432219";
    int k = 3;
    string num1= "10200";
    int k1= 1;
    string num2="10";
    int k2=2;
    string num3="212";
    int k3=1;
    string num4="10";
    int k4=1;
   
    string num5="9";
    int k5=1;
    
    string num6="10001";
    int k6=1;
    
    string num7="10";
    int k7=1;
    
    string num8="1234567890";
    int k8=9;
    string res=mysolu.removeKdigits(num1, k1);
    return 0;
}

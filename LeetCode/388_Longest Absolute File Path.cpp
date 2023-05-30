//
//  388_Longest Absolute File Path.cpp
//  leetcode
//
//  Created by 钱德厚 on 2022/11/14.
//

#include <stdio.h>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int lengthLongestPath(string input) {
        int res=0;
       
        
        stack<int> st;
       
        
        int tmp_char=0;
        bool isfile=false;
        
        for(int i=0;i<input.size();i++){
            if(input[i]=='\n'){
                
                if(st.empty()){
                    st.push(tmp_char);
                }else{
                    st.push(tmp_char+st.top()+1);
                }
                if(isfile) res=max(res,st.top());
                tmp_char=0;
                isfile=false;
                
                
                int num_tab=cal_tab(input,i);
                while(st.size()>num_tab){
                    st.pop();
                }
              
            }else{
                if(input[i]=='.') isfile=true;
                tmp_char++;
            }
            
        }
        
        if(tmp_char!=0){
            if(st.empty()){
                st.push(tmp_char);
            }else{
                st.push(tmp_char+st.top()+1);
            }
            if(isfile) res=max(res,st.top());
        }
        
        return res;
        
    }
    
    
    int cal_tab(string& str,int &i){
        //cout the number of \t
        int res=0;
        while(i+1<str.size()&&str[i+1]=='\t'){
            i++;
            res++;
        }
        
        return res;
    }
};

int main(){
    string str1="dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
    string str2="dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    string str3= "a";
    string str4= "file1.txt\nfile2.txt\nlongfile.txt";
    Solution mysolu;
    int res=mysolu.lengthLongestPath(str1);
    return 0;
}

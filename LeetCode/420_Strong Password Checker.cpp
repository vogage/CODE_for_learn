//
//  420_Strong Password Checker.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/13.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string password) {
        if(password.size()==0)return 6;
        return Min_Step(password);
    }
    
private:
    struct flag{
        bool lowercase;
        bool uppercase;
        bool digit;
        bool all;
        flag(bool l,bool u,bool d,bool a):lowercase(l),uppercase(u),digit(d),all(a){};
    };
    
    struct PassWord_state{
        int step;
        int need_delete;
        int need_change;
        int need_add;
        PassWord_state(int s,int a,int nd,int nc):step(s),need_add(a),need_delete(nd),need_change(nc){};
        PassWord_state():step(0),need_add(0),need_delete(0),need_change(0){};
    };
    
    int Check_Case(const string& PassWord){
        flag Pw_Flag(false,false,false,false);
        for(auto c:PassWord){
            if(Pw_Flag.all)return 0;
            if(c>='0'&&c<='9') Pw_Flag.digit=true;
            if(c>='A'&&c<='Z') Pw_Flag.uppercase=true;
            if(c>='a'&&c<='z') Pw_Flag.lowercase=true;
            if(Pw_Flag.digit&&Pw_Flag.lowercase&&Pw_Flag.uppercase) Pw_Flag.all=true;
        }
        int res=0;
        if(!Pw_Flag.digit)res++;
        if(!Pw_Flag.uppercase)res++;
        if(!Pw_Flag.lowercase)res++;
        return res;
    }
    
    void dfs(const string& PassWord,PassWord_state& st,char pre_char,int repeat,int index,int& res){
        int temp_total=st.step+st.need_change+st.need_delete;
        if(res<temp_total)return;
        if(index==PassWord.size()){
            res=min(res,temp_total);
            return;
        }
        if(PassWord[index]==pre_char){
            repeat++;
            if(repeat==3){
                //1.delete this char
                PassWord_state delete_st;
                delete_st.step=st.step+1;
                delete_st.need_change=st.need_change;
                delete_st.need_delete=st.need_delete-1>0?st.need_delete-1:0;
                dfs(PassWord,delete_st,PassWord[index],repeat-1,index+1,res);
                
                //2.change this char
                PassWord_state change_st;
                change_st.step=st.step+1;
                change_st.need_change=st.need_change-1>0?st.need_change-1:0;
                change_st.need_delete=st.need_delete;
                dfs(PassWord,change_st,PassWord[index],0,index+1,res);
            }else{
                dfs(PassWord,st,PassWord[index],repeat,index+1,res);
            }
        }
        else{
            dfs(PassWord,st,PassWord[index],1,index+1,res);
        }
        return ;
        
        
        
    }
    
    void dfs2(const string& PassWord,PassWord_state& st,char pre_char,int repeat,int index,int& res){
        int temp_total=st.step+(st.need_change>st.need_add?st.need_change:st.need_add);
        if(res<temp_total)return;
        if(index==PassWord.size()){
            res=min(res,temp_total);
            return;
        }
        if(PassWord[index]==pre_char){
            repeat++;
            if(repeat==3){
                //1. add a char
                PassWord_state add_st;
                add_st.step=st.step+1;
                add_st.need_add=st.need_add-1>0?st.need_add-1:0;
                add_st.need_change=st.need_change-1>0?st.need_change-1:0;
                dfs2(PassWord,add_st,PassWord[index],0,index+1,res);
                
                //2. change a char
                PassWord_state change_st;
                change_st.step=st.step+1;
                change_st.need_add=st.need_add;
                change_st.need_change=st.need_change-1>0?st.need_change-1:0;
                dfs2(PassWord,change_st,PassWord[index],0,index+1,res);
                
            }else{
                dfs2(PassWord,st,PassWord[index],repeat,index+1,res);
            }
        }else{
            dfs2(PassWord,st,PassWord[index],1,index+1,res);
        }
    }
    int Min_Step(const string& PassWord){
        int Unsatisfied=Check_Case(PassWord);
        PassWord_state St(0,PassWord.size()<6?6-PassWord.size():0,PassWord.size()>20?PassWord.size()-20:0,Unsatisfied);
        int res=INT_MAX;
        if(PassWord.size()>6)dfs(PassWord,St,PassWord[0],1,1,res);
        else dfs2(PassWord,St,PassWord[0],1,1,res);
        return res;
        
    }
    
    
};

int main(){
    Solution mysolu;
    string password = "aA1";
    string password2="aaaB1";
    string password3="1111111111";
    string password4="aaabbb";
    string password5="ABABABABABABABABABAB1";
    string password6="aaa111";
    string password7="bbaaaaaaaaaaaaaaacccccc";
    string password8="aaaabbbbccccddeeddeeddeedd";
    string password9="a";
    int res=mysolu.strongPasswordChecker(password);
    return 0;
}

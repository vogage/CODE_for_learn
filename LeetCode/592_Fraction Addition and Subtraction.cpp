//
//  592_Fraction Addition and Subtraction.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/15.
//

#include <stdio.h>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Frac{
public:
    long long num;
    long long den;
    Frac operator +(Frac k){
        long long n=num*k.den+den*k.num;
        long long d=den*k.den;
        
        long long remindar=abs(gcd(n,d));
        Frac res(n/remindar,d/remindar);
        return  res;
    }
    Frac(long long n,long long d):num(n),den(d){};
private:
    long long gcd(long long n1,long long n2){
        // calculate the most common denimate
        if(n1%n2==0)return n2;
        else return gcd(n2,n1%n2);
    }
};

class Solution {
public:
    string fractionAddition(string expression) {
        queue<string> que=frac_split(expression);
        Frac res=Frac(0,1);
        while(!que.empty()){
            int n=stoi(que.front());
            que.pop();
            int d=1;
            if(!que.empty()){
                d=stoi(que.front());
                que.pop();
            }
            res=res+Frac(n,d);
        }
        
        string ans=""+to_string(res.num)+"/"+to_string(res.den);
        
        
        return ans;
    }
private:
    queue<string> frac_split(string &expression){
        queue<string> qst;
        int index=0;
        string temp="";
        while(index<expression.size()){
            if(expression[index]=='+'){
                qst.push(temp);
                temp="";
            }else if(expression[index]=='-'){
                qst.push(temp);
                temp="-";
            }
            else if(expression[index]=='/'){
                qst.push(temp);
                temp="";
            }
            else{
                temp+=expression[index];
            }
            index++;
        }
        qst.push(temp);
        if(qst.front().empty()) qst.pop();
        return qst;
    }
};

int main(){
    Solution mysolu;
    string ex="-1/2+1/2+1/3";
    string ex1="1/3-1/2";
    string res=mysolu.fractionAddition(ex);
    return 0;
}

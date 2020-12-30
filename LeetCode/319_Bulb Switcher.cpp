#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int temp = 0;
        int res = 0; 
        for (int i =1; i <= n; i++) {
            int temp3 = (1 <<i-1) ;
            int temp2 = temp3;
            for (int j = 2*i; j <= n; j=j+i) {
                temp2 = (temp2 << i) + temp3;
            }
            int temp4 = temp | temp2;
            int temp5= temp & temp2;
             
           // temp = temp | temp2 - temp & temp2;
            temp = temp4 - temp5;
        }
        while (temp) {
            if (temp % 2) res++;
            temp = temp >> 1;
        }
        return res;
    }
};

int main() {
    Solution mysolu;
    int res = mysolu.bulbSwitch(3);
    return 0;
}
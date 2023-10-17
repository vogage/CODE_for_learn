//
//  927_Three Equal Parts.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/28.
//

#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        //count the num of ones
        vector<int> res = { -1,-1 };
        int NumOneCnt = 0;
        for (int i : arr) if (i) NumOneCnt++;
        if (NumOneCnt % 3 != 0)return res;
        int Cnt = NumOneCnt / 3;
        if (NumOneCnt == 0)return vector<int>{1, 2};
        int end = arr.size() - 1;
        int TailZero = 0;
        while (end >= 0) {
            if (arr[end] == 0) { TailZero++; end--; }
            else break;
        }
        while (end >= 0 && Cnt) {
            if (arr[end--]) Cnt--;
        }
        int Right = end + 1;
        int Len = arr.size() - end - 1 - TailZero;
        int MidTailZero = 0;
        while (end >= 0) {
            if (arr[end] == 0) { MidTailZero++; end--; }
            else break;
        }

        if (MidTailZero < TailZero)return res;
        Right -= (MidTailZero - TailZero);
        for (int k = 0; k < Len; k++) {
            if (end == 0 || arr[end] != arr[arr.size() - 1 - TailZero - k]) return res;
            end--;
        }

        int FrontTailZero = 0;
        while (end >= 0) {
            if (arr[end] == 0) {
                FrontTailZero++;
                end--;
            }
            else break;
        }
        if (FrontTailZero < TailZero)return res;
        int Left = end + TailZero;
        for (int k = 0; k < Len; k++) {
            if (end < 0 || arr[end] != arr[arr.size() - 1 - TailZero - k])return res;
            end--;
        }
        res[0] = Left;
        res[1] = Right;
        return res;
    }
};

int main(){
    Solution mysolu;
    vector<int> arr = { 1, 0, 1, 0, 1 };
    vector<int> arr1 = { 0,0,0,0,0 };
    vector<int> res = mysolu.threeEqualParts(arr);
    return 0;
}

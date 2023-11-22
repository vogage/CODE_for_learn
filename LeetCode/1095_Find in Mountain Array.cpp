#include<vector>

using namespace std;

class MountainArray {
public:
   MountainArray(vector<int>& array) {
        arr = array;
    }
    int get(int index) {
        return arr[index];
    }
    int length() {
        return arr.size();
    }

private:
    vector<int> arr;
};

//You may recall that an array arr is a mountain array if and only if:
//
//arr.length >= 3
//There exists some i with 0 < i < arr.length - 1 such that :
//arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
//    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        //find the one bigger than the target
        int begin = 0;
        int end = mountainArr.length()-1;
        return topbina(begin, end,target, mountainArr);
    }
private:
    int topbina(int begin, int end,int target, MountainArray& mountainArr) {
        if (begin > end)return -1;
       
        int mid = (begin + end) / 2;

        int midvalue = mountainArr.get(mid);
        int beginvalue = mountainArr.get(begin);
        int endvalue = mountainArr.get(end);
        int res = -1;
        if (begin == end) return midvalue == target ? mid : -1;
        if (midvalue == target) {
            int res2 = topbina(begin, mid - 1, target, mountainArr);
            if (res2 == -1)return mid;
            else return res2;
        }
        else if (midvalue > target) {
            if (midvalue < endvalue) {
                res = regubina(begin, mid, target, mountainArr);
            }
            else if (midvalue < beginvalue) res = regubina(mid, end, target, mountainArr);
            else {
                    res=topbina(begin, mid,target, mountainArr);
                    if(res==-1) res= topbina(mid+1, end, target,mountainArr);
            }
        }
        else {
            if (midvalue < beginvalue) res = topbina(begin, mid, target, mountainArr);
            else  if (midvalue < endvalue) res = topbina(mid+1, end,  target, mountainArr);
            else {
                res = topbina(begin, mid, target, mountainArr);
                if (res == -1) res=topbina(mid+1, end,  target, mountainArr);
            }
        }
        return res;
    }

    int regubina(int begin, int end, int target, MountainArray& mountainArr) {
        int mid = -1;
        int midvalue = -1;
        if (begin == end) return mountainArr.get(begin) == target ? begin : -1;
        while (begin < end) {
            mid = (begin + end) / 2;
            midvalue = mountainArr.get(mid);
            if (midvalue >= target) {
                end = mid;
            }
            else {
                begin = mid + 1;
            }
        }
        return mountainArr.get(begin) == target ? begin : -1;
    }
};

int main() {
    Solution mysolu;
    vector<int> array = { 1, 2, 3, 4, 5, 3, 1 };
    int target = 3;
    vector<int> array1 = { 0,1,2,4,2,1 };
    int target1 = 3;
    vector<int> array2 = { 1,2,5,1 };
    int target2 = 5;
    vector<int> array3 = { 3,5,3,2,0 };
    int target3 = 3;
    vector<int> array4 = { 0,1,5,3,0 };
    int target4 = 0;
    vector<int> array5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,
        28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,
        59,60,61,62,63,64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,
        90,91,92,93,94,95,96,97,98,99,100,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82 };
    int target5 = 81;
    vector<int> array6 = { 1,6,11,16,21,26,31,36,41,46,51,56,61,66,71,76,81,86,91,96,101,106,111,116,121,
        126,131,136,141,146,151,156,161,166,171,176,181,186,191,196,201,206,211,216,221,226,231,236,
        241,246,251,256,261,266,271,276,281,286,291,296,301,306,311,316,321,326,331,336,341,346,351,
        356,361,366,371,376,381,386,391,396,401,406,411,416,421,426,431,436,441,446,451,456,461,466,471,
        476,481,486,491,496,501,496,491,486,481,476,471,466,461,456,451,446,441,436,431,426,421,416,411,406 };
    int target6 = 481;
    MountainArray moun(array6);
    int res = mysolu.findInMountainArray(target6, moun);
    return 0;
}
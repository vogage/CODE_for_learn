#include<stdio.h>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> sums(n + 1, 0);
        for (int i = 0; i < n; i++)
            sums[i + 1] = sums[i] + nums[i];
        return countWhileMergeSort(sums, 0, n + 1, lower, upper);

    }

private:
    int countWhileMergeSort(vector<long>& sums, int start, int end, int lower, int upper) {
        if (end - start <= 1)return 0;
        int mid = (start + end) / 2;
        int count = countWhileMergeSort(sums, start, mid, lower, upper) +
            countWhileMergeSort(sums, mid, end, lower, upper);
        int j = mid, k = mid, t = mid;
        vector<long> cache(end - start, 0);
        for (int i = start, r = 0; i < mid; ++i, ++r)  {
            while (k < end && sums[k] - sums[i] < lower)k++;
            while (j < end && sums[j] - sums[i] <= upper) j++; 
            while (t < end && sums[t] < sums[i]) cache[r++] = sums[t++];
               cache[r] = sums[i];
            count += j - k;
        }
        vector<long>::iterator b= cache.begin();
        vector<long>::iterator e = cache.begin() +( t - start);
        vector<long> cut_cache(b, e);
        copy(cut_cache.begin(),cut_cache.end(), sums.begin()+start);
        return count;
    }
};

int main() {
   // int a = -2147483648;
    //https://docs.microsoft.com/zh-cn/cpp/error-messages/compiler-warnings/compiler-warning-level-2-c4146?f1url=%3FappId%3DDev16IDEF1%26l%3DZH-CN%26k%3Dk(C4146);k(TargetFrameworkMoniker-.NETFramework,Version%253Dv4.0);k(TargetFrameworkMoniker-.NETFramework,Version%253Dv4.0)%26rd%3Dtrue&view=msvc-160
    vector<int> nums = {2147483647,INT_MIN,-1,0};
    //vector<int> nums = { 2147483647 };
    //nums.push_back(a);
    //nums.push_back(-1);
    //nums.push_back(0);
    int lower = -2, upper = 2;
    Solution mysolu;
    int res = mysolu.countRangeSum(nums,-1,0);
    return 0;
}
#include<vector>
#include<string>


using namespace std;

//You are given an integer array nums.The adjacent integers in nums will perform the float division.
//
//For example, for nums = [2, 3, 4], we will evaluate the expression "2/3/4".
//However, you can add any number of parenthesis at any position to change the priority of operations.
//You want to add these parentheses such the value of the expression after the evaluation is maximum.
//
//Return the corresponding expression that has the maximum value in string format.
//
//Note: your expression should not contain redundant parenthesis.

class Solution {
public:
    string optimalDivision(vector<int>& nums) {

    }
};

int main() {

//Input: nums = [1000, 100, 10, 2]
//Output : "1000/(100/10/2)"
//Explanation :
//    1000 / (100 / 10 / 2) = 1000 / ((100 / 10) / 2) = 200
//    However, the bold parenthesis in "1000/((100/10)/2)" are redundant, 
//    since they don't influence the operation priority. So you should return "1000/(100/10/2)".
}
//
//  378_Kth Smallest Element in a Sorted Matrix.cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/11.
//

#include <stdio.h>
#include<vector>
#include<queue>
#include<stack>

using namespace std;
//Given an n x n matrix where each of the rows and columns are sorted in ascending order, return the kth smallest element in the matrix.
//
//Note that it is the kth smallest element in the sorted order, not the kth distinct element.
//
//
//
//Example 1:
//
//Input: matrix = [[1 ,5 , 9],
//                 [10,11,13],
//                 [12,13,15]], k = 8
//Output: 13
//Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
//Example 2:
//
//Input: matrix = [[-5]], k = 1
//Output: -5
//
//
//Constraints:
//
//n == matrix.length
//n == matrix[i].length
//1 <= n <= 300
//-109 <= matrix[i][j] <= 109
//All the rows and columns of matrix are guaranteed to be sorted in non-decreasing order.
//1 <= k <= n2



class Solution2 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        vector<int> idx(n,0);
        int count=0;
        for(int i=0;i<matrix.size();i++){
            //if(idx[i]==0)
            count++;
            if(count==k)return matrix[i][idx[i]];
            for(int j=idx[i]+1;j<matrix[0].size();j++){
//                vector<vector<int>> matrix3={{1,4,7,11,15},
//                                            {2,5,8,12,19},
//                                            {3,6,9,16,22},
//                                            {10,13,14,17,24},
//                                            {18,21,23,26,30}};
                
                for(int h=i+1;h<matrix.size();h++){
                   
                   if(matrix[h][idx[h]]<matrix[i][j]){
                       
                        count++;
                  
                       if(count==k)return matrix[h][idx[h]];
                       idx[h]++;
                       for(int m=idx[h];m<matrix[0].size();m++){
                           if(matrix[h][m]<matrix[i][j]){
                               idx[h]++;
                               count++;
                               if(count==k)return matrix[h][m];
                           }
                       }
                   }
                    
                }
                idx[i]++;
                count++;
                if(count==k)return matrix[i][j];
              
            }
        }
        return 0;
    }
};

class Solution3 {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       int count=0;
       int n=matrix.size();
        vector<int> idx(n,0);
        int mm=0;
        while(k){
            int row=mm;
            int m=mm;
            for(;m<idx.size();m++){
                if(matrix[m][idx[m]]<matrix[row][idx[row]]){
                    row=m;
                   
                }
            }
            k--;
            if(k==0)return matrix[m][idx[m]];
            if(idx[row]==matrix[0].size()-1) {mm++;}else{idx[row]++;}

        }
            
        return 0;
      
    }
    
};

//Solution 2 : Binary Search
//We are done here, but let's think about this problem in another way:
//The key point for any binary search is to figure out the "Search Space". For me, I think there are two kind of "Search Space" -- index and range(the range from the smallest number to the biggest number). Most usually, when the array is sorted in one direction, we can use index as "search space", when the array is unsorted and we are going to find a specific number, we can use "range".
//
//Let me give you two examples of these two "search space"
//
//index -- A bunch of examples -- https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/ ( the array is sorted)
//range -- https://leetcode.com/problems/find-the-duplicate-number/ (Unsorted Array)
//The reason why we did not use index as "search space" for this problem is the matrix is sorted in two directions, we can not find a linear way to map the number and its index.

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int lo = matrix[0][0], hi = matrix[matrix.size() - 1][matrix[0].size() - 1] + 1;//[lo, hi)
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int count = 0,  j= matrix[0].size() - 1;
            
//vector<vector<int>> matrix3={{1,4,7,11,15},
//                            {2,5,8,12,19},
//                            {3,6,9,16,22},
//                            {10,13,14,17,24},
//                            {18,21,23,26,30}};
            for(int i = 0; i < matrix.size(); i++) {
                while(j >= 0 && matrix[i][j] > mid) j--;
                count += (j + 1);
            }
            if(count < k) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
};


//Solution 1 : Heap
//Here is the step of my solution:
//
//Build a minHeap of elements from the first row.
//Do the following operations k-1 times :
//Every time when you poll out the root(Top Element in Heap), you need to know the row number and column number of that element(so we can create a tuple class here), replace that root with the next element from the same column.
//After you finish this problem, thinks more :
//
//For this question, you can also build a min Heap from the first column, and do the similar operations as above.(Replace the root with the next element from the same row)
//What is more, this problem is exact the same with Leetcode373 Find K Pairs with Smallest Sums, I use the same code which beats 96.42%, after you solve this problem, you can check with this link:
//https://discuss.leetcode.com/topic/52953/share-my-solution-which-beat-96-42



//public class Solution {
//    public int kthSmallest(int[][] matrix, int k) {
//        int n = matrix.length;
//        PriorityQueue<Tuple> pq = new PriorityQueue<Tuple>();
//        for(int j = 0; j <= n-1; j++) pq.offer(new Tuple(0, j, matrix[0][j]));
//        for(int i = 0; i < k-1; i++) {
//            Tuple t = pq.poll();
//            if(t.x == n-1) continue;
//            pq.offer(new Tuple(t.x+1, t.y, matrix[t.x+1][t.y]));
//        }
//        return pq.poll().val;
//    }
//}
//
//class Tuple implements Comparable<Tuple> {
//    int x, y, val;
//    public Tuple (int x, int y, int val) {
//        this.x = x;
//        this.y = y;
//        this.val = val;
//    }
//
//    @Override
//    public int compareTo (Tuple that) {
//        return this.val - that.val;
//    }
//}


//1 #include <iostream>
//2 #include <queue>
//3 using namespace std;
//4
//5 //方法1
//6 struct tmp1 //运算符重载<
//7 {
//8     int x;
//9     tmp1(int a) {x = a;}
//10     bool operator<(const tmp1& a) const
//11     {
//12         return x < a.x; //大顶堆
//13     }
//14 };
//15
//16 //方法2
//17 struct tmp2 //重写仿函数
//18 {
//19     bool operator() (tmp1 a, tmp1 b)
//20     {
//21         return a.x < b.x; //大顶堆
//22     }
//23 };
//24
//25 int main()
//26 {
//27     tmp1 a(1);
//28     tmp1 b(2);
//29     tmp1 c(3);
//30     priority_queue<tmp1> d;
//31     d.push(b);
//32     d.push(c);
//33     d.push(a);
//34     while (!d.empty())
//35     {
//36         cout << d.top().x << '\n';
//37         d.pop();
//38     }
//39     cout << endl;
//40
//41     priority_queue<tmp1, vector<tmp1>, tmp2> f;
//42     f.push(b);
//43     f.push(c);
//44     f.push(a);
//45     while (!f.empty())
//46     {
//47         cout << f.top().x << '\n';
//48         f.pop();
//49     }
//50 }
//-----------------------------------------------------------------------------------

//// 优先队列：自定义数据类型的使用 - struct
//struct student
//{
//    int score;
//    string name;
//    int student_number;
//
//    // 重载 < 运算符，用于优先级比较, 以成绩来排名
//    bool operator<(const student& s) const
//    {
//        return this->score < s.score;    // 大顶堆
//    }
//
//    student(int s, string n, int sn) :score(s),name(n),student_number(sn){}
//};
//————————————————



struct matrix_key{

    int i;
    int j;
    int val;
    //重载
    bool operator<(const matrix_key& mk) const //只可以用小于号？？？？？？
    {
        return this->val> mk.val;//小顶堆
    }
    matrix_key(int i,int j,int val):i(i),j(j),val(val){}

};


class Solution4 {
public:


   
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<matrix_key> pq;
        int n=matrix.size();
        for(int j=0;j<matrix[0].size();j++) pq.push(matrix_key(0,j,matrix[0][j]));
        while(k>1){
            k--;
            matrix_key m=pq.top();
            pq.pop();
            if(m.i==n-1) continue;
            pq.push(matrix_key(m.i+1,m.j, matrix[m.i+1][m.j]));
           
        }
        return pq.top().val;
        
    }
    
};


//using namespace std;
//
//#include <iostream>
//#include <queue>
//#include <vector>

//class KthSmallestInSortedMatrix {
// public:
//  struct numCompare {
//    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
//      return x.first > y.first;
//    }
//  };
//
//  static int findKthSmallest(vector<vector<int>> &matrix, int k) {
//    int n = matrix.size();
//    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, numCompare> minHeap;
//
//    // put the 1st element of each row in the min heap
//    // we don't need to push more than 'k' elements in the heap
//    for (int i = 0; i < n && i < k; i++) {
//      minHeap.push(make_pair(matrix[i][0], make_pair(i, 0)));
//    }
//
//    // take the smallest element form the min heap, if the running count is equal to k return the number
//    // if the row of the top element has more elements, add the next element to the heap
//    int numberCount = 0, result = 0;
//    while (!minHeap.empty()) {
//      auto heapTop = minHeap.top();
//      minHeap.pop();
//      result = heapTop.first;
//      if (++numberCount == k) {
//        break;
//      }
//
//      heapTop.second.second++;
//      if (n > heapTop.second.second) {
//        heapTop.first = matrix[heapTop.second.first][heapTop.second.second];
//        minHeap.push(heapTop);
//      }
//    }
//    return result;
//  }
//};





int main(){
    vector<vector<int>> matrix={{1 ,5 , 9},
                                {10,11,13},
                                {12,13,15}};
    int k=8;
    vector<vector<int>> matrix1={{-5}};
    int k1=1;
    vector<vector<int>>matrix2={{1,2},{1,3}};
    int k2=2;
    
    vector<vector<int>> matrix3={{1,4,7,11,15},
                                {2,5,8,12,19},
                                {3,6,9,16,22},
                                {10,13,14,17,24},
                                {18,21,23,26,30}};
    int k3=20;
    
    
    vector<vector<int>> matrix4={{1,3,4},
                                {1,8,8},
                                {4,12,17}};
    int k4=5;

    Solution4 mysolu;
    int res=mysolu.kthSmallest(matrix3, k3);
    return 0;
}

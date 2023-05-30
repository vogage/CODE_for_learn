//
//  380_Insert Delete GetRandom O(1).cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/12.
//

#include <stdio.h>
//Implement the RandomizedSet class:
//
//RandomizedSet() Initializes the RandomizedSet object.
//bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
//bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
//int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). Each element must have the same probability of being returned.
//You must implement the functions of the class such that each function works in average O(1) time complexity.
//
//
//
//Example 1:
//
//Input
//["RandomizedSet", "insert", "remove", "insert", "getRandom", "remove", "insert", "getRandom"]
//[[], [1], [2], [2], [], [1], [2], []]
//Output
//[null, true, false, true, 2, true, false, 2]
//
//Explanation
//RandomizedSet randomizedSet = new RandomizedSet();
//randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
//randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
//randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
//randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
//randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
//randomizedSet.insert(2); // 2 was already in the set, so return false.
//randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
//
//
//Constraints:
//
//-231 <= val <= 231 - 1
//At most 2 * 105 calls will be made to insert, remove, and getRandom.
//There will be at least one element in the data structure when getRandom is called.
#include<unordered_set>
#include<unordered_map>
#include<vector>

using namespace std;

//class RandomizedSet {
//public:
//    /** Initialize your data structure here. */
//    RandomizedSet() {
//
//    }
//
//    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
//    bool insert(int val) {
//        if (m.find(val) != m.end()) return false;
//        nums.emplace_back(val);
//        m[val] = nums.size() - 1;
//        return true;
//    }
//
//    /** Removes a value from the set. Returns true if the set contained the specified element. */
//    bool remove(int val) {
//        if (m.find(val) == m.end()) return false;
//        int last = nums.back();
//        m[last] = m[val];
//        nums[m[val]] = last;
//        nums.pop_back();
//        m.erase(val);
//        return true;
//    }
//
//    /** Get a random element from the set. */
//    int getRandom() {
//        return nums[rand() % nums.size()];
//    }
//private:
//    vector<int> nums;
//    unordered_map<int, int> m;
//};



class RandomizedSet2 {
public:
    unordered_set<int> runset;
    /** Initialize your data structure here. */
    RandomizedSet2() {
       
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(runset.find(val)!=runset.end()){
            return false;
        }else{
            runset.insert(val);
            
        }
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        unordered_set<int>::iterator it=runset.find(val);
        if(it!=runset.end()){
            runset.erase(it);
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int total=runset.size();
        int idx=rand()%total;
        int output=0;
        
        for(auto ele: runset){
           
            
            if(idx==0)return ele;
            idx--;
            
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */



class RandomizedSet {
public:
    
    /** Initialize your data structure here. */
    RandomizedSet() {
       
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(runset.find(val)!=runset.end())return false;
        runset[val]=vec.size();
        vec.emplace_back(val);
        return true;
        
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(runset.find(val)==runset.end())return false;
        runset[vec.back()]=runset[val];
        vec[runset[val]]=vec.back();
        vec.pop_back();
        runset.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int idx=rand()%vec.size();
        return vec[idx];
    }
private:
    unordered_map<int,int> runset;
    vector<int> vec;
};









int main(){
    RandomizedSet randomizedSet;
    bool res1=randomizedSet.insert(1); // Inserts 1 to the set. Returns true as 1 was inserted successfully.
    bool res2=randomizedSet.remove(2); // Returns false as 2 does not exist in the set.
    bool res3=randomizedSet.insert(2); // Inserts 2 to the set, returns true. Set now contains [1,2].
    int res4=randomizedSet.getRandom(); // getRandom() should return either 1 or 2 randomly.
    bool res5=randomizedSet.remove(1); // Removes 1 from the set, returns true. Set now contains [2].
    bool res6=randomizedSet.insert(2); // 2 was already in the set, so return false.
    int res7=randomizedSet.getRandom(); // Since 2 is the only number in the set, getRandom() will always return 2.
    return 0;
}

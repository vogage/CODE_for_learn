//
//  381_Insert Delete GetRandom O(1) - Duplicates allowed.cpp
//  leetcode
//
//  Created by qiandehou on 2021/6/12.
//

#include <stdio.h>


//Implement the RandomizedCollection class:
//
//RandomizedCollection() Initializes the RandomizedCollection object.
//bool insert(int val) Inserts an item val into the multiset if not present. Returns true if the item was not present, false otherwise.
//bool remove(int val) Removes an item val from the multiset if present. Returns true if the item was present, false otherwise. Note that if val has multiple occurrences in the multiset, we only remove one of them.
//int getRandom() Returns a random element from the current multiset of elements (it's guaranteed that at least one element exists when this method is called). The probability of each element being returned is linearly related to the number of same values the multiset contains.
//
//
//Example 1:
//
//Input
//["RandomizedCollection", "insert", "insert", "insert", "getRandom", "remove", "getRandom"]
//[[], [1], [1], [2], [], [1], []]
//Output
//[null, true, false, true, 2, true, 1]
//
//Explanation
//RandomizedCollection randomizedCollection = new RandomizedCollection();
//randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
//randomizedCollection.insert(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
//randomizedCollection.insert(2);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
//randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
//randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
//randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
//
//
//Constraints:
//
//-231 <= val <= 231 - 1
//At most 105 calls will be made to insert, remove, and getRandom.
//There will be at least one element in the data structure when getRandom is called.
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection1 {
public:
    /** Initialize your data structure here. */
    RandomizedCollection1() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        if(sunmap.find(val)==sunmap.end()){
            vec.push_back(vector<int>(1,val));
            pair<int,vector<int>> temp;
            temp.first=vec.size()-1;
            temp.second.push_back(0);
            sunmap[val]=temp;
        }else{
            int idx=sunmap[val].first;
            vec[idx].push_back(val);
            sunmap[val].second.push_back(vec[idx].size()-1);
            return false;
        }
        return true;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(sunmap.find(val)==sunmap.end()){
            return false;
        }else{
            pair<int,vector<int>> temp=sunmap[val];
            int ridx=temp.second.back();
            if(temp.second.size()==1){
 
                sunmap[vec.back().back()].first=sunmap[val].first;
                
                vec[temp.first].clear();
                vec[temp.first]=vec.back();
                vec.pop_back();
                sunmap.erase(val);
            }else{
                vec[temp.first].pop_back();
                sunmap[val].second.pop_back();
            }
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand()%vec.size()].back();
    }

private:
    vector<vector<int>> vec;
    unordered_map<int,pair<int,vector<int>>> sunmap;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        vec.push_back(val);
       
        if(sunmap.find(val)==sunmap.end()){
            sunmap[val].insert(vec.size()-1);
            return true;
        }else{
            sunmap[val].insert(vec.size()-1);
        }
        return false;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(sunmap.find(val)==sunmap.end()){
            return false;
        }else{
            if(sunmap[val].size()>1){
            unordered_set<int>::iterator it=sunmap[val].begin();
            int remove_idx=*it;
            sunmap[val].erase(it);
            vec[remove_idx]=vec.back();
            int val2=vec.back();
            
            sunmap[val2].erase(vec.size()-1);
            
            sunmap[val2].insert(remove_idx);
           
            vec.pop_back();
            }else{
                unordered_set<int> ::iterator it=sunmap[val].begin();
                vec[*it]=vec.back();
                sunmap[vec.back()].insert(*it);
                sunmap.erase(val);
                if(sunmap.find(vec.back())!=sunmap.end())sunmap[vec.back()].erase(vec.size()-1);
                vec.pop_back();
            }
            
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vec[rand()%vec.size()];
    }

private:
    vector<int> vec;
    unordered_map<int,unordered_set<int>> sunmap;
};

//Like in the previous problem, Insert Delete GetRandom O(1), the solution is to maintain a vector with all elements to get the random number in O(1).
//With duplicates allowed, instead of just one index, we now need to store indexes of all elements of the same value in our vector. The remove method becomes a bit more complicated therefore, as we need to:
//
//Remove any index of the element being removed
//Swap the last element in the vector with the element being removed (same as in the previous problem)
//Remove old and add new index for the swapped (last) element
//---------------------------------------------------------------------------------
//  vector<int> v;
//  unordered_map<int, unordered_set<int>> m;
//  bool insert(int val) {
//    v.push_back(val);
//    m[val].insert(v.size() - 1);
//    return m[val].size() == 1;
//  }
//  bool remove(int val) {
//    auto it = m.find(val);
//    if (it != end(m)) {
//      auto free_pos = *it->second.begin();
//      it->second.erase(it->second.begin());
//      v[free_pos] = v.back();
//      m[v.back()].insert(free_pos);
//      m[v.back()].erase(v.size() - 1);
//      v.pop_back();
//      if (it->second.size() == 0) m.erase(it);
//      return true;
//    }
//    return false;
//  }
//  int getRandom() { return v[rand() % v.size()]; }


int main(){
    RandomizedCollection randomizedCollection;
//    ["RandomizedCollection","insert","remove","insert","getRandom","remove","insert","getRandom"]
//    [[],[1],[2],[2],[],[1],[2],[]]
    
//    ["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]
//    [[],[1],[1],[2],[],[1],[]]
    
    bool res1=randomizedCollection.insert(1);   // return True. Inserts 1 to the collection. Returns true as the collection did not contain 1.
    bool res2=randomizedCollection.remove(1);   // return False. Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
    bool res3=randomizedCollection.insert(1);   // return True. Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
    //bool res6=randomizedCollection.insert(2);

    int res4=randomizedCollection.getRandom(); // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
    bool res5=randomizedCollection.remove(1);   // return True. Removes 1 from the collection, returns true. Collection now contains [1,2].
    bool res8=randomizedCollection.insert(2);
    int res7=randomizedCollection.getRandom(); // getRandom should return 1 and 2 both equally likely.
    return 0;
}

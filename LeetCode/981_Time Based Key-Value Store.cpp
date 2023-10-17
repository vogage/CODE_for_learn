//
//  981_Time Based Key-Value Store.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/9/18.
//

#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <unordered_map>、

//981. Time Based Key-Value Store
using namespace std;

class TimeMap {
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        StampMap[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        auto m=StampMap[key].upper_bound(timestamp);
        if(m==StampMap[key].begin())return "";
        m--;
        return m->second;
    }
private:
   
private:
    unordered_map<string,map<int,string>> StampMap;
};



int main(){
    
    TimeMap *timeMap = new TimeMap();
    timeMap->set("foo", "bar", 1);  // store the key "foo" and value "bar" along with timestamp = 1.
    string res1=timeMap->get("foo", 1);         // return "bar"
    string res2=timeMap->get("foo", 3);         // return "bar", since there is no value corresponding to foo at timestamp 3
    //and timestamp 2, then the only value is at timestamp 1 is "bar".
    timeMap->set("foo", "bar2", 4); // store the key "foo" and value "bar2" along with timestamp = 4.
    string res3=timeMap->get("foo", 4);         // return "bar2"
    string res4=timeMap->get("foo", 5);         // return "bar2"
    
    //[[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
    return 0;
}


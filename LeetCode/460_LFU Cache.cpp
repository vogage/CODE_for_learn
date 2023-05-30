//
//  460_LFU Cache.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/5/25.
//

#include <stdio.h>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Node{
public:
    Node *pre;
    Node *next;
    int key;
    int val;
    int fre;
    Node():key(0),val(0),fre(0),pre(nullptr),next(nullptr){};
    Node(int k,int v,int f):key(k),val(v),fre(f){};
};

class DLinkList{
public:
    DLinkList(){
        sentinel=new Node();
        sentinel->pre=sentinel;
        sentinel->next=sentinel;
        size=0;
    }
    
    Node *sentinel;
    int size;
    void append(Node *nd){
        //put the node in the first place
        nd->next=sentinel->next;
        sentinel->next=nd;
        nd->next->pre=nd;
        nd->pre=sentinel;
        size++;
        
    }
    void pop(Node *nd){
        //remove the last one
        if(size==0) return;
        // pop the key value  node
        nd->pre->next=nd->next;
        nd->next->pre=nd->pre;
        nd->pre=nullptr;
        nd->next=nullptr;
        size--;
    }
    
    int getkey(){
        return sentinel->pre->key;
    }
};



class LFUCache {
public:
    LFUCache(int capacity) {
        size=0;
        Capacity=capacity;
        minfreq=0;
    }
    
    int get(int key) {
        if(key_dict.find(key)==key_dict.end())return -1;
        int f=key_dict[key].fre;
        key_dict[key].fre++;
        freq_dict[f].pop(&key_dict[key]);
        freq_dict[f+1].append(&key_dict[key]);
        if(freq_dict[f].size==0&&f==minfreq) minfreq++;
        return key_dict[key].val;
    }
    
    void put(int key, int value) {
        if(key_dict.find(key)==key_dict.end()){
            size++;
            
            if(size>Capacity){
                int key_Toearse=freq_dict[minfreq].getkey();
                freq_dict[minfreq].pop(&key_dict[key_Toearse]);
                size--;
                key_dict.erase(key_Toearse);
            }
            key_dict[key]=Node(key,value,1);
            
            minfreq=1;

            freq_dict[minfreq].append(&key_dict[key]);
           
           
        }else{
            key_dict[key].val=value;
            int f=key_dict[key].fre;
            key_dict[key].fre++;
            freq_dict[f].pop(&key_dict[key]);
            freq_dict[f+1].append(&key_dict[key]);
            if(freq_dict[f].size==0&&f==minfreq) minfreq++;
            
        }
    }
    unordered_map<int, Node> key_dict;
private:
    
    unordered_map<int, DLinkList> freq_dict;
    int minfreq;
    int size;
    int Capacity;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
//    Input
//    ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
//    [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
//    Output
//    [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
//    LFUCache *obj=new LFUCache(2);
//    obj->put(1,1);
//    obj->put(2, 2);
//    int para1=obj->get(1);
//    obj->put(3, 3);
//    int para2=obj->get(2);
//    int para3=obj->get(3);
//    obj->put(4,4);
//    int para4=obj->get(1);
//    int para5=obj->get(3);
//    int para6=obj->get(4);
//
////    ["LFUCache","put","put","put","put","get"]
////    [[2],[3,1],[2,1],[2,2],[4,4],[2]]
//    LFUCache *obj2=new LFUCache(2);
//    obj2->put(3,1);
//    obj2->put(2,1);
//    obj2->put(2,2);
//    obj2->put(4,4);
//    para2=obj2->get(2);
    
//    ["LFUCache","put","put","get","get","put","get","get","get"]
//    [[2],[2,1],[3,2],[3],[2],[4,3],[2],[3],[4]]
//    LFUCache *obj3=new LFUCache(2);
//    obj3->put(2,1);
//    obj3->put(3,2);
//    int obj3para1=obj3->get(3);
//    int obj3para2=obj3->get(2);
//    obj3->put(4,3);
//    int obj3para3=obj3->get(2);
//    int obj3para4=obj3->get(3);
//    int obj3para5=obj3->get(4);
    
//    ["LFUCache","put","put","get","put","put","get"]
//    [[2],[2,1],[2,2],[2],[1,1],[4,1],[2]]
    
//    LFUCache *obj4=new LFUCache(2);
//    obj4->put(2,1);
//    obj4->put(2,2);
//    int obj4para1=obj4->get(2);
//    obj4->put(1,1);
//    obj4->put(4,1);
//    int obj4para2=obj4->get(2);
    
//    ["LFUCache","put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"]
//    [[10],[10,13],[3,17],[6,11],[10,5],[9,10],[13],[2,19],[2],[3],[5,25],[8],[9,22],[5,5],[1,30],[11],[9,12],[7],[5],[8],[9],[4,30],[9,3],[9],[10],[10],[6,14],[3,1],[3],[10,11],[8],[2,14],[1],[5],[4],[11,4],[12,24],[5,18],[13],[7,23],[8],[12],[3,27],[2,12],[5],[2,9],[13,4],[8,18],[1,7],[6],[9,29],[8,21],[5],[6,30],[1,12],[10],[4,15],[7,22],[11,26],[8,17],[9,29],[5],[3,4],[11,30],[12],[4,29],[3],[9],[6],[3,4],[1],[10],[3,29],[10,28],[1,20],[11,13],[3],[3,12],[3,8],[10,9],[3,26],[8],[7],[5],[13,17],[2,27],[11,15],[12],[9,19],[2,15],[3,16],[1],[12,17],[9,1],[6,19],[4],[5],[5],[8,1],[11,7],[5,2],[9,28],[1],[2,2],[7,4],[4,22],[7,24],[9,26],[13,28],[11,26]]
    
    vector<vector<int>> input_nums={{10,13},{3,17},{6,11},{10,5},{9,10},{13},{2,19},{2},{3},{5,25},{8},{9,22},{5,5},{1,30},{11},{9,12},{7},{5},{8},{9},{4,30},{9,3},{9},{10},{10},{6,14},{3,1},{3},{10,11},{8},{2,14},{1},{5},{4},{11,4},{12,24},{5,18},{13},{7,23},{8},{12},{3,27},{2,12},{5},{2,9},{13,4},{8,18},{1,7},{6},{9,29},{8,21},{5},{6,30},{1,12},{10},{4,15},{7,22},{11,26},{8,17},{9,29},{5},{3,4},{11,30},{12},{4,29},{3},{9},{6},{3,4},{1},{10},{3,29},{10,28},{1,20},{11,13},{3},{3,12},{3,8},{10,9},{3,26},{8},{7},{5},{13,17},{2,27},{11,15},{12},{9,19},{2,15},{3,16},{1},{12,17},{9,1},{6,19},{4},{5},{5},{8,1},{11,7},{5,2},{9,28},{1},{2,2},{7,4},{4,22},{7,24},{9,26},{13,28},{11,26}};
    
    
        vector<string> input_instruction={"put","put","put","put","put","get","put","get","get","put","get","put","put","put","get","put","get","get","get","get","put","put","get","get","get","put","put","get","put","get","put","get","get","get","put","put","put","get","put","get","get","put","put","get","put","put","put","put","get","put","put","get","put","put","get","put","put","put","put","put","get","put","put","get","put","get","get","get","put","get","get","put","put","put","put","get","put","put","put","put","get","get","get","put","put","put","get","put","put","put","get","put","put","put","get","get","get","put","put","put","put","get","put","put","put","put","put","put","put"};
    
    LFUCache *obj5=new LFUCache(10);
    int n=input_nums.size();
    vector<int> outputs(n,-100);
    
    for(int i=0;i<input_nums.size();i++){
        if(i==64){
            int kkk=9;
        }
        if(i==94){
            int kkk=9;
        }
        if(i>62){
            for(auto k:obj5->key_dict){
                cout<<k.first<<","<<k.second.val<<","<<k.second.fre<<"      ";
            }
            cout<<endl;
        }
        if(input_instruction[i]=="put"){
            obj5->put(input_nums[i][0], input_nums[i][1]);
            outputs[i]=-999999;
        }
        if(input_instruction[i]=="get"){
            outputs[i]=obj5->get(input_nums[i][0]);
        }
    }
    
    return 0;
}

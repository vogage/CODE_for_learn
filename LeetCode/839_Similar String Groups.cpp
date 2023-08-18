//
//  839_Similar String Groups.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/8/2.
//

#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

struct Node{
    unordered_set<string> GroupstrSet;
    Node *next;
    Node():GroupstrSet(unordered_set<string>()),next(nullptr){}
};


class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        Node *root=new Node();
        for(int i=0;i<strs.size();i++){
            Node *temp=root;
            Node *head=nullptr;
            while(temp->next){
                bool isGroup=false;
                for(auto str:temp->next->GroupstrSet){
                    if(is_similar(strs[i], str)){
                        isGroup=true;
                        break;
                    }
                }
                if(isGroup){
                    if(!head) head=temp;
                    else{
                        mergeNode(head, temp);
                        
                    }
                }
                if(temp->next)temp=temp->next;
            }
            if(!head) {
                temp->next=new Node();
                temp->next->GroupstrSet.insert(strs[i]);
            }else{
                head->next->GroupstrSet.insert(strs[i]);
            }
        }
        int cnt=0;
        Node *temp=root;
        while(temp->next){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }
    
    
    
    
private:
    void mergeNode(Node* node1,Node* node2){
        for(auto str:node2->next->GroupstrSet){
            node1->next->GroupstrSet.insert(str);
        }
        node2->next=node2->next->next;
    }
    
    
    
    bool is_similar(string& str1,string& str2){
        pair<char,int> p1('a',-1);
        pair<char,int> p2('a',-1);
        for(int i=0;i<str1.size();i++){
            if(str1[i]!=str2[i]){
                if(p2.second!=-1) return false;
                else{
                    if(p1.second==-1){
                        p1.second=i;
                        p1.first=str2[i];
                    }else{
                        if(str1[i]==p1.first&&str2[i]==str1[p1.second]){
                            p2.second=i;
                            p2.second=str2[i];
                        }else{
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

int main(){
    Solution mysolu;
    vector<string> strs = {"tars","rats","arts","star"};
    vector<string> strs1= {"kccomwcgcs","socgcmcwkc","sgckwcmcoc","coswcmcgkc","cowkccmsgc","cosgmccwkc","sgmkwcccoc","coswmccgkc","kowcccmsgc","kgcomwcccs"};
    int res=mysolu.numSimilarGroups(strs1);
    return 0;
}

//
//  609_Find Duplicate File in System.cpp
//  leetcode
//
//  Created by 钱德厚 on 2023/6/16.
//

#include <stdio.h>
#include <string>

#include <vector>
#include <unordered_map>


using namespace std;


//Given a list paths of directory info, including the directory path, and all the files with contents in this directory,
//return all the duplicate files in the file system in terms of their paths. You may return the answer in any order.
//
//A group of duplicate files consists of at least two files that have the same content.
//
//A single directory info string in the input list has the following format:
//
//"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"
//It means there are n files (f1.txt, f2.txt ... fn.txt) with content (f1_content, f2_content ... fn_content)
//respectively in the directory "root/d1/d2/.../dm". Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.
//
//The output is a list of groups of duplicate file paths. For each group,
//it contains all the file paths of the files that have the same content. A file path is a string that has the following format:
//
//"directory_path/file_name.txt"

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
       
        
        for(int i=0;i<paths.size();i++){
           get_context_and_path(paths[i]);
        }
        vector<vector<string>> res;
        for(auto m:ContextToFilePathsMap) res.push_back(m.second);
        return res;
    }
private:
    void get_context_and_path(string file){
        string temp="";
        vector<string> Candidates;
        
        for(int i=0;i<file.size();i++){
            if(file[i]==' '){
                Candidates.push_back(temp);
                temp="";
            }else{
                temp+=file[i];
            }
        }
        
        if(temp.size()) Candidates.push_back(temp);
        string PathHead=Candidates[0];
        
        
        for(int i=1;i<Candidates.size();i++){
            string temp2="";
            vector<string> FileNameAndContext;
            for(int j=0;j<Candidates[i].size();j++){
                if(Candidates[i][j]=='('||Candidates[i][j]==')'){
                    FileNameAndContext.push_back(temp2);
                    temp2="";
                }else{
                    temp2+=Candidates[i][j];
                }
            }
            ContextToFilePathsMap[FileNameAndContext[1]].push_back(PathHead+"/"+FileNameAndContext[0]);
        }
        
        return;
    }
    
private:
    unordered_map<string, vector<string>> ContextToFilePathsMap;
};


int main(){
    Solution mysolu;
//Input: paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
//Output: [["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
    vector<string> paths={"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    vector<vector<string>> res=mysolu.findDuplicate(paths);
    
    return 0;
}

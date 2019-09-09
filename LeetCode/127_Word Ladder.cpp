#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//unordered_set<string> yes;
		queue<string> q;
		q.push(beginWord);

		int level = 1;
		while (!q.empty()) {
			int count = q.size();
		//	bool flag = false;
			for (int k = 0; k < count; k++) {
				string temp = q.front();
				q.pop();
				if (temp == endWord)return level;
		//		if (level > wordList.size())return 0;
				
				for (int i = 0; i < temp.size(); i++) {
					char be = temp[i];
					for (char j = 'a'; j <= 'z'; j++) {
						if (temp[i] == j)continue;
						else {

							temp[i] = j;
							vector<string>::iterator it = find(wordList.begin(), wordList.end(), temp);
							if (it != wordList.end()) {
								q.push(*it);
								wordList.erase(it);
					//			flag = true;
					//			yes.insert(*it);
							}
							else {
							//	if (yes.size() == wordList.size())return 0;

							}
						}
					}
					temp[i] = be;
				}
			}
		//	if (!flag)return 0;
			level++;
			cout << level<<endl;
			
		}
		return 0;
	}
	
};

class Solution2 {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		//unordered_set<string> yes;
		unordered_set<string> dict(wordList.begin(), wordList.end());
		queue<string> q;
		q.push(beginWord);

		int level = 1;
		while (!q.empty()) {
			int count = q.size();
			//	bool flag = false;
			for (int k = 0; k < count; k++) {
				string temp = q.front();
				q.pop();
				dict.erase(temp);
				if (temp == endWord)return level;
				//		if (level > wordList.size())return 0;

				for (int i = 0; i < temp.size(); i++) {
					char be = temp[i];
					for (char j = 'a'; j <= 'z'; j++) {
						if (temp[i] == j)continue;
						else {

							temp[i] = j;
							
							if (dict.find(temp)!=dict.end()) {
								q.push(temp);
								//wordList.erase(it);
								//			flag = true;
								//			yes.insert(*it);
							}
							else {
								//	if (yes.size() == wordList.size())return 0;

							}
						}
					}
					temp[i] = be;
				}
			}
			//	if (!flag)return 0;
			level++;
			cout << level << endl;

		}
		return 0;
	}

};

class Solution3 {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end()), head, tail,*phead, *ptail;
		if (dict.find(endWord) == dict.end())return 0;
		head.insert(beginWord);
		tail.insert(endWord);
		int level = 2;
		while (!head.empty() && !tail.empty()) {
			if (head.size() < tail.size()) {
				phead = &head;
				ptail = &tail;
			}
			else {
				phead = &tail;
				ptail = &head;
			}
			unordered_set<string> temp;
			for (auto it = phead->begin(); it != phead->end(); it++) {
				string word = *it;
				for (int i = 0; i < word.size(); i++) {
					char t = word[i];
					for (char j = 'a'; j <= 'z'; j++) {
						word[i] = j;
						if (ptail->find(word) != ptail->end()) return level;
						if (dict.find(word) != dict.end()) {
							temp.insert(word);
							dict.erase(word);
						}
					}
					word[i] = t;
				}
			}
			level++;
			phead->swap(temp);
		}
		return 0;
	}
};

int main() {
	vector<string> v = { "hot","dot","dog","lot","log","cog"};
	string begin = "hit";
	string end = "cog";
	Solution2 mysolu;
	int res = mysolu.ladderLength(begin, end, v);
	return res;
}
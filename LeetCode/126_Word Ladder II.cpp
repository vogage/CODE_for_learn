#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
//#include<hash_map>
#include<queue>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> res;
		vector<string> temp;
		vector<pair<string, bool>> wordlist2;
		temp.push_back(beginWord);
		BST(beginWord, endWord, wordList,temp, res);
		int m_res = INT_MAX;
		for (int i = 0; i < res.size(); i++) {
			m_res = min(m_res,(int) res[i].size());

		}
		vector<vector<string>> res2;
		for (int i = 0; i < res.size(); i++) {
			if (res[i].size() == m_res) res2.push_back(res[i]);
		}






		return res2;
	}
	void BST(string beginWord, string endWord, vector<string> &wordList,vector<string>& temp,
		vector<vector<string>> &res) {
		if (beginWord == endWord) {
			res.push_back(temp);
			return;
		}
		if (wordList.size() == 0)return;
		int x = onedif(beginWord, endWord, wordList);
		if (x == -1)return;
		else {
			string str = wordList[x];
			wordList.erase(wordList.begin() + x);
			
			BST(beginWord, endWord, wordList, temp, res);
			
			temp.push_back(str);

			BST(str, endWord, wordList, temp, res);

			temp.pop_back();

			wordList.push_back(str);
		}

	}









	int onedif(string beginWord, string endWord, vector<string> wordList) {

		//返回该单词所在list的idx
		int i = 0;
		int idx = -1;
		for (; i < wordList.size(); i++) {
			idx=cmp(beginWord, wordList[i]);
			if (idx != -1)break;
		}
		if (idx == -1)return -1;
		return i;
		/*
		//不同的那个char在endWord里面
		if (endWord.find(wordList[i][idx]) !=endWord.npos) {
			return i;
		}
		else return -1;
		*/
	}

	int cmp(string w1, string w2) {
		//只有一个相同，返回该idx
		int res = -1;
		int count = 0;
		for (int i = 0; i < w1.size(); i++) {
			if (w1[i] != w2[i]) {
				res = i;
				count++;
			}
		}
		if (count == 1)return res;
		else return -1;
	}
	

};


class Solution2 {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>> res;
		vector<string> solution;
		unordered_map<string, pair<int, vector<string>>> dict;
		for (int i = 0; i < wordList.size(); i++) {
			dict.insert(pair<string, pair<int, vector<string>>>(wordList[i], pair<int, vector<string>>(0, vector<string>())));
		}
		if (dict.find(endWord) == dict.end())return res;
		pair<int, vector<string>> temp;
		BFS(beginWord, endWord, wordList, temp, dict);
		solution.push_back(beginWord);
		DFS(beginWord, endWord,dict,solution,res);
		return res;
	}
	
	void DFS(string beginWord, string endWord, unordered_map<string, pair<int, vector<string>>>& dict,
		vector<string>& solution, vector<vector<string>>& res) {
		if (beginWord == endWord) {
			res.push_back(solution); return;
		}
		else {
			for (string next : dict[beginWord].second) {
				if (dict[next].first == dict[beginWord].first + 1) {
					solution.push_back(next);
					DFS(next, endWord, dict, solution, res);
					solution.pop_back();
				}
			}
		}
	}

	void BFS(string beginWord, string endWord, vector<string>& wordList, pair<int, vector<string>>& temp,
		unordered_map<string, pair<int, vector<string>>>& dict) {
		queue<string> q;
		q.push(beginWord);
		int level = 0;
		bool findend = false;
		while (!q.empty()) {
			
			int count = q.size();
			for (int i = 0; i < count; i++) {
				string cur = q.front();
				q.pop();
				if(dict[cur].first==0&&cur!=beginWord)dict[cur].first = level;
				vector<string> level_temp = getneibour(wordList, cur);
				for (int j = 0; j < level_temp.size(); j++) q.push(level_temp[j]);
				dict[cur].second = level_temp;

				if (cur == endWord) findend=true;
			}
			level++;
			if (findend)break;
		}
		

	}
	vector<string> getneibour(vector<string> &wordList, string cur) {
		vector<string> res;
		for (int i = 0; i < wordList.size(); i++) {
			if (cmp(cur, wordList[i]) != -1) res.push_back(wordList[i]);
		}
		return res;
	}
	int cmp(string w1, string w2) {
		//只有一个相同，返回该idx
		int res = -1;
		int count = 0;
		for (int i = 0; i < w1.size(); i++) {
			if (w1[i] != w2[i]) {
				res = i;
				count++;
			}
		}
		if (count == 1)return res;
		else return -1;
	}
};

class Solution3 {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		vector<vector<string>>res;
		queue<vector<string>> paths;
		unordered_set<string> visited;
		vector<string> path;
		int level = 1;
		int min_level = INT_MAX;
		paths.push({ beginWord });
		while (!paths.empty()) {
			path = paths.front();
			paths.pop();
			if (path.size() > level) {
				for (string w : visited) {
					vector<string>::iterator it = find(wordList.begin(), wordList.end(), w);
					wordList.erase(it);
				}
				visited.clear();
				if (path.size() > min_level) break;
				else level = path.size();

			}
			string last = path.back();
			for (int i = 0; i < last.size(); i++) {
				string news = last;
				for (char c = 'a'; c <= 'z'; c++) {
					news[i] = c;
					vector<string>::iterator it = find(wordList.begin(),wordList.end(),news);
					if (it != wordList.end()) {
						vector<string> new_path = path;
						new_path.push_back(news);
						visited.insert(news);
						if (news == endWord) {
							min_level = level;
							res.push_back(new_path);
						}
						else {
							paths.push(new_path);
						}
					}
					
				}
			}
		}
		return res;
	}
};

class Solution4 {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (beginWord == endWord)return { {beginWord} };
		int len = beginWord.size();
		unordered_set<string> dict;
		for (string& w : wordList) dict.insert(w);
		unordered_map<string, int> seen = { {beginWord,0} };
		vector<string> q = { beginWord };
		vector<int> prev = { -1 };
		int qid = 0;
		vector<vector<string>> ans;
		while (qid < q.size()) {
			for (int l = 0; l < len; l++) {
				for (int i = 0; i < 26; i++) {
					string w = q[qid];
					if (w[l] == 'a' + i)continue;
					w[l] = 'a' + i;
					if (dict.find(w) != dict.end() && (seen.find(w) == seen.end() || seen[w] == seen[q[qid]] + 1)) {
						if (w == endWord) {
							vector<string> res = { w,q[qid] };
							int pr = prev[qid];
							while (pr != -1) {
								res.push_back(q[pr]);
								pr = prev[pr];
							}
							if (ans.size() == 0 || ans[0].size() == res.size()) {
								reverse(res.begin(), res.end());
								ans.push_back(res);
							}
							else return ans;
						}
						else {
							seen[w] = seen[q[qid]] + 1;
							prev.push_back(qid);
							q.push_back(w);
						}
					}
				}
			}
			qid++;
		}
		return ans;
	}
};
int main() {
	vector<string> list = { "kid","tag","pup","ail","tun","woo","erg","luz","brr","gay","sip","kay","per","val","mes","ohs","now","boa","cet","pal","bar","die","war","hay","eco","pub","lob","rue","fry","lit","rex","jan","cot","bid","ali","pay","col","gum","ger","row","won","dan","rum","fad","tut","sag","yip","sui","ark","has","zip","fez","own","ump","dis","ads","max","jaw","out","btu","ana","gap","cry","led","abe","box","ore","pig","fie","toy","fat","cal","lie","noh","sew","ono","tam","flu","mgm","ply","awe","pry","tit","tie","yet","too","tax","jim","san","pan","map","ski","ova","wed","non","wac","nut","why","bye","lye","oct","old","fin","feb","chi","sap","owl","log","tod","dot","bow","fob","for","joe","ivy","fan","age","fax","hip","jib","mel","hus","sob","ifs","tab","ara","dab","jag","jar","arm","lot","tom","sax","tex","yum","pei","wen","wry","ire","irk","far","mew","wit","doe","gas","rte","ian","pot","ask","wag","hag","amy","nag","ron","soy","gin","don","tug","fay","vic","boo","nam","ave","buy","sop","but","orb","fen","paw","his","sub","bob","yea","oft","inn","rod","yam","pew","web","hod","hun","gyp","wei","wis","rob","gad","pie","mon","dog","bib","rub","ere","dig","era","cat","fox","bee","mod","day","apr","vie","nev","jam","pam","new","aye","ani","and","ibm","yap","can","pyx","tar","kin","fog","hum","pip","cup","dye","lyx","jog","nun","par","wan","fey","bus","oak","bad","ats","set","qom","vat","eat","pus","rev","axe","ion","six","ila","lao","mom","mas","pro","few","opt","poe","art","ash","oar","cap","lop","may","shy","rid","bat","sum","rim","fee","bmw","sky","maj","hue","thy","ava","rap","den","fla","auk","cox","ibo","hey","saw","vim","sec","ltd","you","its","tat","dew","eva","tog","ram","let","see","zit","maw","nix","ate","gig","rep","owe","ind","hog","eve","sam","zoo","any","dow","cod","bed","vet","ham","sis","hex","via","fir","nod","mao","aug","mum","hoe","bah","hal","keg","hew","zed","tow","gog","ass","dem","who","bet","gos","son","ear","spy","kit","boy","due","sen","oaf","mix","hep","fur","ada","bin","nil","mia","ewe","hit","fix","sad","rib","eye","hop","haw","wax","mid","tad","ken","wad","rye","pap","bog","gut","ito","woe","our","ado","sin","mad","ray","hon","roy","dip","hen","iva","lug","asp","hui","yak","bay","poi","yep","bun","try","lad","elm","nat","wyo","gym","dug","toe","dee","wig","sly","rip","geo","cog","pas","zen","odd","nan","lay","pod","fit","hem","joy","bum","rio","yon","dec","leg","put","sue","dim","pet","yaw","nub","bit","bur","sid","sun","oil","red","doc","moe","caw","eel","dix","cub","end","gem","off","yew","hug","pop","tub","sgt","lid","pun","ton","sol","din","yup","jab","pea","bug","gag","mil","jig","hub","low","did","tin","get","gte","sox","lei","mig","fig","lon","use","ban","flo","nov","jut","bag","mir","sty","lap","two","ins","con","ant","net","tux","ode","stu","mug","cad","nap","gun","fop","tot","sow","sal","sic","ted","wot","del","imp","cob","way","ann","tan","mci","job","wet","ism","err","him","all","pad","hah","hie","aim","ike","jed","ego","mac","baa","min","com","ill","was","cab","ago","ina","big","ilk","gal","tap","duh","ola","ran","lab","top","gob","hot","ora","tia","kip","han","met","hut","she","sac","fed","goo","tee","ell","not","act","gil","rut","ala","ape","rig","cid","god","duo","lin","aid","gel","awl","lag","elf","liz","ref","aha","fib","oho","tho","her","nor","ace","adz","fun","ned","coo","win","tao","coy","van","man","pit","guy","foe","hid","mai","sup","jay","hob","mow","jot","are","pol","arc","lax","aft","alb","len","air","pug","pox","vow","got","meg","zoe","amp","ale","bud","gee","pin","dun","pat","ten","mob" };
	string beginWord = "cet";
	string endWord = "ism";
	Solution3 mysolu;
	vector<vector<string>> res = mysolu.findLadders(beginWord, endWord, list);
	return 0;
}
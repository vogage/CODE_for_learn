#include<stdio.h>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Trie {
public:
	vector<string> tr;
	/** Initialize your data structure here. */
	Trie() {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		tr.push_back(word);
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return find(tr.begin(), tr.end(), word) != tr.end();
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		//int len = prefix.size();
		if (tr.size() == 0)return false;
		int len = prefix.size();
		bool ans = false;
		for (auto str : tr) {
			ans = ans || str.substr(0, len) == prefix;

		}
		return ans;
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
	Trie *obj = new Trie();
	obj->insert("ab");
	bool res1 = obj->search("abc");
	bool res2 = obj->search("ab");
	bool res3 = obj->startsWith("abc");
	bool res4 = obj->startsWith("ab");
	obj->insert("ab");
	bool res6 = obj->search("abc");
	//["Trie","insert","search","search","startsWith","startsWith","insert","search",

	//"startsWith","insert","search","startsWith"]

	
	//[[], ["ab"], ["abc"], ["ab"], ["abc"], ["ab"], ["ab"], ["abc"], ["abc"], ["abc"], ["abc"], ["abc"]]
	bool res7 = obj->startsWith("abc");
	obj->insert("abc");
	bool res9 = obj->search("abc");
	bool res10 = obj->startsWith("abc");

	return 0;

}

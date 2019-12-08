#include<stdio.h>
#include<string>
#include<vector>
#include<unordered_map>
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

class TrieNode {
public:
	TrieNode* children[26];
	bool is_word;

	//initial your data structure here
	TrieNode(bool b = false) {
		memset(children, 0, sizeof(children));
		is_word = false;
	}
};


class Trie2 {
public:
	TrieNode *root;
	/** Initialize your data structure here. */
	Trie2() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode *p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->children[word[i] - 'a'] == NULL) {
				p->children[word[i] - 'a'] = new TrieNode();
			}
				p = p->children[word[i] - 'a'];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode* p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->children[word[i] - 'a'] == NULL)return false;
			p = p->children[word[i] - 'a'];

		}
		return p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode *p = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (p->children[prefix[i] - 'a'] == NULL)return false;
			p = p->children[prefix[i] - 'a'];
		}
		return true;
	}
};



class TrieNode1 {
public:
	//TrieNode1* children[26];
	unordered_map<char,TrieNode1*>children;
	bool is_word;

	//initial your data structure here
	TrieNode1(bool b = false) {
		//memset(children, 0, sizeof(children));
		is_word = false;
	}
};


class Trie3 {
public:
	TrieNode1 *root;
	/** Initialize your data structure here. */
	Trie3() {
		root = new TrieNode1();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode1 *p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->children[word[i]] == NULL) {
				p->children[word[i]] = new TrieNode1();

			}
			p = p->children[word[i]];
		}
		p->is_word = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		TrieNode1* p = root;
		for (int i = 0; i < word.size(); i++) {
			if (p->children[word[i]] == NULL)return false;
			p = p->children[word[i]];

		}
		return p->is_word;
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		TrieNode1 *p = root;
		for (int i = 0; i < prefix.size(); i++) {
			if (p->children[prefix[i]] == NULL)return false;
			p = p->children[prefix[i]];
		}
		return true;
	}
};


int main() {
	Trie3 *obj = new Trie3();
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

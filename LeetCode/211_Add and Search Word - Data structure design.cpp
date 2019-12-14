#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class TreeNode {
public:
	unordered_map<char, TreeNode*> children;
	bool isWord;
	TreeNode(bool isword = false) {
		isWord = false;
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	TreeNode* root;
	WordDictionary() {
		root = new TreeNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TreeNode *p = root;
		
		for (int i = 0; i < word.size(); i++) {
			if (p->children[word[i]] == NULL) {
				p->children[word[i]] = new TreeNode();
			}
			p = p->children[word[i]];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return DFS(word, 0, root);
	}

	bool DFS(string word, int i, TreeNode* root) {
		if (i == word.size())return true;
		if (word[i] == '.') {
			for (auto p : root->children) {
				if (DFS(word, i + 1, p.second))return true;
			}
		}
		else {
			if(root->children[word[i]] == NULL)return false;
			else {
				TreeNode *p = root->children[word[i]];
				if (!DFS(word, i + 1, p))return false;
			}
		}
		return true;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class TrieNode1 {
public:
	//TrieNode1* children[26];
	unordered_map<char, TrieNode1*>children;
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
	//WordDictionary *obj = new WordDictionary();
	//obj->addWord("bad");
	//obj->addWord("dad");
	//obj->addWord("mad");
	//bool res1=obj->search("pad");
	//bool res2 = obj->search("bad");
	//bool res3 = obj->search(".ad");
	//bool res4 = obj->search("b..");
	WordDictionary w;
	w.addWord("bad");
	w.addWord("dad");
	w.addWord("mad");
	return 0;
}
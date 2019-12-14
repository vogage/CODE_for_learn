#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class TrNode {
public:
	unordered_map<char, TrNode*> children;
	bool isWord;
	TrNode(bool isword = false) {
		isWord = false;
	}
};

class WordDictionary {
public:
	/** Initialize your data structure here. */
	TrNode* root;
	WordDictionary() {
		root = new TrNode();
	}

	/** Adds a word into the data structure. */
	void addWord(string word) {
		TrNode *p = root;
	
		for (int i = 0; i < word.size(); i++) {
			if (p->children[word[i]] == NULL) {
				p->children[word[i]] = new TrNode();
			}
			p = p->children[word[i]];
		}
		p->isWord = true;
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		return DFS(word, 0, root);
		
	}

	bool DFS(string word, int i,TrNode *root) {
		if (root == NULL)return false;
		if (word.size() - 1 == i) {
			if (word[i] == '.') {
				return root->isWord;
			}
			else {
				return root->children[word[i]]->isWord;
			}
		}
		if (word[i] == '.') {
			for (auto p : root->children) {
				if (DFS(word, i + 1, p.second))return true;
			}
			return false;
		}
		else {
			TrNode *p = root->children[word[i]];
			return DFS(word, i + 1, p);
		}
		
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
	WordDictionary *obj = new WordDictionary();
	//obj->addWord("bad");
	//obj->addWord("dad");
	//obj->addWord("mad");
	//bool res1=obj->search("pad");
	//bool res2 = obj->search("bad");
	//bool res3 = obj->search(".ad");
	//bool res4 = obj->search("b..");

	//["WordDictionary", "addWord", "addWord", "search", "search", "search", "search", "search", "search"]
	//[[], ["a"], ["a"], ["."], ["a"], ["aa"], ["a"], [".a"], ["a."]]
	//obj->addWord("a");
	//obj->addWord("a");
	//bool res1=obj->search(".");
	//bool res2=obj->search("a");
	//bool res3=obj->search("aa");
	//bool res4=obj->search("a");
	//bool res5=obj->search(".a");
	//bool res6=obj->search("a.");

	//["WordDictionary","addWord","addWord","addWord","addWord",
	//"search","search","addWord","search",
	//"search","search","search","search","search"]
	//[[], ["at"], ["and"], ["an"], ["add"],
	//["a"], [".at"], ["bat"], [".at"], ["an."], 
	//["a.d."], ["b."], ["a.d"], ["."]]
	 obj->addWord("at");
	 obj->addWord("and");
	 obj->addWord("an");
	 obj->addWord("add");
	 bool res0=obj->search("a");
	 bool res1 = obj->search(".at");
	 obj->addWord("bat");
	 bool res2 = obj->search(".at");
	 bool res3 = obj->search("b.");
	 bool res4 = obj->search("a.d");
	 bool res5 = obj->search(".");

	return 0;
}
#include<stdio.h>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>

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
		//stack<TrNode*> st;
		
		return DFS(word, 0,root);
	}

	bool DFS(string word, int index,TrNode *root) {
		//if (root->children[word[index]] == NULL)return false;
		if (root == NULL)return false;
		bool flag = false;
		for (auto p : root->children) {
			flag = true;
		}
		if (flag == false)return false;
		if (index == word.size() - 1) {
			//return root->children[word[index]]->isWord;
			if (word[index] == '.') {
				//if (word.size() == 1) {
					for (auto p : root->children) {
						if (p.second == NULL)return false;
						else return p.second->isWord;
					}
					return false;
				//}				
			}
			else {
				if(root->children[word[index]]==NULL) return false;
				else return root->children[word[index]]->isWord;
			}
		}
		if (word[index] == '.') {
			for (auto p : root->children) {
				if (DFS(word, index + 1, p.second)) return true;
			}
			//return false;
		}
		else {
			if (root->children[word[index]] == NULL)return false;
			else {
				return DFS(word, index + 1, root->children[word[index]]);
			}
		}
		return false;
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
	 //obj->addWord("at");
	 //obj->addWord("and");
	 //obj->addWord("an");
	 //obj->addWord("add");
	 //bool res0=obj->search("a");
	 //bool res1 = obj->search(".at");
	 //obj->addWord("bat");
	 //bool res2 = obj->search(".at");
	 //bool res3 = obj->search("an.");
	 //bool res4 = obj->search("a.d.");
	 //bool res5 = obj->search("b.");
	 //bool res6 = obj->search("a.d");
	 //bool res7 = obj->search(".");

	/* bool res1 = obj->search("a");*/

	//["WordDictionary", "addWord", "addWord", "search", "search", 
	//"search", "search", "search", "search", "search", "search"]
	//[[], ["a"], ["ab"], ["a"], ["a."], ["ab"], 
	//[".a"], [".b"], ["ab."], ["."], [".."]]

	obj->addWord("a");
	obj->addWord("ab");
	bool res1 = obj->search("a");
	bool res2 = obj->search("a.");
	bool res3 = obj->search("ab");
	bool res4 = obj->search(".a");
	bool res5 = obj->search(".b");
	bool res6 = obj->search("ab.");
	bool res7 = obj->search(".");
	bool res8 = obj->search("..");

	return 0;
}
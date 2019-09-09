#include<stdio.h>
#include<string>
#include<iostream>
#include<map>

using namespace std;

class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1 == s2)return true;
		int n1 = s1.size(); int n2 = s2.size();
		if (n1 != n2)return false;
		map<char, int> m1;
		map<char, int> m2;
		for (int i = 0; i < n1; i++) {
			m1[s1[i]]++;
			m2[s2[i]]++;
		}
		for (auto m:m1){
			if (m.second != m2[m.first])return false;
		}
		return scram(s1, s2);
		
	}
	
	bool scram(string s1, string s2) {
	
		if (s1 == s2)return true;
		/*
		map<char, int> m1;
		map<char, int> m2;
		for (int i = 0; i < s1.size(); i++) {
			m1[s1[i]]++;
			m2[s2[i]]++;
		}
		for (auto m : m1) {
			if (m.second != m2[m.first])return false;
		}
		*/



		cout << " s1= " << s1 << " s2= " << s2 << endl;

		int len = s1.size();
		//swap left 
		for (int i = 1; i < len; i++) {
			if(scram(s1.substr(0,i),s2.substr(0,i))&&scram(s1.substr(i),s2.substr(i)))
				return true;
			if (scram(s1.substr(0, i), s2.substr(len - i)) && scram(s1.substr(i) ,s2.substr(0,len-i)))
				return true;
		}


			//devide s2
			return false;

	



	}


};

int main() {
	Solution mysolu;
	string str1 = "abcdefghijklmnopq";

	string str2 = "efghijklmnopqcadb";

		
	bool ans = mysolu.isScramble(str1, str2);
	return 0;
}
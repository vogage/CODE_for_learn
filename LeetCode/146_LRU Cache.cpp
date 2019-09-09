#include<stdio.h>
#include<vector>
#include<list>
#include<unordered_map>
using namespace std;



/*

class LRUCache {
public:
	vector<pair<int, int>> v;
	int size = 0;
	vector<pair<int, int>> ::iterator it = v.begin();

	LRUCache(int capacity) {
		size = capacity;
	}

	int get(int key) {
		it = v.begin();
		while (it != v.end()) {
			if (it->first == key) return it->second;
			it++;
		}
		return -1;

	}

	void put(int key, int value) {
		pair<int, int> temp;
		temp.first = key;
		temp.second = value;


		if (size == v.size()) {
			//for (auto v_temp : v) {
			//	if (v_temp.first == recent) {//这里只是进行了复制，没有在原位置进行修改
			//		v_temp.first = key;
			//		v_temp.second = value;
			//	}
			//}
			it->first = key;
			it->second = value;

		}
		else v.push_back(temp);
	}
};
*/

class LRUCache {





public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto it = cache.find(key);
		if (it == cache.end()) return -1;
		touch(it);
		return it->second.first;
	}

	void put(int key, int value) {
		auto it = cache.find(key);
		if (it != cache.end()) {
			touch(it);
		}
		else {
			if (cache.size() == _capacity) {
				cache.erase(used.back());
				used.pop_back();
			}
			used.push_front(key);
		}
		cache[key] = { value,used.begin() };
	}
private:
	typedef list<int> LI;
	typedef pair<int, LI::iterator>PLI;
	typedef unordered_map<int, PLI> HPLI;

	void touch(HPLI::iterator it) {
		int key = it->first;
		used.erase(it->second.second);
		used.push_front(key);
		it->second.second = used.begin();
	}

	HPLI cache;
	LI used;
	int _capacity;

};

int main() {
	LRUCache *cache = new LRUCache(2 /* capacity */);

	cache->put(1, 1);
	cache->put(2, 2);
	cache->get(1);       // returns 1
	cache->put(3, 3);    // evicts key 2
	cache->get(2);       // returns -1 (not found)
	cache->put(4, 4);    // evicts key 1
	cache->get(1);       // returns -1 (not found)
	cache->get(3);       // returns 3
	cache->get(4);       // returns 4
	return 0;
}


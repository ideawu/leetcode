#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 使用 std::list 来保存 {key, value}
* 使用 std::map 来保存 key=>list::iterator
***********************************************************/
class LRUCache {
public:
    LRUCache(int capacity) {
        this->_capacity = capacity;
    }
    
    int get(int key) {
        auto it = _map.find(key);
		if(it == _map.end()){
			return -1;
		}
		auto lit = it->second;
		Item &item = *lit;
		_list.erase(lit);
		_list.push_front(item);
		_map[key] = _list.begin();
		return item.val;
    }
    
    void put(int key, int value) {
        auto it = _map.find(key);
		if(it != _map.end()){
			auto lit = it->second;
			Item &item = *lit;
			item.val = value;
			return;
		}

		Item item;
		item.key = key;
		item.val = value;
		_list.push_front(item);
		_map[key] = _list.begin();

		if(_list.size() > _capacity){
			Item &item = _list.back();
			_list.pop_back();
			_map.erase(item.key);
		}
    }
private:
	struct Item{
		int key;
		int val;
	};
	int _capacity;
	list<Item> _list;
	map<int, list<Item>::iterator> _map;
};

int main(int argc, char **argv){
	LRUCache cache(2);
	cache.put(1, 1);
	cache.put(2, 2);
	printf("%d\n", cache.get(1));       // returns 1
	cache.put(3, 3);    // evicts key 2
	printf("%d\n", cache.get(2));       // returns -1 (not found)
	cache.put(4, 4);    // evicts key 1
	printf("%d\n", cache.get(1));       // returns -1 (not found)
	printf("%d\n", cache.get(3));       // returns 3
	printf("%d\n", cache.get(4));       // returns 4

	return 0;
}

/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

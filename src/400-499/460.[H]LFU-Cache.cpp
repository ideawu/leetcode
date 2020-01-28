#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 考察对 list, map 的使用.
* list 的迭代器不支持 +1 操作(随机访问).
* 迭代器就是元素的代理指针, 可以当作元素的指针来使用.
* 当用引用指向迭代器的元素时, 注意迭代器可能失效. 可以换成使用拷贝.
* n = std::next(list_it, 1);
* std::advance(list_it, 1);
***********************************************************/
struct Item{
	int key;
	int val;
	int f;
	Item(int k, int v) : key(k), val(k), f(0){}
};

class LFUCache {
public:
    LFUCache(int capacity) {
        _cap = capacity;
    }
	
	void visit(list<Item>::iterator lit){
		lit->f ++;
		
		list<Item>::iterator next = std::next(lit, 1);
		list<Item>::iterator nlit = next;
		while(nlit != _list.end()){
			if(lit->f >= nlit->f){
				nlit ++;
			}else{
				break;
			}
		}
		if(nlit != next){
			Item item = *lit;
			_list.erase(lit);
			lit = _list.insert(nlit, item);
			_map[item.key] = lit;
		}		
	}
    
    int get(int key) {
        auto it = _map.find(key);
		if(it == _map.end()){
			printf("get %d = %d\n", key, -1);
			return -1;
		}
		list<Item>::iterator lit = it->second;
		// 注意用拷贝而不是引用, visit 之后迭代器可能失效, item 也被释放
		Item item = *lit;
		visit(lit);
		printf("get %d = %d\n", item.key, item.val);
		return item.val;
    }
    
    void put(int key, int value) {
		printf("put %d = %d\n", key, value);
		list<Item>::iterator lit;
        auto it = _map.find(key);
		if(it != _map.end()){
			lit = it->second;
			lit->val = value;
		}else{
			if(_list.size() == _cap){
				// 如果这里使用引用, list 和 map 都删除元素后, 指向的内存已被释放
				// 所以这里使用拷贝
				Item i = _list.front();
				_list.pop_front();
				_map.erase(i.key);
				printf("evict %d\n", i.key);
			}
			Item item(key, value);
			_list.push_front(item);
			lit = _list.begin();
			_map[item.key] = lit;
		}
		visit(lit);
    }
private:
	int _cap;
	list<Item> _list;
	unordered_map<int, list<Item>::iterator> _map;
};

int main(int argc, char **argv){
	LFUCache cache(2);

	cache.put(1, 1);
	cache.put(2, 2);
	cache.get(1);       // returns 1
	cache.put(3, 3);    // evicts key 2
	cache.get(2);       // returns -1 (not found)
	cache.get(3);       // returns 3.
	cache.put(4, 4);    // evicts key 1.
	cache.get(1);       // returns -1 (not found)
	cache.get(3);       // returns 3
	cache.get(4);       // returns 4
	return 0;
}

/*
Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.

Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.

 

Follow up:
Could you do both operations in O(1) time complexity?

 

Example:

LFUCache cache = new LFUCache( 2 capacity );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.get(3);       // returns 3.
cache.put(4, 4);    // evicts key 1.
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/
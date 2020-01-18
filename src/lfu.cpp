#include <stdio.h>
#include <string>
#include <list>
#include <map>

class Item
{
public:
	std::string key;
	int val;
	int score;
	Item() : val(0), score(0){}
};

class LFU
{
public:
	bool get(const std::string &key, int *val);
	void set(const std::string &key, int val);
private:
	std::map<std::string, std::list<Item>::iterator> _data;
	std::list<Item> _list;
	int _max_size;
};

bool LFU::get(const std::string &key, int *val){
   	auto iter = _data.find(key);
	if(iter == _data.end()){
		return false;
	}

	auto curr = iter->second;
	(*curr).score += 1;
	*val = (*curr).val;

	// 后移
	auto next = _list.erase(curr);
	while(next != _list.end()){
		if((*curr).score <= (*next).score){
			break;
		}
		next ++;
	}
	curr = _list.insert(next, *curr);
	_data[key] = curr;

	return true;
}

void LFU::set(const std::string &key, int val){
   	auto iter = _data.find(key);
	if(iter == _data.end()){
		Item &item = *iter->second;
		item.val = val;
	}else{
		// 淘汰
		if(_data.size() > _max_size){
			_data.erase(_list.front().key);
			_list.pop_front();
		}

		Item item;
		item.key = key;
		item.val = val;
		_list.push_front(item);
		auto curr = _list.begin();
		_data[key] = curr;
	}
}

int main(int argc, char **argv){
	return 0;
}


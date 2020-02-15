#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 先排序 O(n log n).
* 然后遍历计数, 存到优先队列中 O(m log k).
* 无法优于 O(n log n), 但能 work.
***********************************************************/
struct Item{
	int num;
	int count;
	Item():num(0),count(0){}
	
	friend bool operator < (const Item &a, const Item &b){
		return a.count > b.count;
	}
};
vector<int> topKFrequent(vector<int>& nums, int k) {
	std::sort(nums.begin(), nums.end());
	
	priority_queue<Item> q;
	Item item;
	for(int i=0; i<=nums.size(); i++){
		if((i>0 && nums[i] != nums[i-1]) || i == nums.size()){
			q.push(item);
			if(q.size() > k) q.pop();
			
			item.count = 0;
			if(i == nums.size()){
				break;
			}
		}
		item.num = nums[i];
		item.count ++;
	}
	
	vector<int> ret;
	while(q.size() > 0){
		Item item = q.top();
		q.pop();
		ret.push_back(item.num);
	}
	return ret;
}

/***********************************************************
# 解题思路

* 哈希计数. O(n)
* 计数结果存到优先队列, 用 pair 或者 vector 存 count:key.
***********************************************************/
vector<int> topKFrequent2(vector<int>& nums, int k) {
	unordered_map<int, int> mm;
	for(auto n : nums){
		mm[n] ++;
	}
	
	priority_queue<pair<int,int>> q;
	for(auto p : mm){
		q.push(p);
	}
	
	vector<int> ret;
	while(k-- > 0){
		auto p = q.top();
		q.pop();
		ret.push_back(p.second);
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums, ret;
	nums = {1,1,1,2,2,3};
	ret = topKFrequent(nums, 2);
	print_array(ret);
	nums = {1};
	ret = topKFrequent(nums, 1);
	print_array(ret);

	nums = {1,1,1,2,2,3};
	ret = topKFrequent2(nums, 2);
	print_array(ret);
	nums = {1};
	ret = topKFrequent2(nums, 1);
	print_array(ret);
	
	return 0;
}

/*
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/

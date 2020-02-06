#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这是一道滑动窗口的题.
* Time Complexity: O(k * n)
***********************************************************/
bool containsNearbyDuplicate(vector<int>& nums, int k) {
	// int s = 0;
	// for(int e=1; e<nums.size(); e++){
	// 	if(nums[s] == nums[e]){
	// 		return true;
	// 	}
	// 	if(e-s == k){
	// 		s ++;
	// 		e = s; // e = s + 1; // 错!
	// 	}
	// }
	for(int i=0; i<nums.size()-k; i++){
		for(int j=i; j<i+k; j++){
			if(nums[i] == nums[j]){
				return true;
			}
		}
	}
	return false;
}

/***********************************************************
# 解题思路

* 用哈希表计数
* 也是滑动窗口, 保持窗口大小等于 k, 哈希表充当窗口.
* 上沿 e 移动时, 相应计数 +1; 下沿移动时, 相应计数 -1.
* 如果有计数等于 2, 返回 true.
* Time Complexity: O(n), Space Complexity: O(k)
***********************************************************/
bool containsNearbyDuplicate2(vector<int>& nums, int k) {
	unordered_map<int, int> cnt;
	int s = 0;
	for(auto n : nums){
		if(++cnt[n] == 2){
			return true;
		}
		if(cnt.size() == k + 1){
			cnt.erase(nums[s]);
			s ++;
		}
	}
	return false;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3,1};
	printf("%d\n", containsNearbyDuplicate(nums, 3));
	nums = {1,0,1,1};
	printf("%d\n", containsNearbyDuplicate(nums, 1));
	nums = {1,2,3,1,2,3};
	printf("%d\n", containsNearbyDuplicate(nums, 2));
	
	nums = {1,2,3,1};
	printf("%d\n", containsNearbyDuplicate2(nums, 3));
	nums = {1,0,1,1};
	printf("%d\n", containsNearbyDuplicate2(nums, 1));
	nums = {1,2,3,1,2,3};
	printf("%d\n", containsNearbyDuplicate2(nums, 2));
	return 0;
}

/*
Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

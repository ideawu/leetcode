#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <set>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 首先, 肯定是一道滑动窗口题.
* 注意时间复杂度. 这道题希望时间复杂度小于 O(k*n)
* 题目翻译一下: abs(nums[i]-nums[j])<=t, abs(i-j)<=k
* 用 set 充当窗口, 但还要一个变量 s 记录窗口左沿.
* 当一个元素被加入窗口前, 判断窗口中的数是否满足 [n-t, n+t] 这个区间. 
* 用 set 的有序性查找.
***********************************************************/
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
	if(nums.empty()) return false;
	set<int> wnd;
	int s = 0;
	wnd.insert(nums[0]);
	for(int i=1; i<nums.size(); i++){
		int n = nums[i];
		int hi = n + t;
		int lo = n - t;
		
		auto it = wnd.lower_bound(lo);
		if(it != wnd.end() && *it <= hi){
			return true;
		}
		
		wnd.insert(nums[i]);
		if(wnd.size() == k+1){
			wnd.erase(nums[s]);
			s ++;
		}
	}
	return false;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3,1};
	printf("%d\n", containsNearbyAlmostDuplicate(nums, 3, 0));
	nums = {1,0,1,1};
	printf("%d\n", containsNearbyAlmostDuplicate(nums, 1, 2));
	nums = {1,5,9,1,5,9};
	printf("%d\n", containsNearbyAlmostDuplicate(nums, 2, 3));
	return 0;
}

/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.

Example 1:

Input: nums = [1,2,3,1], k = 3, t = 0
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1, t = 2
Output: true
Example 3:

Input: nums = [1,5,9,1,5,9], k = 2, t = 3
Output: false
*/

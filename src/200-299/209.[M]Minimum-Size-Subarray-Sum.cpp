#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用滑动窗口, 当 sum < target 时, hi++, 否则 lo++
* corner case 是最后一个元素.
* 遍历前初始化 sum 为第一个元素, 从第2个元素开始遍历.
***********************************************************/
int minSubArrayLen(int s, vector<int>& nums) {
	if(nums.empty()) return 0;
	int ret = INT_MAX;
	int lo = 0;
	int hi = 1;
	int sum = nums[0];
	while(1){
		if(hi == nums.size() && sum < s){
			break;
		}
		if(sum >= s){
			ret = min(ret, hi-lo);
			sum -= nums[lo];
			lo ++;
		}else{
			sum += nums[hi];
			hi ++;
		}
	}
	return ret == INT_MAX? 0 : ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,3,1,2,4,3};
	printf("%d\n", minSubArrayLen(7, nums));
	nums = {2,3,1,7,2,4,3};
	printf("%d\n", minSubArrayLen(7, nums));
	nums = {2,3,1,2,4,3};
	printf("%d\n", minSubArrayLen(7, nums));
	return 0;
}

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example: 

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
*/

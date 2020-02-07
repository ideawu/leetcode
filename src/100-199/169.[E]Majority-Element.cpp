#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 只需要找出现次数最多的元素即可.
***********************************************************/
int majorityElement(vector<int>& nums) {
	int m=0, mv=INT_MIN;
	unordered_map<int, int> count;
	for(auto n : nums){
		count[n] ++;
		if(count[n] > mv){
			m = n;
			mv = count[n];
		}
	}
    return m;
}

/***********************************************************
# 解题思路

* 采用相对计票算法(摩尔投票).
***********************************************************/
int majorityElement(vector<int>& nums) {
	int ret = -1;
	int cnt = 0;
	for(auto n : nums){
		if(cnt == 0){
			ret = n;
			cnt = 1;
		}else if(ret == n){
			cnt ++;
		}else{
			cnt --;
		}
	}
	// 题目假设有半数, 所以不用判断 cnt
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,2,3};
	printf("%d\n", majorityElement(nums));
	nums = {2,2,1,1,1,2,2};
	printf("%d\n", majorityElement(nums));
	return 0;
}

/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

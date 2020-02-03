#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题并不是求组合, 而是排列.
***********************************************************/
void combination(vector<vector<int>> &ret, vector<int> &nums, int s, int target, vector<int> &pre){
	if(target == 0){
		ret.push_back(pre);
		return;
	}
	for(int i=s; i<nums.size(); i++){
		int n = 0;
		while(1){ // 元素可重复使用
			int t = target - nums[i] * (n+1);
			if(t < 0){
				break;
			}
			n ++;
			pre.push_back(nums[i]);
			combination(ret, nums, i+1, t, pre);
		}
		while(--n >= 0){
			pre.pop_back();
		}
	}
}
void permutation(int &ret, vector<int>& nums, int s){
	if(s == nums.size()){
		ret ++;
		return;
	}
	for(int i=s; i<nums.size(); i++){
		if(i > s && nums[i] == nums[s]) continue;
		if(i > s && nums[i] == nums[i-1]) continue;
		std::swap(nums[s], nums[i]);
		permutation(ret, nums, s+1);
		std::swap(nums[s], nums[i]);
	}
}
int combinationSum4(vector<int>& nums, int target) {
	std::sort(nums.begin(), nums.end());
	int count = 0;
	
	vector<vector<int>> ret;
	vector<int> pre;
	combination(ret, nums, 0, target, pre);
	// print_matrix(ret);
	
	for(auto com : ret){
		int c = 0;
		permutation(c, com, 0);
		// print_matrix(perm);
		count += c;
	}
	
	return count;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,3};
	printf("%d\n", combinationSum4(nums, 4));
	// 超时 test case: [4,1,2] 32
	nums = {4,1,2};
	LOG("");
	printf("%d\n", combinationSum4(nums, 32)); // 39882198
	LOG("");
	return 0;
}

/*
Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.

Example:

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.

Follow up:
What if negative numbers are allowed in the given array?
How does it change the problem?
What limitation we need to add to the question to allow negative numbers?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

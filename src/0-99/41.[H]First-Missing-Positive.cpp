#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题有 Tricky 的地方...
* 无序的数据, 要求 O(n) 时间复杂度, 显然只能常数趟遍历.
* 不能使用额外空间, 那就是修改源数据了.
* Tricky 的点就在于: 结果r必须满足 r>=1 && r<=n+1
	那么只需要找 1-n 是否存在即可.
* 这道题就变成单指针归位的问题, 1-n 的数据不断两两交换直到归位, 其它数据丢弃.
***********************************************************/
int firstMissingPositive(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++){
		while(nums[i] != i+1){
			if(nums[i] <= 0 || nums[i] > nums.size()){
				nums[i] = INT_MAX;
				break;
			}
			std::swap(nums[i], nums[nums[i]-1]);
		}
    }
    for(int i=0; i<nums.size(); i++){
		if(nums[i] == INT_MAX){
			return i+1;
		}
	}
	return 0;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,2,0};
	printf("%d\n", firstMissingPositive(nums));
	nums = {3,4,-1,1};
	printf("%d\n", firstMissingPositive(nums));
	nums = {7,8,9,11,12};
	printf("%d\n", firstMissingPositive(nums));
	return 0;
}

/*
Given an unsorted integer array, find the smallest missing positive integer.

Example 1:

Input: [1,2,0]
Output: 3
Example 2:

Input: [3,4,-1,1]
Output: 2
Example 3:

Input: [7,8,9,11,12]
Output: 1
Note:

Your algorithm should run in O(n) time and uses constant extra space.
*/

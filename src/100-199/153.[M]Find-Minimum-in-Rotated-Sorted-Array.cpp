#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 将数组分成两段, 至少有一段是有序的. 取有序那段的最小值.
* 对无序一半继续二分.
***********************************************************/
int helper(vector<int> &nums, int s, int e){
	if(s == e) return nums[s];
	int m = s + (e-s)/2;
	if(nums[s] < nums[m]){
		return min(nums[s], helper(nums, m+1, e));
	}else{
		return min(nums[m+1], helper(nums, s, m));
	}
}
int findMin(vector<int>& nums) {
	return helper(nums, 0, nums.size()-1);
}

/***********************************************************
# 解题思路

* 可以不用递归, 而且二分后的断言之前并不完善.
* 哪一半无序, 那么最小值(和最大值)就出现在哪一段.
* 如果两半都有序, 直接对比两段的最小(最大)值.
***********************************************************/
int findMin2(vector<int>& nums) {
	if(nums.empty()) return -1;
	int s = 0;
	int e = nums.size() - 1;
	while(s < e){
		int m = s + (e-s)/2;
		if(nums[s] > nums[m]){
			e = m;
		}else if(nums[m+1] > nums[e]){
			s = m + 1;
		}else{
			return min(nums[s], nums[m+1]);
		}
	}
	return nums[s];
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,4,5,1,2};
	printf("%d\n", findMin(nums));
	printf("%d\n", findMin2(nums));
	printf("%d\n", findMin3(nums));
	nums = {4,5,6,7,0,1,2};
	printf("%d\n", findMin(nums));
	printf("%d\n", findMin2(nums));
	printf("%d\n", findMin3(nums));
	return 0;
}

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0
*/

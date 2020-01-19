#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
	int s = 0;
	int e = nums.size() - 1;
	int t = target;
	while(s <= e){
		int mid = s + (e - s)/2;
		if(nums[mid] == t){
			return mid;
		}
		// either left sorted or right sorted
		bool left_sorted = (nums[s] < nums[mid]);
		if(left_sorted){
			if(nums[s] <= t && t < nums[mid]){
				e = mid - 1;
			}else{
				s = mid + 1;
			}
		}else{
			if(nums[mid] < t && t <= nums[e]){
				s = mid + 1;
			}else{
				e = mid - 1;
			}
		}
	}
	return -1;
}

int main(int argc, char **argv){
	vector<int> nums;
	int t;

	nums = {4,5,6,7,0,1,2};
	t = 0;
	printf("%d\n\n", search(nums, 0));

	nums = {4,5,6,7,0,1,2};
	t = 0;
	printf("%d\n\n", search(nums, 3));
	
	return 0;
}

// 主要考察各种条件组合

/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).

Example 1:

Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
Example 2:

Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
*/
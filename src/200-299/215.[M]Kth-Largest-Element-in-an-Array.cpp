#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 借鉴快排的思路, 做 partition, 如果 left > k, 继续对 left partition.
* 需要保证 nums[return] = pivot
***********************************************************/
int partition(vector<int>& nums, int lo, int hi) {
	int p = nums[lo];
	int s = lo + 1;
	int e = hi;
	while(s <= e){
		if(nums[e] > p){
			e --;
		}else if(nums[s] <= p){
			s ++;
		}else{
			swap(nums[s], nums[e]);
			s ++;
			e --;
		}
	}
	// 保证 pivot 放在 e
	swap(nums[lo], nums[e]);
	return e;
}

int findKthLargest(vector<int>& nums, int k) {
	k = nums.size() - k;
	int s = 0;
	int e = nums.size()-1;
	print_array(nums);
	while(1){
		int m = partition(nums, s, e);
		print_array(nums);
		if(m == k){
			return nums[k];
		}
		if(m > k){
			e = m-1;
		}else{
			s = m+1;
		}
	}
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {3,2,1,5,6,4};
	printf("%d\n", findKthLargest(nums, 2));
	nums = {3,2,3,1,2,4,5,5,6};
	printf("%d\n", findKthLargest(nums, 4));
	nums = {3,2,3,1,2,4,5,5,6};
	printf("%d\n", findKthLargest(nums, 3));
	nums = {3,2,3,1,2,4,5,5,6};
	printf("%d\n", findKthLargest(nums, 1));
	return 0;
}

/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
*/

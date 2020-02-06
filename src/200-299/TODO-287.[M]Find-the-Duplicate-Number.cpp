#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 首先根据鸽笼原理可以证明一定有重复元素出现(这个证明要求是个解题提示).
* 要求: 不能修改源数据(为什么不加 const?).
* 要求: O(1) 空间, 不能是 O(n^2) 时间.
* 可以用二分查找
	用中间值遍历一趟查找, 计算大于, 小于等于 2 种情况的计数.
	这样就可以知道重复值所处的区间.
	有点像桶排序?
***********************************************************/
int findDuplicate(vector<int>& nums) {
    int s = 1, e = nums.size()-1;
	while(1){
		if(s == e) return s;
		
		// 没必要限制必须在 [s,e] 范围内计数, 因为以 m 划分,
		// 只要重复数出现在哪一边, 哪一边必然计数大于分段长度.
		// int m = s + (e-s)/2;
		// int cnt=0;
		// for(auto n : nums){
		// 	if(n < s || n > e) continue;
		// 	if(n > m) cnt ++;
		// }
		// if(cnt > e-m){
		// 	s = m + 1;
		// }else{
		// 	e = m;
		// }
		// printf("m: %d\n", m);

		int m = s + (e-s)/2;
		int cnt=0;
		for(auto n : nums){
			if(n <= m) cnt ++;
		}
		printf("[%d,%d] m: %d, cnt: %d\n", s, e, m, cnt);
		if(cnt > m){
			e = m;
		}else{
			s = m + 1;
		}
	}
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,3,4,2,2};
	printf("%d\n", findDuplicate(nums));
	nums = {3,1,3,4,2};
	printf("%d\n", findDuplicate(nums));
	return 0;
}

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

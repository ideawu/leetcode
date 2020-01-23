#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 解题的思路是合并成一个数组, 然后根据数组长度是奇数还是偶数来算出中间值的下标
* 事实上不用进行合并操作, 用两个指针(下标)分别遍历两个数组, 哪个指针对
* 	应的值小就先移动哪个指针, 类似链表合并.
* 注意边界条件
* 这道不应该算 Hard 难度, 只有 Medium 而已?
* 	真正做起来, 边界条件和分支还很有难度的, 特别是为了查找第 n 个元素,
* 	却要尝试找第 n+1 个元素, 然后一在找的过程中维护第 n 个元素的值.
***********************************************************/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int total = nums1.size() + nums2.size();
	int s, e; // 目标两个数的下标(在合并后的数组中), 可能重合
	if(total & 1){ // 奇数
		s = total/2;
		e = s;
	}else{
		e = total/2;
		s = e - 1;
	}

	int i = 0, j = 0;
	int f = s + 1; // 查找第 s+1 个数, 查找过程维护第 s 个数(ns)
	int ns = 0, ne = 0;
	while(1){
		if(i + j == f){
			if(s == e){
				ne = ns;
			}else{
				int a = (i == nums1.size())? INT_MAX : nums1[i];
				int b = (j == nums2.size())? INT_MAX : nums2[j];
				ne = min(a, b);
			}
			return (ns + ne)/2.0;
		}

		if(i == nums1.size()){
			j = f - i;
			ns = nums2[j-1];
			continue;
		}
		if(j == nums2.size()){
			i = f - j;
			ns = nums1[i-1];
			continue;
		}

		if(nums1[i] < nums2[j]){
			ns = nums1[i];
			i ++;
		}else{
			ns = nums2[j];
			j ++;
		}
	}
}

int main(int argc, char **argv){
	vector<int> nums1, nums2;
	nums1 = {1, 3};
	nums2 = {2};
	printf("%f\n", findMedianSortedArrays(nums1, nums2));

	nums1 = {1, 2};
	nums2 = {3, 4};
	printf("%f\n", findMedianSortedArrays(nums1, nums2));

	return 0;
}

/*
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5
*/

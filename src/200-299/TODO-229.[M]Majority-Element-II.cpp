#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* 要求出现大于 n/3 次的元素, 那么符合条件的元素个数不超过2个.
* 要求 O(n) 时间, 只能遍历常数趟.
* 要求 O(1) 空间, 只能修改源数据.
***********************************************************/
vector<int> majorityElement(vector<int>& nums) {
}

/*
Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题主要是考察缓存.
* 关键点在于如何设计缓存方案.
* 如果每一个元素都缓存对应的从头开始的子集总和, 那么用减少即可求出区间的各.
* 增加一个 padding, 让寻址规律起来.
***********************************************************/
class NumArray {
public:
    NumArray(vector<int>& nums) {
		sum.resize(nums.size()+1, 0);
        for(int i=1; i<=nums.size(); i++){
        	sum[i] = nums[i-1] + sum[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return sum[j+1] - sum[i];
    }
private:
	vector<int> sum;
};

/**
 * Your NumArray object will be instantiated and called as such:
 */

int main(int argc, char **argv){
	vector<int> nums = {-2,0,3,-5,2,-1};
	NumArray* obj = new NumArray(nums);
	printf("%d\n", obj->sumRange(0,2));
	printf("%d\n", obj->sumRange(2,5));
	printf("%d\n", obj->sumRange(0,5));
	return 0;
}

/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
Note:
You may assume that the array does not change.
There are many calls to sumRange function.
*/

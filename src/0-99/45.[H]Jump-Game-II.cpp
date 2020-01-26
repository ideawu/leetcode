#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 使用一个 cost 数组, 与输入对应, 记录到达每一步所需要的成本(跳数)
* 从前往后遍历每一个元素, 尝试更新后面可达的元素的成本
* BFS(Breadth First Search) + 演进
***********************************************************/
int jump(vector<int>& nums) {
    vector<int> cost(nums.size(), INT_MAX);
	cost[0] = 0;
	for(int i=0; i<nums.size(); i++){
		for(int j=1; j<=nums[i] && (i+j)<nums.size(); j++){
			cost[i+j] = min(cost[i]+1, cost[i+j]);
		}
	}
	return cost[nums.size()-1];
}

// 递归, DFS + 倒推
int jump2(vector<int>& nums, int s){
	if(s == nums.size() - 1){
		return 0;
	}
	int d = INT_MAX/2; // +1
	for(int j=1; j<=nums[s]; j++){
		int c = jump2(nums, s+j);
		d = min(c+1, d);
	}
	return d;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {2,3,1,1,4};
	printf("%d\n", jump(nums));
	printf("%d\n", jump2(nums, 0));
	return 0;
}

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.
*/
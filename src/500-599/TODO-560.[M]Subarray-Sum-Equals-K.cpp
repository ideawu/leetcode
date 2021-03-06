#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 因为有负数, 所以无法使用滑动窗口.
* 穷举.
* 一趟遍历, 计数每一个节点到头节点的 sum.
* 不断移动头节点指针, 遍历后面每一个节点的 sum - head[i].

* 优化空间: 遇到上升沿或者下降沿(连续的正数或负数)进行聚合, 减少数据总数.
***********************************************************/
int subarraySum(vector<int>& nums, int k) {
	vector<int> cc(nums.size(), 0);
	int ret = 0;
	for(int i=0; i<nums.size(); i++){
		int prev = (i == 0)? 0 : cc[i-1];
		cc[i] = nums[i] + prev;
		if(cc[i] == k){
			ret ++;
		}
	}
	for(int i=0; i<nums.size(); i++){
		for(int j=i+1; j<nums.size(); j++){
			int sum = cc[j] - cc[i];
			if(sum == k){
				ret ++;
			}
		}
	}
	return ret;
}
/***********************************************************
# 解题思路

* 优化空间: 遇到上升沿或者下降沿(连续的正数或负数)进行聚合, 可以跳过某些节点.
* 复杂度分析: 一趟遍历进行分组. 穷举时, 内循环有 1/2 的机率跳过.
***********************************************************/
struct Group {
	int cnt = 0; // 后面连续还有多少个同符号(或0)的数
	int sum = 0;
};

int subarraySum2(vector<int>& nums, int k) {
	vector<Group> gs;
	int ret = 0;
	
	Group g;
	for(int i=0; i<nums.size(); i++){
		if(i == nums.size() || i > 0 && nums[i] * nums[i-1] < 0){
			int s = i - g.cnt;
			int e = i - 1;
			while(g.cnt > 0){
				gs[s] = g;
				g.cnt --;
				g.sum -= nums[e];
				s ++;
				e --;
			}
		}
		if(i < nums.size()){
			g.cnt ++;
			g.sum += nums[i];
		}
	}
	
	for(int i=0; i<nums.size(); i++){
		int sum = 0;
		for(int j=i; j<nums.size(); j++){
			Group &g = gs[j];
			if(sum > k && sum + g.sum > k || sum < k && sum + g.sum < k
					|| sum == k && g.sum != 0)
			{
				sum += g.sum;
				j += g.cnt - 1;
				continue;
			}
			sum += nums[i];
			if(sum == k){
				ret ++;
			}
		}
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums = {1,1,1};
	printf("%d\n", subarraySum(nums, 2));
	printf("%d\n", subarraySum2(nums, 2));
	return 0;
}

/*
Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
*/

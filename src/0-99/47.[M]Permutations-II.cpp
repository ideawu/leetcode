#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 和 46. Permutations 类似.
* 图遍历.
* 对输入进行排序. [1,1,2,3,3]
* 如果多个入口相同, 则只选其中一个.
	i > s && [i] == [i-1]
* 进入入口后, 如果发现下一步与入口相同, 则忽略
	i > s && [i] == [s] (交换后)
* 因为有 i>s 条件, 所以重复元素都会被遍历到.
***********************************************************/
void helper(vector<vector<int>> &ret, vector<int>& nums, int s, vector<int> &pre){
	if(s == nums.size()){
		ret.push_back(pre);
		return;
	}
	for(int i=s; i<nums.size(); i++){
		if(i > s && nums[i] == nums[i-1]) continue;
		if(i > s && nums[i] == nums[s]) continue;
		std::swap(nums[s], nums[i]);
		pre.push_back(nums[s]);
		helper(ret, nums, s+1, pre);
		pre.pop_back();
		std::swap(nums[s], nums[i]);
	}
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, nums, 0, pre);
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums;
	nums = {1,1,2};
	print_matrix(permuteUnique(nums));
	nums = {1,2,1};
	print_matrix(permuteUnique(nums));
	
	nums = {3,2,1};
	nums = {4,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2};
    vector<vector<int>> ret;
	ret = permuteUnique(nums);
	printf("%d\n", (int)ret.size());
	// print_matrix(permuteUnique(nums), "[", "]");
	
	std::sort(nums.begin(), nums.end());
	int n = 0;
	do{
		auto it = std::find(ret.begin(), ret.end(), nums);
		if(it == ret.end()){
			printf("error!\n");
			print_array(nums);
			break;
		}
		n ++;
	}while(std::next_permutation(nums.begin(), nums.end()));
	printf("%d\n", n);
	if(ret.size() != n){
		printf("error!\n");
	}
	
	return 0;
}

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/

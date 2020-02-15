#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 先用穷举法试试.
* 递归调用次数: n! + (n-1)! + ...
* 优化空间在于, 如果能跟前序路径的最大值整除, 就不用跟整个集合比较了.
* 排列组合子集的题目一般预先对输入数据进行排序.
***********************************************************/
void helper(vector<int>& ret, vector<int>& path, vector<int>& nums, int s){
	if(s == nums.size()){
		return;
	}
	for(int i=s; i<nums.size(); i++){
		// bool can = true;
		// for(auto n : path){
		// 	if(n % nums[i] != 0 && nums[i] % n != 0){
		// 		can = false;
		// 		break;
		// 	}
		// }
		// if(!can) continue;
		if(!path.empty() && nums[i]%path[path.size()-1] != 0){
			continue;
		}
		
		path.push_back(nums[i]);
		if(path.size() > ret.size()){
			ret = path;
		}
		helper(ret, path, nums, i+1);
		path.pop_back();
	}
}
vector<int> largestDivisibleSubset(vector<int>& nums) {
	std::sort(nums.begin(), nums.end());

	vector<int> ret, path;
	helper(ret, path, nums, 0);
	return ret;
}

/***********************************************************
# 解题思路

* 因为只要跟前序路径的最大值比较即可, 所以只需要记录当前节点与前序哪一个节点连接.
* 缓存每一个节点作为末尾元素时对应的最大子集大小.
* 缓存每一个子集中末尾元素对应的前一个节点.
* 这样, 通过引用指针, 在数组中保存一棵树.
* 这个动态规划算法的最大难点, 就是不用保存 Result(路径), 而是只保存
	路径中的每一个节点的父子关系, 最终也能组装回一条路径.
* 当然, 也要保存 Result 的关键信息, 如成本.
* 在工程上, 通过离散地定义两两节点的父子(连通)关系来保存树和图, 这是非常
	普遍的技术, 例如在 db 中保存菜单. 到了这里所谓的算法题, 突然就无法对应了...
	所以说, 工程实践上可能已经应用了很多所谓的算法, 但平时未必能想到理论.
***********************************************************/
vector<int> largestDivisibleSubset2(vector<int>& nums) {
	std::sort(nums.begin(), nums.end());
	
	vector<int> res(nums.size(), 0); // last item => subset count
	vector<int> link(nums.size(), -1); // last item => prev item
	
	int max_i = 0; // 当前已找到的最长 subset 的末尾元素下标
	res[0] = 1;
	for(int i=1; i<nums.size(); i++){
		// 回溯
		for(int j=0; j<i; j++){
			if(nums[i] % nums[j] == 0){
				if(res[j] + 1 > res[i]){
					res[i] = res[j] + 1;
					link[i] = j;
				}
			}
		}
		if(res[i] > res[max_i]){
			max_i = i;
		}
	}
	
	// 通过连通关系(父子关系), 生成路径
	vector<int> ret;
	while(max_i != -1){
		ret.push_back(nums[max_i]);
		max_i = link[max_i];
	}
	return ret;
}

int main(int argc, char **argv){
	vector<int> nums, ret;
	
	nums = {1,2,3};
	ret = largestDivisibleSubset2(nums);
	print_array(ret);
	nums = {1,2,4,8};
	ret = largestDivisibleSubset2(nums);
	print_array(ret);
	nums = {1,2,4,8,9,3};
	ret = largestDivisibleSubset2(nums);
	print_array(ret);
	
	return 0;
}

/*
Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies:

Si % Sj = 0 or Sj % Si = 0.

If there are multiple solutions, return any subset is fine.

Example 1:

Input: [1,2,3]
Output: [1,2] (of course, [1,3] will also be ok)
Example 2:

Input: [1,2,4,8]
Output: [1,2,4,8]
*/

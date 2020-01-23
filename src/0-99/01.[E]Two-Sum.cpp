#include <stdio.h>
#include <string>
#include <vector>
#include <unordered_map>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* 这是天字第一道题, Easy 级别
* 这道题有几个考察目的: 暴力破解, 常用数据结构, 边界条件, 逆向思维
* 暴力破解: 这个方法是很多问题的解法, 有时会基于此再进行优化
* 如果要说有技巧的话, 那就是逆向思维, 把加法变减法
* 常用数据结构封装的使用: 虽然是所谓的"算法题", 但使用常见的数据结构
*	封装也是正常的, 并不排斥! 当然你要知道这些数据结构的成本
* 对于 C++ 来说, vector, list, queue, stack, priority_queue,
*	map/unordered_map, set 这些都可以使用, 不过 queue 和 stack
*	一般用 vector 和 list 代替.
***********************************************************/
vector<int> twoSum(vector<int>& nums, int target) {
	
}

vector<int> twoSum2(vector<int>& nums, int target) {
	vector<int> ret;
	// 如果暴力破解这样写的话, 可能难以直接想到优化的点, 因为逆向思维
	// 不是那么容易有的...
	for(int i=0; i<nums.size(); i++){
		for(int j=i+1; j<nums.size(); j++){
			if(nums[i] + nums[j] == target){
				ret.push_back(i);
				ret.push_back(j);
				break;
			}
		}
	}
	return ret;
}

vector<int> twoSum2(vector<int>& nums, int target) {
	vector<int> ret;
	// 如果代码写成这样, 也许我们能总结出这样的算法逻辑:
	// 对于每一个数 a, 遍历找出另一个数 b 与它相加等于 t,
	// 这种写法是很自然的, 因为 CPU 间接寻址也许比直接寻址慢?
	for(int i=0; i<nums.size(); i++){
		int a = nums[i];
		for(int j=i+1; j<nums.size(); j++){
			int b = nums[j];
			if(a + b == target){
				ret.push_back(i);
				ret.push_back(j);
				break;
			}
		}
	}
	return ret;
}

vector<int> twoSum3(vector<int>& nums, int target) {
	vector<int> ret;
	// 那么, 我们要找的数 b 是多少? 这里, 需要用一点逆向思维
	// 对于给定的 a, b = t - a, 这样, 就可以把多次加法运算
	// 变成一次减少运算和多次比较运算. 加法运算比比较运算慢?
	for(int i=0; i<nums.size(); i++){
		int a = nums[i];
		int b = target - a;
		for(int j=i+1; j<nums.size(); j++){
			if(nums[j] == b){
				ret.push_back(i);
				ret.push_back(j);
				break;
			}
		}
	}
	return ret;
}

vector<int> twoSum4(vector<int>& nums, int target) {
	vector<int> ret;
	for(int i=0; i<nums.size(); i++){
		int a = nums[i];
		int b = target - a;
		// TODO: if b in nums[i+1:]

		// 这样的话, 进一步的优化点在于用其它更快的查找算法替代顺序查找.
		// 更快的查找算法:
		// 排序后二分查找, 建立树之后查找, 建立哈希表后查找. 决定采用哈希表查找.

		// 那么, 问题来了: 真的需要建立哈希表之后再查找吗?
		// 这需要两次遍历, 能不能优化成一次遍历? 即在遍历过程中建表并查找?
		// 好像不行?
		// 这时, 又需要一点点逆向思维以及逻辑思维了.

		// TODO: 逆向思维...
	}
	return ret;
}

/*
所以, 优化的思路是:
1. 缓存变量, 减少数组下标取值次数
2. 减少加法, 减法等计算次数, 变成数值比较运算
3. 转变成查找算法问题
4. 查找算法根据业务的特点, 进行初始化和查找这两个步骤的优化
*/

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
*/

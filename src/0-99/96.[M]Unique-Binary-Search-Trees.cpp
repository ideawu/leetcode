#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 将这 1-n 组成一个数组, 依次取一个元素作为根节点.
* 左边的列表和右边的列表各组成左右子树, 那就有 m*n 种组合.
* 注意, 0 个元素有 1 种, 1 个元素有 1 种.
***********************************************************/
int numTrees(int n) {
	if(n == 0 || n == 1) return 1;
	int ret = 0;
	for(int i=1; i<=n; i++){
		ret += numTrees(i-1) * numTrees(n-i);
	}
	return ret;
}

/***********************************************************
# 解题思路

* 递归, 但缓存计算结果
***********************************************************/
int helper2(vector<int> &close_list, int n){
	if(close_list[n] != 0){
		return close_list[n];
	}
	
	int ret = 0;
	for(int i=1; i<=n; i++){
		ret += helper2(close_list, i-1) * helper2(close_list, n-i);
	}
	
	close_list[n] = ret;
	return ret;
}
int numTrees2(int n) {
	vector<int> close_list(n+1, 0);
	close_list[0] = 1;
	close_list[1] = 1;
	return helper2(close_list, n);
}

/***********************************************************
# 解题思路

* 不用递归, 改为迭代. 所谓 DP(优化图遍历).
***********************************************************/
int numTrees3(int n) {
	vector<int> close_list(n+1, 0);
	close_list[0] = 1;
	close_list[1] = 1;
	for(int i=2; i<=n; i++){
		for(int j=0; j<i; j++){
			close_list[i] += close_list[j] * close_list[i-j-1];
		}
	}
	return close_list[n];
}

int main(int argc, char **argv){
	// vector<int> r1;
	// runtime();
	// for(int i=1; i<20; i++){
	// 	int n = numTrees(i);
	// 	// printf("%d = %d\n", i, n);
	// 	r1.push_back(n);
	// }
	runtime();
	
	vector<int> r2;
	for(int i=1; i<1000; i++){
		int n = numTrees2(i);
		// printf("%d = %d\n", i, n);
		r2.push_back(n);
	}
	runtime();

	vector<int> r3;
	for(int i=1; i<1000; i++){
		int n = numTrees3(i);
		// printf("%d = %d\n", i, n);
		r3.push_back(n);
	}
	runtime();

	printf("%d\n", r3 == r2);
	
	return 0;
}

// 

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

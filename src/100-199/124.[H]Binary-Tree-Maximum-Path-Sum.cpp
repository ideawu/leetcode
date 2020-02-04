#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归
* 分别计算如下路径:
	1. 左子节点到叶子节点的最大路径 lds, 以及左子树内的最大连通路径 lts.
	2. 右子节点到叶子节点的最大路径 rds, 以及右子树内的最大连通路径 rts.
	3. 连通根节点和左右路径的最大路径 ts=val+max(lds,0)+max(rds,0)
* max(lds,0) 表示可以不连接左边
* 根节点到左右叶子节点的最大路径 lds+val, rds+val, 显然都比 ts 小.
* 这样就可以知道当前的最大路径 maxl=max(ts, lts, rts)
* 更新 ds=max(val+lds, val+rds) 向上传
***********************************************************/
int helper(TreeNode *root, int *ds){
	if(!root){
		*ds = 0;
		return INT_MIN;
	}
	int ts, lts, rts, lds, rds;
	lts = helper(root->left, &lds);
	rts = helper(root->right, &rds);
	// ts 可以不连接左右
	ts = root->val + max(lds, 0) + max(rds, 0);
	// 但 ds 必须连接左或者右
	*ds = root->val + max(lds, rds);
	return max(ts, max(lts, rts));
}
int maxPathSum(TreeNode* root) {
	int maxs;
	return helper(root, &maxs);
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({1,2,3});
	print_tree(root);
	printf("%d\n", maxPathSum(root));
	root = build_tree({-10,9,20,0,0,15,7});
	print_tree(root);
	printf("%d\n", maxPathSum(root));
	return 0;
}

/*
Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42
*/

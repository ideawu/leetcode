#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 树的DFS遍历.
***********************************************************/
bool hasPathSum(TreeNode* root, int sum) {
	if(!root) return sum == 0;
	sum -= root->val;
	return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({5,4,8,11,0,13,4,7,2,0,0,0,1});
	print_tree(root);
	printf("%d\n", hasPathSum(root, 22));
	return 0;
}

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1
return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
*/

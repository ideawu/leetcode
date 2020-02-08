#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 中序遍历, 带上前序路径, 到叶子节点时更新总数.
***********************************************************/
void helper(TreeNode *n, int pre, int *total){
	pre = pre * 10 + n->val;
	if(!n->left && !n->right){
		*total += pre;
		return;
	}
	if(n->left) helper(n->left, pre, total);
	if(n->right) helper(n->right, pre, total);
}
int sumNumbers(TreeNode* root) {
	if(!root) return 0;
    int total = 0;
	int pre = 0;
	helper(root, pre, &total);
	return total;
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({1,2,3});
	print_tree(root);
	printf("%d\n", sumNumbers(root));
	root = build_tree({4,9,0,5,1}, INT_MAX);
	print_tree(root);
	printf("%d\n", sumNumbers(root));
	return 0;
}

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.
*/

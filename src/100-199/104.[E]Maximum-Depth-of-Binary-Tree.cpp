#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 就是穷举, 找出最长的一条根到节点的路径.
***********************************************************/
int maxDepth(TreeNode* root) {
	if(!root) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({3,9,20,0,0,15,7});
	print_tree(root);
	printf("%d\n", maxDepth(root));
	return 0;
}

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.

*/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 和求 maxDepth 类似, 就是递归穷举.
***********************************************************/
int minDepth(TreeNode* root) {
	if(!root) return 0;
	return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({3,9,20,0,0,15,7});
	print_tree(root);
	printf("%d\n", minDepth(root));
	return 0;
}

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
*/

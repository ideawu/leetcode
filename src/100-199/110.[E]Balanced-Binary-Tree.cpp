#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归, 判断左右两个节点的最大深度是否相差在1以内.
***********************************************************/
int maxDepth(TreeNode* root) {
	if(!root) return 0;
	return 1 + max(maxDepth(root->left), maxDepth(root->right));
}
bool isBalanced(TreeNode* root) {
	if(!root) return true;
	return isBalanced(root->left) && isBalanced(root->right) &&
		(abs(maxDepth(root->left) - maxDepth(root->right)) <= 1);
}

/***********************************************************
# 解题思路

* 在遍历的过程记录当前尝试和最大深度, 一旦两个深度差超过 1 则停止遍历.
* 注意边界条件, maxDepth 要赋值之后才比较深度差.
***********************************************************/
bool helper(TreeNode *root, int depth, int &maxDepth){
	if(!root){
		maxDepth = max(maxDepth, depth);
		return true;
	}
	if(maxDepth > 0 && abs(maxDepth - depth) > 1){
		return false;
	}
	return helper(root->left, depth+1, maxDepth) &&
		helper(root->right, depth+1, maxDepth);
}
bool isBalanced2(TreeNode* root) {
	int maxd = 0;
	return helper(root, 0, maxd);
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({3,9,20,0,0,15,7});
	print_tree(root);
	printf("%d\n", isBalanced(root));
	printf("%d\n", isBalanced2(root));
	root = build_tree({1,2,2,3,3,0,0,4,4});
	print_tree(root);
	printf("%d\n", isBalanced(root));
	printf("%d\n", isBalanced2(root));
	return 0;
}

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.

*/

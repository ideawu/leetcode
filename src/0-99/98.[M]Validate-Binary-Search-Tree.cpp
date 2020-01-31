#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归
* 判断左子节点和右子节点; 传递给左边上限值, 传递给右边下限值.
***********************************************************/
bool helper(TreeNode *root, int lo, int hi){
	if(!root){
		return true;
	}
	if(root->val <= lo || root->val >= hi){
		return false;
	}
	return helper(root->left, lo, root->val) && helper(root->right, root->val, hi);
}
bool isValidBST(TreeNode* root) {
    return helper(root, INT_MIN, INT_MAX);
}

/***********************************************************
# 解题思路

* 中序遍历: 中序遍历会先访问所有左边的节点, 父节点, 然后右边所有的节点.
	所以, 每访问一个节点时, 必须比前一个节点(且仅前一个节点)大.
	即: 左 < 父 < 右, 遍历的次序正好符合 BST 的定义.
***********************************************************/
bool helper2(TreeNode *root, int *v){
	if(!root){
		return true;
	}
	if(!helper2(root->left, v)){
		return false;
	}
	
	if(!(*v < root->val)){
		return false;
	}
	*v = root->val;
	
	if(!helper2(root->right, v)){
		return false;
	}
	return true;
}
bool isValidBST2(TreeNode* root) {
	int v = INT_MIN;
    return helper2(root, &v);
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({2,1,3});
	print_tree(root);
	printf("%d\n", isValidBST(root));
	printf("%d\n", isValidBST2(root));
	root = build_tree({5,1,4,0,0,3,6});
	print_tree(root);
	printf("%d\n", isValidBST(root));
	printf("%d\n", isValidBST2(root));
	return 0;
}

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
*/

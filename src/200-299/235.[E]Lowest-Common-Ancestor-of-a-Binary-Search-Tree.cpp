#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 根据 p, q 被当前节点分隔的情况, 决定在左还右子树中查找.
* 如果 q < n, 在左子树找
* 如果 p > n, 在右子树找
* 否则, 返回 n
***********************************************************/
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	if(q->val < root->val){
		return lowestCommonAncestor(root->left, p, q);
	}
	if(p->val > root->val){
		return lowestCommonAncestor(root->right, p, q);
	}
	return root;
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({6,2,8,0,4,7,9,0,0,3,5});
	print_tree(root);
	TreeNode *n;
	
	n = lowestCommonAncestor(root, bst_find(root, 2), bst_find(root, 8));
	printf("%d\n", n->val);
	n = lowestCommonAncestor(root, bst_find(root, 2), bst_find(root, 4));
	printf("%d\n", n->val);
	n = lowestCommonAncestor(root, bst_find(root, 7), bst_find(root, 8));
	printf("%d\n", n->val);
	n = lowestCommonAncestor(root, bst_find(root, 8), bst_find(root, 9));
	printf("%d\n", n->val);
	
	return 0;
}

/*
Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given binary search tree:  root = [6,2,8,0,4,7,9,null,null,3,5]


 

Example 1:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8
Output: 6
Explanation: The LCA of nodes 2 and 8 is 6.
Example 2:

Input: root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4
Output: 2
Explanation: The LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
*/

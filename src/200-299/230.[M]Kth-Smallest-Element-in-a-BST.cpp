#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用中序遍历. 遍历时带上计数器.
* 然后判断计数器是否为0, 否则计数器减1. 找不到就返回 INT_MAX 继续递归.
* 注意 (*k)-- 和 *k-- 的不同!
***********************************************************/
int helper(TreeNode *n, int *k){
	if(!n){
		return INT_MAX;
	}
	int ret = helper(n->left, k);
	if(ret != INT_MAX){
		return ret;
	}
	
	(*k)--;
	if(*k == 0){
		return n->val;
	}
	
	return helper(n->right, k);
}
int kthSmallest(TreeNode* root, int k) {
	return helper(root, &k);
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({3,1,4,0,2});
	printf("%d\n", kthSmallest(root, 1));
	root = build_tree({5,3,6,2,4,0,0,1});
	printf("%d\n", kthSmallest(root, 3));
	return 0;
}

/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
*/

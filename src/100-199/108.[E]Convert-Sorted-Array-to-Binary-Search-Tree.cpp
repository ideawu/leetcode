#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 数组的中点就是根节点, 这样左右两边节点数相等(或者+1), 所以是平衡的.
* 继续按中点拆分.
***********************************************************/
TreeNode* helper(vector<int>& nums, int s, int e){
	if(s > e){
		return NULL;
	}
	int m = s + (e-s)/2;
	TreeNode *root = new TreeNode(nums[m]);
	root->left = helper(nums, s, m-1);
	root->right = helper(nums, m+1, e);
	return root;
}
TreeNode* sortedArrayToBST(vector<int>& nums) {
	return helper(nums, 0, nums.size()-1);
}

int main(int argc, char **argv){
	vector<int> nums = {-10,-3,0,5,9};
	TreeNode *root = sortedArrayToBST(nums);
	print_tree(root);
	return 0;
}

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

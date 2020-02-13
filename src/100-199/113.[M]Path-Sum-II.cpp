#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 树的DFS遍历.
* 注意边界条件, 如果左右子节点都为 NULL 时, 不遍历右节点.
***********************************************************/
void helper(vector<vector<int>> &ret, TreeNode* root, int sum, vector<int> &pre) {
	if(!root){
		if(sum == 0){
			ret.push_back(pre);
		}
    	return;
    }
	sum -= root->val;
	
	pre.push_back(root->val);
	helper(ret, root->left, sum, pre);
	pre.pop_back();
	
	if(root->left || root->right){
		pre.push_back(root->val);
		helper(ret, root->right, sum, pre);
		pre.pop_back();
	}
}
vector<vector<int>> pathSum(TreeNode* root, int sum) {
	vector<vector<int>> ret;
	vector<int> pre;
	helper(ret, root, sum, pre);
	return ret;
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({5,4,8,11,0,13,4,7,2,0,0,0,0,5,1});
	print_tree(root);
	print_matrix(pathSum(root, 22));
	return 0;
}

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归
***********************************************************/
void helper(vector<vector<int>> &ret, TreeNode *root, int depth){
	if(!root){
		return;
	}
	if(ret.size() <= depth){
		ret.push_back({});
	}
	ret[depth].push_back(root->val);
	helper(ret, root->left, depth+1);
	helper(ret, root->right, depth+1);
}
vector<vector<int>> levelOrder(TreeNode* root) {
	vector<vector<int>> ret;
	helper(ret, root, 0);
	return ret;
}

vector<vector<int>> levelOrder2(TreeNode* root) {
	vector<vector<int>> ret;
	list<TreeNode*> q;
	q.push_back(root);
	while(!q.empty()){
		vector<int> row;
		for(int i=q.size(); i>0; i--){
			TreeNode *n = q.front();
			q.pop_front();
			row.push_back(n->val);
			if(n->left) q.push_back(n->left);
			if(n->right) q.push_back(n->right);
		}
		ret.push_back(row);
	}
	return ret;
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({3,9,20,0,0,15,7});
	print_tree(root);
	print_matrix(levelOrder(root), "[", "]");
	print_matrix(levelOrder2(root), "[", "]");
	return 0;
}

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
*/

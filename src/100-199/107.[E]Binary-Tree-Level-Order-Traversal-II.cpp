#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* BFS 访问后再逆序结果.
* 每一层之间用 NULL 分隔.
***********************************************************/
vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
	std::reverse(ret.begin(), ret.end());
	return ret;
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({3,9,20,0,0,15,7});
	print_tree(root);
	vector<vector<int>> ret = levelOrderBottom(root);
	print_matrix(ret);
	return 0;
}

/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

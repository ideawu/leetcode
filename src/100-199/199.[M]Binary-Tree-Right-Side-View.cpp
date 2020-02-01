#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 前序遍历, 但右节点先于左节点.
* 传递当前节点的深度和已看到的节点的最大深度. 已看到的最大深度会被修改.
***********************************************************/
void helper(vector<int> &ret, TreeNode *n, int level, int &seen){
	if(!n) return;
	if(level > seen){
		ret.push_back(n->val);
		seen = level;
	}
	helper(ret, n->right, level+1, seen);
	helper(ret, n->left, level+1, seen);
}
vector<int> rightSideView(TreeNode* root) {
	vector<int> ret;
	int seen = -1;
	helper(ret, root, 0, seen);
	return ret;
}

/***********************************************************
# 解题思路

* 广度优化遍历, 取每一层的最后一个元素.
***********************************************************/
vector<int> rightSideView2(TreeNode* root) {
	vector<int> ret;
	list<TreeNode*> q;
	q.push_back(NULL);
	q.push_back(root);
	while(1){
		TreeNode *n = q.front();
		q.pop_front();
		if(n == NULL){
			if(q.empty()){
				break;
			}
			ret.push_back(q.back()->val);
			q.push_back(NULL);
		}else{
			if(n->left) q.push_back(n->left);
			if(n->right) q.push_back(n->right);
		}
	}
	return ret;
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({1,2,3,0,5,0,4});
	print_tree(root);
	print_array(rightSideView(root));
	print_array(rightSideView2(root));
	root = build_tree({1,2,3,0,5});
	print_tree(root);
	print_array(rightSideView(root));
	print_array(rightSideView2(root));
	return 0;
}

/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
*/

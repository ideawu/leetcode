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

/***********************************************************
# 解题思路

* 广度优先遍历, 用 NULL 来做分隔符.
***********************************************************/
vector<vector<int>> levelOrder2(TreeNode* root) {
    vector<vector<int>> ret;
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
			
			vector<int> row;
			for(auto s : q){
				row.push_back(s->val);
			}
			ret.push_back(row);
			
			q.push_back(NULL);
		}else{
			if(n->left) q.push_back(n->left);
			if(n->right) q.push_back(n->right);
		}
	}
	
	return ret;
}

// TODO: 将遍历结果放到 vector 中, q 只用于模拟调用栈.
vector<vector<int>> levelOrder3(TreeNode* root) {
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

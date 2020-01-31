#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 广度优先遍历.
* 用 NULL 来分隔每一层的节点列表.
* 先遍历左节点还是右节点的不同.
***********************************************************/
vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
	vector<vector<int>> ret;
    list<TreeNode*> q;
	bool ltr = true;
	
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
			if(!ltr){
				std::reverse(row.begin(), row.end());
			}
			ret.push_back(row);

			ltr = !ltr;
			q.push_back(NULL);
		}else{
			if(n->left) q.push_back(n->left);
			if(n->right) q.push_back(n->right);
		}
	}
	
	return ret;
}

// 将遍历结果放到 vector 中, q 只用于模拟调用栈.
vector<vector<int>> zigzagLevelOrder2(TreeNode* root) {
	vector<vector<int>> ret;
	vector<int> row;
    list<TreeNode*> q;
	
	q.push_back(root);
	q.push_back(NULL);
	bool ltr = true;
	while(1){
		TreeNode *n;
		if(ltr){
			n = q.front();
			q.pop_front();
		}else{
			n = q.back();
			q.pop_back();
		}
		if(n == NULL){
			ret.push_back(row);
			row.clear();
			if(q.empty()){
				break;
			}
			ltr = !ltr;
			if(ltr){
				q.push_back(NULL);
			}else{
				q.push_front(NULL);
			}
		}else{
			row.push_back(n->val);
			if(ltr){
				if(n->left) q.push_back(n->left);
				if(n->right) q.push_back(n->right);
			}else{
				if(n->right) q.push_front(n->right);
				if(n->left) q.push_front(n->left);
			}
		}
	}
	
	return ret;
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({3,9,20,1,2,15,7,3,4,5});
	print_tree(root);
	print_matrix(zigzagLevelOrder(root));
	print_matrix(zigzagLevelOrder2(root));
	return 0;
}

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

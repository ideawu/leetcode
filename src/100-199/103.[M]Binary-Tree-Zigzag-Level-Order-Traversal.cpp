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

int main(int argc, char **argv){
	TreeNode *root = build_tree({3,9,20,0,0,15,7});
	print_tree(root);
	print_matrix(zigzagLevelOrder(root));
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

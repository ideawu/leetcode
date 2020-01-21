#include <stdio.h>
#include <string>
#include <vector>
#include "../include/tree.h"

using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
	vector<int> ret;
	vector<TreeNode*> nodes;
	TreeNode *n = root;

	// 函数入栈, 根节点
	nodes.push_back(n);
	while(1){
		if(nodes.empty()){ // 递归栈为空
			break;
		}

		if(n->left){
			// 函数入栈, 左节点
			n = n->left;
			nodes.push_back(n);
			continue; //
		}

		// 函数出栈
		n = nodes.back();
		nodes.pop_back();

		// 业务逻辑处理
		ret.push_back(n->val);

		if(n->right){
			// 函数入栈, 右节点
			n = n->right;
			nodes.push_back(n);
		}
	}
	for(auto n : ret){
		printf("%d ", n);
	}
	printf("\n");
	return ret;
}

int main(int argc, char **argv){
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1->right = n2;
	n2->left = n3;
	inorderTraversal(n1);
	return 0;
}

/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/

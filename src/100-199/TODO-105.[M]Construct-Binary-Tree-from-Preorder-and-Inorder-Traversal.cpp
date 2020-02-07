#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

int main(int argc, char **argv){
	return 0;
}

/***********************************************************
# 解题思路

* 对于前序遍历, 父节点后面连续的 n 个元素是其左子树. 当然, n 还不确定.
* 对于中序遍历, 父节点前面连续的 n 个元素是其左子树.
* 用前序遍历和中序遍历共同可以确定 n.
***********************************************************/
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	TreeNode *root;
	root = new TreeNode(preorder[0]);
	

	
	return root;
}
/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 对于前序遍历, 父节点后面连续的 n 个元素是其左子树. 当然, n 还不确定.
* 对于中序遍历, 父节点前面连续的 n 个元素是其左子树.
* 用前序遍历和中序遍历共同可以确定 n.
***********************************************************/
TreeNode* helper(vector<int> &po, int ps, int pe, vector<int> &io, int is, int ie){
	if(ps > pe) return NULL;
	TreeNode *root = new TreeNode(po[ps]);
	int p = std::find(io.begin()+is, io.begin()+ie+1, po[ps]) - io.begin();
	int llen = p - is;
	int rlen = ie - p;
	root->left = helper(po, ps+1, ps+llen, io, is, p-1);
	root->right = helper(po, ps+llen+1, pe, io, p+1, ie);
	return root;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	return helper(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
}

int main(int argc, char **argv){
	vector<int> preorder = {3,9,20,15,7};
	vector<int> inorder =  {9,3,15,20,7};
	print_tree(buildTree(preorder, inorder));
	return 0;
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

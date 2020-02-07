#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 对于后序遍历, 父节点前 n 个是其右子树.
* 对于中序遍历, 父节点后 n 个是其右子树.
***********************************************************/
TreeNode* helper(vector<int> &po, int ps, int pe, vector<int> &io, int is, int ie){
	if(ps > pe) return NULL;
	TreeNode *root = new TreeNode(po[pe]);
	int p = std::find(io.begin()+is, io.begin()+ie+1, po[pe]) - io.begin();
	int llen = p - is;
	int rlen = ie - p;
	root->left = helper(po, ps, ps+llen-1, io, is, p-1);
	root->right = helper(po, ps+llen, pe-1, io, p+1, ie);
	return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return helper(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1);
}

int main(int argc, char **argv){
	vector<int> inorder =   {9,3,15,20,7};
	vector<int> postorder = {9,15,7,20,3};
	print_tree(buildTree(inorder, postorder));
	return 0;
}

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题的来历让人唏嘘.
***********************************************************/
TreeNode* invertTree(TreeNode* root) {
    if(!root){
    	return NULL;
    }
	std::swap(root->left, root->right);
	invertTree(root->left);
	invertTree(root->right);
	return root;
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({4,2,7,1,3,6,9});
	print_tree(root);
	invertTree(root);
	print_tree(root);
	return 0;
}

/*
Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can’t invert a binary tree on a whiteboard so f*** off.
*/

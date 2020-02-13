#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 从示例看, 这是中序遍历的结果.
* 将左右子树 flatten, 记录尾结点. 然后连接.
* 别忘了将 left 清空.
***********************************************************/
void helper(TreeNode *root, TreeNode **tail){
	if(!root){
		return;
	}
	TreeNode *l=root->left, *r=root->right;
	if(l){
		helper(l, tail);
		root->left = NULL;
		root->right = l;
		(*tail)->right = r;
	}
	*tail = root;
	if(r){
		helper(r, tail);
	}
}
void flatten(TreeNode* root) {
	TreeNode *t;
	helper(root, &t);
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({1,2,5,3,4,0,6});
	print_tree(root);
	flatten(root);
	print_tree(root);
	return 0;
}

/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
*/

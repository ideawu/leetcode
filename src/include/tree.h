#include <stdio.h>

struct TreeNode {
	int val;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

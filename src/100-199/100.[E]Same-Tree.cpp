#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 这道题很简单, 就是树遍历. 可以用递归, 也可以用队列辅助遍历.
* 就是考察遍历树的两种方式.
***********************************************************/
bool isSameTree(TreeNode* p, TreeNode* q) {
	if(!p && !q){
		return true;
	}
	if(!p || !q){
		return false;
	}
	return p->val == q->val &&
		isSameTree(p->left, q->left) && isSameTree(p->right, p->right);
}

int main(int argc, char **argv){
	TreeNode *a, *b;
	a = build_tree({1,2,3});
	b = build_tree({1,2,3});
	printf("%d\n", isSameTree(a, b));
	a = build_tree({1,2});
	b = build_tree({1,0,2});
	printf("%d\n", isSameTree(a, b));
	a = build_tree({1,2,1});
	b = build_tree({1,1,2});
	printf("%d\n", isSameTree(a, b));
	return 0;
}

/*
Given two binary trees, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Example 1:

Input:     1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

Output: true
Example 2:

Input:     1         1
          /           \
         2             2

        [1,2],     [1,null,2]

Output: false
Example 3:

Input:     1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

Output: false
*/

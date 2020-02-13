#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 采用中序遍历.
* 记录当前节点的 level
* 找到 p 或 q 后, f=found=p, found_level=min(found_level, level)
* 找到任意一个之后, 遍历的每一个节点都可能是 LCA.
* 继续直到找到 q 或 p, 如果到了根节点还未找到第2个, 则根节点是LCA.
***********************************************************/
// 返回是否停止. fl=found_level f=found_node
bool helper(TreeNode *n, int level, TreeNode *p, TreeNode *q, TreeNode **f, int *fl){
	if(!n) return false;
	if(helper(n->left, level+1, p, q, f, fl)){
		return true;
	}
	if(!*f){
		if(n->val == p->val || n->val == q->val){
			*f = n;
			*fl = level;
		}
	}else{
		if(*fl > level){
			*f = n;
			*fl = level;
		}
		if(level == 0){
			return true;
		}
		if(n->val == p->val || n->val == q->val){
			return true;
		}
	}
	return helper(n->right, level+1, p, q, f, fl);
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	TreeNode *f = NULL;
	int fl = INT_MAX;
	helper(root, 0, p, q, &f, &fl);
	return f;
}

int main(int argc, char **argv){
	TreeNode *root = build_tree({3,5,1,6,2,0,8,0,0,7,4});
	print_tree(root);
	TreeNode *n;
	
	n = lowestCommonAncestor(root, tree_find(root, 5), tree_find(root, 1));
	printf("%d\n", n->val);
	n = lowestCommonAncestor(root, tree_find(root, 5), tree_find(root, 4));
	printf("%d\n", n->val);
	
	return 0;
}

/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Given the following binary tree:  root = [3,5,1,6,2,0,8,null,null,7,4]


 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.
Example 2:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.
*/

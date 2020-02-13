#include <stdio.h>
#include <string>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 递归
***********************************************************/
bool helper(TreeNode *left, TreeNode *right){
	if(!left && !right){
		return true;
	}
	if(!left || !right){
		return false;
	}
	if(left->val != right->val){
		return false;
	}
	return helper(left->left, right->right) && helper(left->right, right->left);
}
bool isSymmetric(TreeNode* root) {
	return helper(root->left, root->right);
}

/***********************************************************
# 解题思路

* 迭代, 不用递归. 那就是广度遍历, 然后判断列表是否对称.
* 用 sep 来做层的分隔.
***********************************************************/
bool list_is_symmetric(list<TreeNode*> &q){
	if(q.size() == 0){
		return true;
	}
	auto s = q.begin();
	auto e = q.end();
	while(1){
		e --;
		if(s == e){
			return true;
		}
		
		TreeNode *n1 = *s;
		TreeNode *n2 = *e;
		if(n1 && n2){
			// s->val 并不正确! 因为 s = &T, 其实就是 &(TreeNode*), 是双重指针了.
			// (*s) 才是容器内元素的内容.
			if(n1->val != n2->val){
				return false;
			}
		}else if(!n1 && !n2){
			//
		}else if(!n1 || !n2){
			return false;
		}
		
		s ++;
		if(s == e){
			return true;
		}
	}
	return false;
}
bool isSymmetric2(TreeNode* root) {
	TreeNode *sep = new TreeNode(-1);
	list<TreeNode*> q;

	q.push_back(sep);
	q.push_back(root);
	
	while(1){
		TreeNode *node = q.front();
		q.pop_front();
		
		if(node == sep){
			if(q.empty()){
				return true;
			}
			if(!list_is_symmetric(q)){
				return false;
			}
			q.push_back(sep);
		}else{
			if(node != NULL){
				q.push_back(node->left);
				q.push_back(node->right);
			}
		}
	}
}

/***********************************************************
# 解题思路

* 每次都将需要对比的两个节点加入队列中, 一次对比两个节点, 然后继续递归.
***********************************************************/
bool isSymmetric3(TreeNode* root) {
	list<TreeNode*> q;

	q.push_back(root);
	q.push_back(root);
	
	while(!q.empty()){
		TreeNode *n1 = q.front();
		q.pop_front();
		TreeNode *n2 = q.front();
		q.pop_front();
		
		if(!n1 && !n2){
			continue;
		}
		if(!n1 || !n2){
			return false;
		}
		if(n1->val != n2->val){
			return false;
		}
		
		q.push_back(n1->left);
		q.push_back(n2->right);
		q.push_back(n1->right);
		q.push_back(n2->left);
	}
	return true;
}

int main(int argc, char **argv){
	TreeNode *root;
	root = build_tree({1,2,2,3,4,4,3});
	print_tree(root);
	printf("%d\n", isSymmetric(root));
	printf("%d\n", isSymmetric2(root));
	printf("%d\n", isSymmetric3(root));

	root = build_tree({1,2,2,0,3,0,3});
	print_tree(root);
	printf("%d\n", isSymmetric(root));
	printf("%d\n", isSymmetric2(root));
	printf("%d\n", isSymmetric3(root));

	return 0;
}

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.
*/

#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 用快慢指针二分链表, 但要保证第二个链表的长度不小于前一个.
* special case 是 3 个节点.
***********************************************************/
TreeNode* helper(ListNode *head){
	if(!head) return NULL;
	if(!head->next) return new TreeNode(head->val);
	
	ListNode *f, *s;
	s = head;
	f = head->next;
	while(f){
		f = f->next;
		if(f && f->next){
			f = f->next;
			s = s->next;
		}
	}
	
	ListNode *r = s->next;
	ListNode *second = r->next;
	s->next = NULL;
	r->next = NULL;
	
	TreeNode *root = new TreeNode(r->val);
	root->left = helper(head);
	root->right = helper(second);
	return root;
}
TreeNode* sortedListToBST(ListNode* head) {
	return helper(head);
}

/***********************************************************
# 解题思路

* 不破坏原链表结构, 而是传入链表的长度.
* 只需要开始时遍历计算长度, 后面不再需要遍历. 但需要遍历找中点. 比两
	指针少遍历一趟, 代码更简洁.
* 注意边界条件.
* special cases: 2, 3 个节点.
***********************************************************/
TreeNode* helper2(ListNode* head, int len){
	if(len == 0) return NULL;
	if(len == 1) return new TreeNode(head->val);
	ListNode *prev = head; // 中点前一个
	for(int i=1; i<len/2; i++){
		prev = prev->next;
	}
	ListNode *mid = prev->next;
	ListNode *second = mid->next;
	TreeNode *root = new TreeNode(mid->val);
	root->left = helper2(head, len/2);
	root->right = helper2(second, len-1-len/2);
	return root;
}
TreeNode* sortedListToBST2(ListNode* head) {
	int len = 0;
	ListNode *n = head;
	while(n){
		len ++;
		n = n->next;
	}
	return helper2(head, len);
}

int main(int argc, char **argv){
	print_tree(sortedListToBST(build_list("-10,-3,0,5,9")));
	print_tree(sortedListToBST(build_list("1")));
	print_tree(sortedListToBST(build_list("1,2")));
	print_tree(sortedListToBST(build_list("1,2,3")));

	print_tree(sortedListToBST2(build_list("-10,-3,0,5,9")));
	print_tree(sortedListToBST2(build_list("1")));
	print_tree(sortedListToBST2(build_list("1,2")));
	print_tree(sortedListToBST2(build_list("1,2,3")));
	return 0;
}

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5
*/

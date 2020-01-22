#include <stdio.h>
#include <string>
#include <vector>
#include "../include/list.h"

using namespace std;

ListNode* reverseList(ListNode *head, int m){
	ListNode *prev = head;
	for(int i=1; i<m; i++){
		ListNode *node = prev->next;
		prev->next = node->next;
		node->next = head;
		head = node;
	}
	return head;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *flag = dummy;
	ListNode *prev = head;

	for(int i=1; i<m; i++){
		flag = prev;
		prev = prev->next;
	}

	for(int i=m; i<n; i++){
		ListNode *node = prev->next;
		prev->next = node->next;
		node->next = flag->next;
		flag->next = node;
	}

	return dummy->next;
}

int main(int argc, char **argv){
	ListNode *node = build_list("1->2->3->4->5");
	print_list(node);
	node = reverseBetween(node, 2, 4);
	print_list(node);
	return 0;
}

/***********************************************************
# 解题思路

* 引入新的头节点, 简化处理逻辑, 应对旧的头节点发生变化的情况
* prev 用于遍历, 指向要移动的节点的前一个节点(m+1)
* flag 是插入点
***********************************************************/

/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 因为可以删除头节点, 所以引入辅助头节点 dummy
* 涉及到节点删除操作, 所以遍历指针节点指向 prev
* 简单方法是两次遍历.

* 但是要求只遍历一次, 怎么做?
* 一次遍历的方法是使用前后两个指针拉开距离 n 之后同时遍历, 但性能并没什么帮助, 只是提供了一种思路.
***********************************************************/
ListNode* removeNthFromEnd2(ListNode* head, int n) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;

	ListNode *prev = dummy;
	int size = 0;
	while(prev->next){
		size ++;
		prev = prev->next;
	}

	int idx = size - n;
	prev = dummy;
	for(int i=0; i<idx; i++){
		prev = prev->next;
	}
	prev->next = prev->next->next;

	return dummy->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;

	ListNode *prev = dummy;
	ListNode *advance = prev->next;
	for(int i=0; i<n; i++){
		advance = advance->next;
	}

	while(advance){
		advance = advance->next;
		prev = prev->next;
	}
	prev->next = prev->next->next;

	return dummy->next;
}

int main(int argc, char **argv){
	{
		ListNode *head = build_list("1->2->3->4->5");
		print_list(removeNthFromEnd(head, 2));
	}
	{
		ListNode *head = build_list("1->2->3->4->5");
		print_list(removeNthFromEnd2(head, 2));
	}
	return 0;
}

/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
*/

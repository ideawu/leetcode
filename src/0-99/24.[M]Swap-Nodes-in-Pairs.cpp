#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 因为会改变头节点, 所以引入辅助头节点
* flag 节点了插入点(插入其之后)
***********************************************************/
ListNode* swapPairs(ListNode* head) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	
	ListNode *flag = dummy;
	ListNode *curr = flag->next;
	while(curr && curr->next){
		ListNode *next = curr->next;
		curr->next = next->next;
		next->next = flag->next;
		flag->next = next;
		
		flag = curr;
		curr = flag->next;
	}
	
	return dummy->next;
}

int main(int argc, char **argv){
	ListNode *head = build_list("1->2->3->4");
	print_list(head);
	head = swapPairs(head);
	print_list(head);
	return 0;
}

/*
Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
*/

#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 先实现 reverseList(head, n, *new_head, *new_tail);
* 利用 reverseList() 来实现
* 翻转的分段要和之前的链表尾拼接起来

* 因为涉及删除(移动)操作, 所以遍历指针指向要删除的节点的前一个节点 prev
* 不引入辅助头节点, 而是在交换的时候更新 head 指针
* 注意处理最后一个分段, 如果不足时, 需要再次反转回来
***********************************************************/
void reverseList(ListNode *head, int k, ListNode **new_head, ListNode **new_tail){
	ListNode *prev = head;
	for(int i=1; i<k; i++){
		if(!prev->next){
			// reverse again with correct k
			reverseList(head, i, new_head, new_tail);
			return;
		}
		ListNode *node = prev->next;
		prev->next = node->next;
		node->next = head;
		head = node;
	}
	*new_head = head;
	*new_tail = prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
	ListNode *ret = NULL;
	ListNode *h, *t;
	h = head;
	t = NULL;
	while(1){
		ListNode *nh, *nt;
		reverseList(h, k, &nh, &nt);
		if(!ret){
			ret = nh;
		}
		if(t){
			t->next = nh;
		}
		t = nt;
		h = nt->next;
		if(!h){
			break;
		}
	}
	return ret;
}

int main(int argc, char **argv){
	{
		ListNode *head = build_list("1->2->3->4->5");
		head = reverseKGroup(head, 2);
		print_list(head);	
	}
	{
		ListNode *head = build_list("1->2->3->4->5");
		head = reverseKGroup(head, 3);
		print_list(head);	
	}
	return 0;
}


/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

Example:

Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, only nodes itself may be changed.
*/

#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 将链表对半拆开成两个链表, 反转后一个, 然后将两个链表交叉合并.
* 用快慢指针遍历找中点, 不用两趟遍历.
* 注意, 当链表数量是奇数时, 拆分后的链表数量不一, 要保证原链表比新链表多一个节点.
***********************************************************/
ListNode* reverseList(ListNode *head){
	ListNode *node = head;
	while(node->next){
		ListNode *next = node->next;
		node->next = next->next;
		next->next = head;
		head = next;
	}
	return head;
}
void reorderList(ListNode* head) {
	ListNode *slow, *fast;
	// 查找中点
	slow = head;
	fast = head;
	while(fast){
		fast = fast->next;
		if(fast){
			fast = fast->next;
			slow = slow->next;
		}
	}
	
	// 断开成两个链表, 反转第2个
	ListNode *h1 = head;
	ListNode *h2 = reverseList(slow->next);
	slow->next = NULL;
	
	// 交叉合并第2个到第1个
	while(h2){
		ListNode *n = h2->next;
		h2->next = h1->next;
		h1->next = h2;
		h1 = h1->next->next;
		h2 = n;		
	}
}

int main(int argc, char **argv){
	ListNode *head;
	head = build_list("1->2->3->4");
	reorderList(head);
	print_list(head);
	head = build_list("1->2->3->4->5");
	reorderList(head);
	print_list(head);
	return 0;
}

/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
*/

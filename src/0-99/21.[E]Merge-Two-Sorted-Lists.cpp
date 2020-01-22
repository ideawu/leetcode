#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

//Input: 1->2->4, 1->3->4

/***********************************************************
# 解题思路

* 不引入新的头节点
* 新头节点 head 指向原链表头节点较小的那一条
* node 指向最新找到的较小节点
* 两个链表谁先遍历完, node 指向另一个
***********************************************************/
ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
	ListNode *head;
	ListNode *node;

	// init
	if(l1->val < l2->val){
		head = l1;
		l1 = l1->next;
	}else{
		head = l2;
		l2 = l2->next;
	}
	node = head;

	while(1){
		if(!l1){
			node->next = l2;
			break;
		}
		if(!l2){
			node->next = l1;
			break;
		}

		if(l1->val < l2->val){
			node->next = l1;
			l1 = l1->next;
		}else{
			node->next = l2;
			l2 = l2->next;
		}
		node = node->next;
	}

	return head;
}

/***********************************************************
# 解题思路

* 引入新的头节点, 简化处理逻辑, 应对旧的头节点发生变化的情况
* 在新的头节点后面建立新链表
* node 指向新链表最后一个节点
* 将找到的较小节点添加到 node 后面
* 两个链表谁先遍历完, node 指向另一个
***********************************************************/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *dummy = new ListNode(0);
	ListNode *node = dummy;
	while(1){
		if(!l1){
			node->next = l2;
			break;
		}
		if(!l2){
			node->next = l1;
			break;
		}

		if(l1->val < l2->val){
			node->next = l1;
			l1 = l1->next;
		}else{
			node->next = l2;
			l2 = l2->next;
		}
		node = node->next;
	}
	return dummy->next;
}

int main(int argc, char **argv){
	ListNode *a = build_list("1->2->4");
	ListNode *b = build_list("1->3->4");
	ListNode *c = mergeTwoLists(a, b);
	print_list(c);
	return 0;
}

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
*/

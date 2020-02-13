#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 引入新的头节点, 简化处理逻辑, 应对旧的头节点发生变化的情况
* 为了符合题目的输出, 增加查找 flag 的操作(不做此步骤不影响逻辑正确)
* prev 用于遍历, 指向要移动的节点的前一个节点
* flag 是插入点, 指向最后一个符合条件的节点
***********************************************************/
ListNode* partition2(ListNode* head, int x) {
	ListNode *dummy = new ListNode(-INT_MAX);
	dummy->next = head;
	ListNode *flag = dummy;
	ListNode *prev = flag->next;

	// don't really need this
	while(flag->next && flag->next->val < x){
		flag = flag->next;
	}
	prev = flag->next;

	while(prev && prev->next){
		ListNode *node = prev->next;
		if(node->val < x){
			prev->next = node->next; // remove node
			node->next = flag->next; // insert 1/2
			flag->next = node;	   // insert 2/2

			flag = flag->next;
			// prev = prev->next; // next has been removed, so prev stays
		}else{
			prev = prev->next;
		}
	}

	return dummy->next;
}

ListNode* partition(ListNode* head, int x) {
	ListNode dummy(-1);
	dummy.next = head;
	ListNode *flag = &dummy;
	ListNode *prev = head;
	while(prev && prev->val < x){
		flag = prev;
		prev = prev->next;
	}
	while(prev && prev->next){
		ListNode *next = prev->next;
		if(next->val < x){
			prev->next = next->next;
			next->next = flag->next;
			flag->next = next;
			flag = flag->next;
		}else{
			prev = prev->next;
		}
	}
	return dummy.next;
}

int main(int argc, char **argv){
	ListNode *head = build_list("1->4->3->2->5->2");
	print_list(head);
	head = partition(head, 3);
	print_list(head);
	return 0;
}

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

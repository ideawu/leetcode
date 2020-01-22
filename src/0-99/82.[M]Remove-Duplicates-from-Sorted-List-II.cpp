#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

ListNode* deleteDuplicates1(ListNode* head) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *prev = dummy;
	while(prev->next){
		ListNode *curr = prev->next;
		while(curr->next && curr->next->val == prev->next->val){
			// point to last duplicated node
			curr = curr->next;
		}
		if(curr == prev->next){ // duplicated not found
			prev = curr;
		}else{
			prev->next = curr->next;
		}
	}
	return dummy->next;
}

ListNode* deleteDuplicates2(ListNode* head) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *prev = dummy;
	ListNode *node = head;
	while(node){
		bool dup = false;
		while(node->next && node->val == node->next->val){
			node->next = node->next->next;
			dup = true;
		}
		if(dup){
			prev->next = node->next;
		}else{
			prev = node;
		}
		node = node->next;
	}
	return dummy->next;
}

ListNode* deleteDuplicates(ListNode* head) {
	ListNode *dummy = new ListNode(0);
	dummy->next = head;

	ListNode *prev = dummy;
	while(prev->next){
		ListNode *curr = prev->next;
		// TODO:
	}

	return dummy->next;
}

int main(int argc, char **argv){
	ListNode *head;

	head = build_list("1->2->3->3->4->4->5");
	print_list(head);
	head = deleteDuplicates(head);
	print_list(head);

	head = build_list("1->1->1->2->3");
	print_list(head);
	head = deleteDuplicates(head);
	print_list(head);

	return 0;
}

/***********************************************************
# 解题思路

* 引入新的头节点, 简化处理逻辑, 应对旧的头节点发生变化的情况
* prev 用于遍历, 指向要删除的节点的前一个节点
***********************************************************/

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

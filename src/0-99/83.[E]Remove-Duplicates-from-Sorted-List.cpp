#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	ListNode *prev = head;
	while(prev->next){
		ListNode *node = prev->next;
		if(prev->val == node->val){
			prev->next = node->next;
		}else{
			prev = prev->next;
		}
	}
}

int main(int argc, char **argv){
	ListNode *head;

	head = build_list("1->1->2");
	print_list(head);
	head = deleteDuplicates(head);
	print_list(head);

	head = build_list("1->1->2->3->3");
	print_list(head);
	head = deleteDuplicates(head);
	print_list(head);

	return 0;
}

/***********************************************************
# 解题思路

* prev 用于遍历, 指向要删除的节点的前一个节点
* 如果有删除, prev 不移动; 否则 prev 移动到下一个节点
***********************************************************/

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

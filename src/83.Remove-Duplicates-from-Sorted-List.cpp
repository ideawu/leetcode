#include <stdio.h>
#include <string>
#include <vector>
#include "include/list.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	ListNode *node = head;
	while(node){
		while(node->next && node->val == node->next->val){
			node->next = node->next->next;
		}
		node = node->next;
	}
	return head;
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

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3
*/

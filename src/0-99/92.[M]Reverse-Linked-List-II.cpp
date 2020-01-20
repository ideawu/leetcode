#include <stdio.h>
#include <string>
#include <vector>
#include "../include/list.h"

using namespace std;

ListNode* reverseList(ListNode *head, int m){
	ListNode *node = head;
	for(int i=1; i<m; i++){
		ListNode *next = node->next;
		node->next = next->next;
		next->next = head;
		head = next;
	}
	return head;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
	ListNode *dummy = new ListNode(-1);
	dummy->next = head;
	ListNode *prev = dummy;
	ListNode *node = head;
	for(int i=1; i<m; i++){
		prev = node;
		node = node->next;
	}

	for(int i=m; i<n; i++){
		ListNode *next = node->next;
		node->next = next->next;
		next->next = prev->next;
		prev->next = next;
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

/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL
*/

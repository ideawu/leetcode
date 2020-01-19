#include <stdio.h>
#include <string>
#include <vector>
#include "include/list.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	ListNode *init = new ListNode(-1);
	init->next = head;

	ListNode *prev = init;
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

	return init->next;
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

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
*/

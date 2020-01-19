#include <stdio.h>
#include <string>
#include <vector>
#include "include/list.h"

using namespace std;

ListNode* deleteDuplicates(ListNode* head) {
	ListNode *ret = NULL;
	ListNode *prev = NULL;
	ListNode *na = head;
	while(na){
		ListNode *nb = na->next;
		if(nb && na->val == nb->val){
			do{
				nb = nb->next;
				na->next = nb;
			}while(nb && na->val == nb->val);
			if(prev){
				prev->next = nb;
			}
		}else{
			if(!ret){
				ret = na;
			}
			prev = na;
		}
		na = na->next;
	}
	return ret;
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

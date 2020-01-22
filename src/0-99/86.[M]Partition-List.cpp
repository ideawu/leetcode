#include <stdio.h>
#include <string>
#include <vector>
#include "../include/list.h"

using namespace std;

ListNode* partition(ListNode* head, int x) {
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *flag = head;
	ListNode *prev = head;
	while(prev->next){
		ListNode *node = prev->next;
		if(node->val < x){
			prev->next = node->next; // remove node
			node->next = flag->next; // insert 1/2
			flag->next = node;       // insert 2/2

			flag = flag->next;
			// prev = prev->next; // next has been removed, so prev remains
		}else{
			prev = prev->next;
		}
	}
	return dummy->next;
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

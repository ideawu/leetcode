#include <stdio.h>
#include <string>
#include <vector>
#include "../include/list.h"

using namespace std;

ListNode* partition(ListNode* head, int x) {
	ListNode *dummy = new ListNode(0);
	dummy->next = head;
	ListNode *lo = dummy;
	ListNode *p = head;
	// 不是必须
	while(p->val < x){
		lo = p;
		p = p->next;
	}
	ListNode *n = p->next;
	while(n){
		if(n->val < x){
			p->next = n->next;
			n->next = lo->next;
			lo->next = n;

			lo = lo->next;
			n = p->next;
		}else{
			p = p->next;
			n = p->next;
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

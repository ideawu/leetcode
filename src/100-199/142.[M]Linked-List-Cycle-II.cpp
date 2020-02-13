#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 见"解题要点-龟兔赛跑.md"
***********************************************************/
ListNode* detectCycle(ListNode *head) {
	if(!head) return NULL;
	
	ListNode *f = head;
	ListNode *s = head;
	while(f && f->next){
		f = f->next->next;
		s = s->next;
		if(f == s) break;
	}
	if(!f || !f->next) return NULL;
	
	s = head;
	while(f != s){
		f = f->next;
		s = s->next;
	}
	
	return f;
}

int main(int argc, char **argv){
	ListNode *h, *c;
	
	h = build_list("3,2,0,-4");
	list_tail(h)->next = list_next(h, 1);
	c = detectCycle(h);
	if(c){
		printf("%d\n", c->val);
	}else{
		printf("no cycle\n");
	}
	
	h = build_list("1,2");
	list_tail(h)->next = list_next(h, 0);
	c = detectCycle(h);
	if(c){
		printf("%d\n", c->val);
	}else{
		printf("no cycle\n");
	}
	
	h = build_list("1");
	c = detectCycle(h);
	if(c){
		printf("%d\n", c->val);
	}else{
		printf("no cycle\n");
	}
	
	return 0;
}

/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.


 

Follow-up:
Can you solve it without using extra space?
*/

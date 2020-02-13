#include <stdio.h>
#include <string>
#include <vector>
#include <list>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 环检测有一个学名叫 Floyd's Tortoise and Hare Cycle Finding Algorithm.
* 用快慢指针同时遍历, 如果能相遇即是有环.
***********************************************************/
bool hasCycle(ListNode *head) {
	if(!head) return false;
	ListNode *f = head;
	ListNode *s = head;
	while(f && f->next){
		f = f->next->next;
		s = s->next;
		if(f == s) return true;
	}
	return false;
}

int main(int argc, char **argv){
	ListNode *h;
	
	h = build_list("3,2,0,-4");
	printf("%d\n", hasCycle(h));
	list_tail(h)->next = list_next(h, 1);
	printf("%d\n", hasCycle(h));
	
	h = build_list("1,2");
	printf("%d\n", hasCycle(h));
	list_tail(h)->next = list_next(h, 0);
	printf("%d\n", hasCycle(h));

	h = build_list("1");
	printf("%d\n", hasCycle(h));
	
	return 0;
}

/*
Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Example 2:

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Example 3:

Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


 

Follow up:

Can you solve it using O(1) (i.e. constant) memory?
*/

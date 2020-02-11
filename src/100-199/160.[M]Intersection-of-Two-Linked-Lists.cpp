#include <stdio.h>
#include <string>
#include <vector>
#include "../include/all.h"

using namespace std;

/***********************************************************
# 解题思路

* 问题是求两个链表有没有共用节点, 即两个链表的尾部 n 节点相同, 类似
	于两个链表的尾节点都指向了第3个链表.
* 使用两个指针分别遍历两个链表, 到达尾部时, 换成另一个头节点继续遍历.
***********************************************************/
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
	if(!headA || !headB) return NULL;
	
	ListNode *n1, *n2;
	n1 = headA;
	n2 = headB;
	bool ex1 = false;
	bool ex2 = false;
	while(1){
		if(n1 == n2){
			return n1;
		}
		n1 = n1->next;
		n2 = n2->next;			
		if(!n1){
			if(ex1){
				return NULL;
			}
			ex1 = true;
			n1 = headB;
		}
		if(!n2){
			if(ex2){
				return NULL;
			}
			ex2 = true;
			n2 = headA;
		}
	}
}

/***********************************************************
# 解题思路

* 找出两个链表的长度, 以差值作为较长的链表的出发偏移.
* 然后两个指针按同样的速度遍历链表, 若链表相交则指针会相遇.
***********************************************************/
int list_len(ListNode *h){
	int ret = 0;
	while(h){
		h = h->next;
		ret ++;
	}
	return ret;
}
ListNode* list_advance(ListNode *h, int step){
	while(--step >= 0){
		h = h->next;
	}
	return h;
}
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
	int s1 = list_len(headA);
	int s2 = list_len(headB);
	if(s1 > s2){
		headA = list_advance(headA, s1 - s2);
	}else{
		headB = list_advance(headB, s2 - s1);
	}
	while(1){
		if(!headA || !headB) return NULL;
		if(headA == headB) return headA;
		headA = headA->next;
		headB = headB->next;
	}
}

int main(int argc, char **argv){
	ListNode *h1, *h2, *h3;
	ListNode *c;
	
	h1 = build_list("4->1");
	h2 = build_list("5->0->1");
	h3 = build_list("8->4->5");
	list_tail(h1)->next = h3;
	list_tail(h2)->next = h3;
	c = getIntersectionNode(h1, h2);
	printf("%d\n", (c? c->val : -1));
	c = getIntersectionNode2(h1, h2);
	printf("%d\n", (c? c->val : -1));
	
	h1 = build_list("0->9->1");
	h2 = build_list("3");
	h3 = build_list("2->4");
	list_tail(h1)->next = h3;
	list_tail(h2)->next = h3;
	c = getIntersectionNode(h1, h2);
	printf("%d\n", (c? c->val : -1));
	c = getIntersectionNode2(h1, h2);
	printf("%d\n", (c? c->val : -1));
	
	h1 = build_list("2->6->4");
	h2 = build_list("1->5");
	c = getIntersectionNode(h1, h2);
	printf("%d\n", (c? c->val : -1));
	c = getIntersectionNode2(h1, h2);
	printf("%d\n", (c? c->val : -1));
	
	return 0;
}

/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


begin to intersect at node c1.

 

Example 1:


Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,0,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
 

Example 2:


Input: intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Reference of the node with value = 2
Input Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect). From the head of A, it reads as [0,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
 

Example 3:


Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: null
Input Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
 

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
*/

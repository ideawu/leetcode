ListNode* partition(ListNode* head, int x) {
	ListNode *prev, *curr, *lo;
	if(found){
		prev->next = curr->next;

		curr->next = lo->next;
		lo->next = curr;
		lo = curr;
	}else{
		prev = prev->next;
	}
}

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

#include <stdio.h>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

// 1->2->3->3->4->4->5
ListNode* build_list(const string &str){
	ListNode *head = NULL;
	ListNode *prev = NULL;
	int s = 0;
	int e;
	for(int i=0; i<=str.size(); i++){
		if(i == str.size() || (str[i] == '-' && str[i+1] == '>')){
			e = i - 1;

			char buf[32];
			memcpy(buf, str.data() + s, e - s + 1);
			buf[e - s + 1] = '\0';

			// parseInt
			int n = atoi(buf);

			ListNode *node = new ListNode(n);
			if(!head){
				head = node;
			}
			if(prev){
				prev->next = node;
			}
			prev = node;

			i += 1;
			s = i + 1;
		}
	}
	return head;
}

void print_list(ListNode *head){
	while(head){
		printf("%d", head->val);
		if(head->next){
			printf("->");
		}
		head = head->next;
	}
	printf("\n");
}

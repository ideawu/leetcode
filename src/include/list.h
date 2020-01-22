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
		if(i == str.size() || str[i] == '-'){
			e = i - 1;

			// parseInt
			int n = 0;
			for(int j=s; j<=e; j++){
				if(str[j] >= '0' && str[j] <= '9'){
					n = n * 10 + str[j] - '0';
				}
			}

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

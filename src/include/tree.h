#include <stdio.h>
#include <math.h>
#include "util.h"

struct TreeNode {
	int val;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static int tree_depth(TreeNode *n){
	int d = 1;
	if(n->left){
		d = max(d, 1 + tree_depth(n->left));
	}
	if(n->right){
		d = max(d, 1 + tree_depth(n->right));
	}
	return d;
}

void tree_nodes_at_level_helper(vector<TreeNode*> *ret, TreeNode *root, int l){
	if(l < 0){
		return;
	}
	// 如果递归到了这里, 说明同级有NULL节点
	if(l == 0){
		if(root){
			ret->push_back(root);
		}else{
			ret->push_back(NULL);
		}
		return;
	}
	if(!root){
		return;
	}
	tree_nodes_at_level_helper(ret, root->left, l-1);
	tree_nodes_at_level_helper(ret, root->right, l-1);
}

vector<TreeNode*> tree_nodes_at_level(TreeNode *root, int l){
	vector<TreeNode*> ret;
	tree_nodes_at_level_helper(&ret, root, l);
	return ret;
}

static TreeNode* build_tree(vector<int> ps){
	vector<TreeNode *> nodes;
	for(int i=0; i<ps.size(); i++){
		if(ps[i] > 0){
			TreeNode *n = new TreeNode(ps[i]);
			nodes.push_back(n);
			int pid = (i-1)/2;
			TreeNode *p = nodes[pid];
			if(!p){
				printf("ERROR: NULL parent!\n");
				break;
			}
			n->parent = p;
			if(i % 2 == 0){
				p->right = n;
			}else{
				p->left = n;
			}
		}else{
			nodes.push_back(NULL);
		}
	}
	return nodes[0];
}

// 1,2,2,3,4,4,3
// static TreeNode* build_tree(string s){
// 	vector<string> ps = str_split(s, ",");
// 	vector<int> nums;
// 	for(auto p : ps){
// 		if(p.find("NULL") == string::npos && p.find("null") == string::npos){
// 			nums.push_back(atoi(p.c_str()));
// 		}else{
// 			nums.push_back(0);
// 		}
// 	}
// 	return build_tree(nums);
// }

//   01
//  /  \
// 02  03
void print_tree(TreeNode *root){
	int depth = tree_depth(root);
	int cell_width = 2;
	int max_level = depth - 1;
	for(int level=0; level<=max_level; level++){
		// int num = pow(2, level) * 2 - 1;
		int span = pow(2, max_level - level) * 2 - 1; // -1: 分隔符比跨越的元素个数少1
		int indent = pow(2, max_level - level - 1) * 2 - 1; // next_span
		
		printf("[");
		printf("%s", str_repeat(" ", indent*cell_width).c_str());
		vector<TreeNode*> nodes = tree_nodes_at_level(root, level);
		for(int j=0; j<nodes.size(); j++){
			if(j > 0){
				printf("%s", str_repeat(" ", span*cell_width).c_str());
			}
			TreeNode *node = nodes[j];
			if(node == NULL){
				printf("%*s", cell_width, "*");
			}else{
				printf("%0*d", cell_width, node->val);
			}
		}
		printf("%s", str_repeat(" ", indent*cell_width).c_str());
		printf("]\n");
		
		if(level < max_level){
			int next_span = pow(2, max_level - level) - 1;
			int next_indent = pow(2, max_level - level - 1) - 1;
			
			int idn = indent - 1;
			int gap = 1;
			
			while(idn >= next_indent){
				int spn = span - (gap*2-1) - 1; // -1: '\'; -1: middle

				printf("[");
				printf("%s", str_repeat(" ", idn*cell_width).c_str());
				for(int j=0; j<nodes.size(); j++){
					if(j > 0){
						printf("%s", str_repeat(" ", spn*cell_width).c_str());
					}
					printf("%*s", cell_width, "/");
					printf("%s", str_repeat(" ", (gap*2-1)*cell_width).c_str());
					printf("%-*s", cell_width, "\\");
				}
				printf("%s", str_repeat(" ", idn*cell_width).c_str());
				printf("]\n");
				// idn -= (max_level - level + 1)/2;
				// gap += (max_level - level + 1)/2;
				idn -= 1;
				gap += 1;
				break;
			}
		}
	}
}

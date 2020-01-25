#include <vector>

void print_array(const std::vector<int> &nums, int count=INT_MAX){
	printf("[");
	for(int i=0; i<count && i < nums.size(); i++){
		int n = nums[i];
		if(i == 0){
			printf("%d", n);
		}else{
			printf(", %d", n);	
		}
	}
	printf("]\n");
}

static void print_matrix(vector<vector<int>> &matrix){
	for(auto &row : matrix){
		for(auto &e : row){
			printf("%2d ", e);
		}
		printf("\n");
	}
}

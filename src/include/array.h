#include <vector>

static void print_array(const std::vector<int> &nums, int count=INT_MAX){
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

static void print_matrix(const vector<vector<int>> &matrix, string s="", string e=""){
	int width = 2;
	for(auto row : matrix){
		for(auto e : row){
			if(e != 0){
				double f = log10(fabs(e)) + 2;
				if(e < 0){
					f += 1;
				}
				width = std::max(width, (int)f);
			}
		}
	}
	
	if(!s.empty()){
		printf("%s\n", s.c_str());
	}
	for(int i=0; i<matrix.size(); i++){
		auto &row = matrix[i];
		if(!s.empty()){
			printf("    %s", s.c_str());
		}
		for(int j=0; j<row.size(); j++){
			auto &e = row[j];
			if(!s.empty() && j > 0){
				printf(", ");
			}
			if(!s.empty()){
				printf("%d", e);
			}else{
				printf("%*d", width, e);
			}
		}
		if(!e.empty()){
			printf("%s", e.c_str());
			if(i < matrix.size() - 1){
				printf(",");
			}
		}
		printf("\n");
	}
	if(!e.empty()){
		printf("%s\n", e.c_str());
	}else{
		printf("\n");
	}
}

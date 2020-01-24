#include <vector>

void print_array(const std::vector<int> &nums){
	for(auto n : nums){
		printf("%d ", n);
	}
	printf("\n");
}

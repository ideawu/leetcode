#include <stdio.h>
#include <vector>

/*
   Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

Example:

Input: [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2.
    Jump 1 step from index 0 to 1, then 3 steps to the last index.
Note:

You can assume that you can always reach the last index.


 * We use "last" to keep track of the maximum distance that has been reached
 * by using the minimum steps "ret", whereas "curr" is the maximum distance
 * that can be reached by using "ret+1" steps. Thus,
 * curr = max(i+A[i]) where 0 <= i <= last.
class Solution {
public:
    int jump(int A[], int n) {
        int ret = 0;
        int last = 0;
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            if (i > last) {
                last = curr;
                ++ret;
            }
            curr = max(curr, i+A[i]);
        }

        return ret;
    }
};
*/

int jump(const std::vector<int> &nums, int num, int idx){
	if(idx == nums.size() - 1){
		return 0;
	}
	if(num == 0){
		return INT_MAX/2;
	}
	int j1 = jump(nums, num-1, idx+1);
	if(j1 == 0){
		return 1;
	}
	int j2 = jump(nums, nums[idx+1], idx+1) + 1;
	return j1<j2? j1 : j2;
}


int main(int argc, char **argv){
	std::vector<int> nums;

	nums.clear();
	nums.push_back(4);
	printf("%d\n", jump(nums, nums[0], 0));

	nums.clear();
	nums.push_back(0);
	printf("%d\n", jump(nums, nums[0], 0));

	nums.clear();
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(1);
	nums.push_back(1);
	nums.push_back(4);
	printf("%d\n", jump(nums, nums[0], 0));

	nums.clear();
	nums.push_back(3);
	nums.push_back(2);
	nums.push_back(1);
	nums.push_back(0);
	nums.push_back(4);
	printf("%d\n", jump(nums, nums[0], 0));

	// nums not empty
	return 0;
}


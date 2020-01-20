#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	int i = m - 1;
	int j = n - 1;
	int r = nums1.size() - 1;
	while(1){
		if(nums1[i] > nums2[j]){
			nums1[r--] = nums1[i--];
		}else{
			nums1[r--] = nums2[j--];
		}

		if(i < 0){
			while(j >= 0){
				nums1[r--] = nums2[j--];
			}
			break;
		}
		if(j < 0){
			break;
		}
	}
}

int main(int argc, char **argv){
	vector<int> nums1, nums2;
	int m, n;
	nums1 = {1,2,3,0,0,0};
	nums2 = {2,5,6};
	m = 3;
	n = 3;
	merge(nums1, m, nums2, n);
	for(auto n : nums1){
		printf("%d ", n);
	}
	printf("\n");
	return 0;
}

/*
88. Merge Sorted Array
[EASY]

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

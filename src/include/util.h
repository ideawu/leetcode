#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <vector>

using namespace std;

static inline double microtime(){
	struct timeval now;
	gettimeofday(&now, NULL);
	double ret = now.tv_sec + now.tv_usec/1000.0/1000.0;
	return ret;
}

static void print_matrix(vector<vector<int>> &matrix){
	for(auto &row : matrix){
		for(auto &e : row){
			printf("%2d ", e);
		}
		printf("\n");
	}
}
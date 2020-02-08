#include <sstream>
#include <string.h>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <unordered_map>

using namespace std;

bool cmp(int a, int b){
	printf("cmp %d %d\n", a, b);
	return a < b;
}

struct clzcmp{
	bool operator()(const int &a, const int &b) const {
		printf("clzcmp %d %d\n", a, b);
		return a < b;
	}
};

int main(int argc, char **argv){
	//set<int, bool(*)(int,int)> s1(cmp);
	set<int, decltype(&cmp)> s1(cmp);
	s1.insert(1);
	s1.insert(2);

	set<int, clzcmp> s2;
	s2.insert(1);
	s2.insert(2);

	// C++98 要求 > > 之间有空格...
	set<int, std::less<int>> s3;
	s3.insert(1);
	s3.insert(2);

	/*
	set<int> s5(clzcmp);
	s4.insert(1); // 如果没有这一行, 编译正常!
	*/

	return 0;
}


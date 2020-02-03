#include <sstream>

using namespace std;

int main(int argc, char **argv){
	stringstream ss("10\n1  2\n3 a4\n0 1");
	string line;
	//while(ss.getline(char *)){
	while(std::getline(ss, line)){
		printf("%s\n", line.c_str());
		stringstream s2(line);
		int a;
		while(s2 >> a){
			printf(" > %d\n", a);
		}
	}
	return 0;
}


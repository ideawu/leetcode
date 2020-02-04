#include <sstream>

using namespace std;

int main(int argc, char **argv){
	stringstream ss("10\n1  2\n3 a4\n0 1");
	string line;
	//while(ss.getline(char *)){
	while(std::getline(ss, line, '\n')){
		printf("%s\n", line.c_str());
		stringstream s2(line);
		int a;
		while(s2 >> a){
			printf(" > %d\n", a);
		}
	}
	
	char str[] = "a b - c   w";
	const char *delimeter = " -";
	char *tok = strtok(str, delimeter);
	while(tok){
		printf("[%s]\n", tok);
		tok = strtok(NULL, delimeter);
	}
	printf("%s\n", str);
	
	return 0;
}


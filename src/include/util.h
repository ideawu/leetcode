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

static double _stime = 0;
static double _etime = 0;
void runtime(){
	_etime = microtime();
	if(_stime == 0){
		//
	}else{
		printf("time elapse: %.6f\n", _etime - _stime);
	}
	_stime = _etime;
}

vector<string> str_split(string src, string sep){
	vector<string> ret;
	int s = 0;
	while(1){
		int e = src.find(sep, s);
		if(e == string::npos){
			e = src.size();
		}
		string p = src.substr(s, src.size() - s);
		ret.push_back(p);
		
		s = e + sep.size();
		if(e > src.size()){
			break;
		}
	}
	return ret;
}

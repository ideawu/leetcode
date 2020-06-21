#ifndef _LEETCODE_UTIL_
#define _LEETCODE_UTIL_

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
static void runtime(){
	_etime = microtime();
	if(_stime == 0){
		//
	}else{
		printf("time elapse: %.6f\n", _etime - _stime);
	}
	_stime = _etime;
}

static std::vector<std::string> str_split(const std::string &src, const std::string &sep){
	std::vector<std::string> ret;
	int s = 0;
	while(s <= src.size()){
        if(s == src.size()){
            ret.push_back("");
            break;
        }
        
		int e = src.find(sep, s);
		if(e == std::string::npos){
			e = src.size();
		}
		std::string p = src.substr(s, e - s);
		ret.push_back(p);
		
		s = e + 1;
	}
	return ret;
}

string str_repeat(string s, int n){
	string ret;
	while(n-- > 0){
		ret.append(s);
	}
	return ret;
}

#endif

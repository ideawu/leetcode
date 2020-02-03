#include <sys/time.h>
#include <unistd.h>

#define LOG_BUF_LEN		4096

#define LOG(fmt, args...)	\
	log_write("%s(%d): " fmt, basename(__FILE__), __LINE__, ##args)

const char* basename(const char *s){
	const char *p = s + strlen(s) - 1;
	while(p >= s && *p != '/'){
		p--;
	}
	return p+1;
}

int logv(const char *fmt, va_list ap);

int log_write(const char *fmt, ...){
	va_list ap;
	va_start(ap, fmt);
	int ret = logv(fmt, ap);
	va_end(ap);
	return ret;
}

int logv(const char *fmt, va_list ap){
	char buf[LOG_BUF_LEN];
	int len;
	char *ptr = buf;

	time_t time;
	struct timeval tv;
	struct tm *tm, tm_tmp;
	gettimeofday(&tv, NULL);
	time = tv.tv_sec;
	tm = localtime_r(&time, &tm_tmp);
	/* %3ld 在数值位数超过3位的时候不起作用, 所以这里转成int */
	len = sprintf(ptr, "%04d-%02d-%02d %02d:%02d:%02d.%03d ",
		tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday,
		tm->tm_hour, tm->tm_min, tm->tm_sec, (int)(tv.tv_usec/1000));
	if(len < 0){
		return -1;
	}
	ptr += len;

	int space = sizeof(buf) - (ptr - buf) - 10;
	len = vsnprintf(ptr, space, fmt, ap);
	if(len < 0){
		return -1;
	}
	ptr += len > space? space : len;
	*ptr++ = '\n';
	*ptr = '\0';

	len = ptr - buf;
	write(STDOUT_FILENO, buf, len);

	return len;
}

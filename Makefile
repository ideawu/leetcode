# 支持 make [num] 自动找到对应文件编译
# 例如 make 81

%:
	echo $(shell find src | grep "/$@\.")
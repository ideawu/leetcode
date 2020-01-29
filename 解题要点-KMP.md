# 解题要点-KMP

## 直观 substr

不考虑边界

	for(int i=0; i<=haystack; i++){
		for(int j=0; j<=needle.size(); j++){
			if(j == needle.size()){
				return i;
			}
			if(haystack[i+j] != needle[i+j]){
				break;
			}
		}
	}

这个算法的缺点是 i 每次只增加 1, 而 j 总是从 0 开始. 能否 i 每一次增加更多的距离, 而 j 能否从大数开始呢?

KMP 方法不能同时达到这两个方向的最优, i 增加得越快, j 就越接近 0.

## Longest Prefix Suffix

如果已经匹配了 j 个字符:

	haystack.substr(i, j) == needle.substr(0, j);

但第 j 个字符不匹配:

	haystack.substr(i, j+1) != needle.substr(0, j+1);

那么我们关心的是:

	haystack.substr(i+1, j-1) ?= needle.substr(0, j-1);
	haystack.substr(i+m, j-m) ?= needle.substr(0, j-m);

也即

	needle.substr(1, j-1) ?= needle.substr(0, j-1)
	needle.substr(m, j-m) ?= needle.substr(0, j-m)

**这个转换非常重要.** 因为这其实是 needle 在和自己匹配(prefix 是否等于 suffix), 而不是和 haystack 在匹配. 这样就可以预先建立 lps[] 表(pattern).

	abc...abc

如果 prefix 完全不等于 suffix, 那么就可以从不匹配点开始从头匹配, 即 `i+=j`, 而不是 `i+=1`. 如果两者匹配的长度越长, 那么 i 能一次跳过的的距离就越短(同时 j 的初始值就越接近 needle 长度).

所以, 建立 lps 的过程, 就是对 needle 的每一个 substr(0, x), 计算 prefix=suffix 的最大长度.

## KMP

建立了 lps 表之后, 当每遇到不匹配的情况时, 就查询 lps 表, 确定 i 要跳过多少步, 而 j 要从哪开始.

**心智负担** KMP 算法 i 的速度(源文本的遍历速度)越快, 匹配进度就要越清空, 效果相反. 你可能跟我一样, 认为匹配进度被清空, 是拖慢了匹配速度. 但直观的方法, 不仅 i 的速度慢, 而且匹配进度都一次都被清空!


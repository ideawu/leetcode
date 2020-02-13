#!/bin/sh
for i in `find src | grep '\.cpp$'`
do
	#sed '/{/,/}/s/    /	/' "$i"
	sed -i "" '/{/,/}/s/    /	/' "$i"
done


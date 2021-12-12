.ONESHELL:
SHELL := /bin/sh
.SILENT:
.PHONY: \
        compile-all

define compile_all_tasks = 
for dir in ./src/*/
do 
	for src in ${dir}*.cpp
		do 
			g++ -std=c++11 -O2 -Wall ${src} -o ${src%.*}.o
		done
done
endef

DEFAULT_GOAL := compile-all
compile-all:
	$(value compile_all_tasks)

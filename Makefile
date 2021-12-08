.SILENT:
.PHONY: \
        compile \
        run

compile:
	g++ -std=c++11 -O2 -Wall $$SRCPATH/main.cpp -o $$SRCPATH/main.o

run:
	$$SRCPATH/main.o $(shell pwd)/$$SRCPATH/$$INPUT_FILE
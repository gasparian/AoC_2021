## Advent Of Code 2021  

https://adventofcode.com/2021  

List of my "unpolished" solutions.  

GNU C++11  

Run `make` to compile all the tasks one by one. Binaries would be stored alongside with source code with the `*.{o|out}` ext.  
To run compiled program, navigate to the corresponding folder and execute binary (it will read needed input file from the same folder you are in):  
```
cd ./src/day_1_sonar_sweep && ./part_1.o
```  

Or compile manually, after navigating to the task folder:  
```
g++ -std=c++11 -O2 -Wall part_1.cpp -o part_1.o
```  

# CppTutorials

g++ -c option will compile the implementation file (IterationFor.cpp) and generate the object file .o
g++ main application file with object file to generate the executable file.
Execute the application


D:\HrishikeshSir\C++Programming\CalculatorTutorial\IterationWhile>g++ -c IterationFor.cpp -o IterationFor.o

D:\HrishikeshSir\C++Programming\CalculatorTutorial\IterationWhile>g++ IterationWhile.cpp IterationFor.o -o d.exe

D:\HrishikeshSir\C++Programming\CalculatorTutorial\IterationWhile>d.exe

Laundary Item List
1 : a1
2 : b2
3 : c3
4 : d4
5 : e5
6 : f6
7 : g7
8 : h8
9 : i9
10 : j10

Please enter the input from 1 to 10 only.
Please enter a number : 3

D:\HrishikeshSir\C++Programming\CalculatorTutorial\IterationWhile>

Observation : Visual Studio will execute the program even though
header file are not included. we got error sqrt was not declared 
in scope when trying to run same code from command prompt (MinGW).
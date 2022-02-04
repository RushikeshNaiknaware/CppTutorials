#include "IterationFor.h"

void whyForLoop() {
	constexpr int LIMIT{ 10 };
	int icounter{ 1 };	// initialize
	while (icounter <= LIMIT) {		// conditional statement
		std::cout << "Value : " << icounter << std::endl;
		++icounter;		// re-evaluate the loop control variable.
	}
	std::cout << "icounter value : " << icounter << std::endl;
	//Rule : Do not keep the variable in the memory for 
	// a longer time than it is required
	
	//Since icounter we will not use outside while loop
	//its better to use for loop.
	
	for (int icountx{ 1 }; icountx <= LIMIT; ++icountx) {
		std::cout << "Value : " << icountx << std::endl;
	}
	// icountx: loop control variable.
	// ++icountx: re-evaluation parameter.
	// int icountx{ 12 }; inside for loop Ill definded for loop if initial condition 
	// does not satisfy test. Loop body will not executed.

	//Error : icountx : undeclared identifier
	//std::cout << "icountx value : " << icountx << std::endl;
}

// Print integers in the range of 1..10 in descending order
void descForLoop() {
	constexpr int UPPER_LIMIT{ 10 };
	constexpr int LOWER_LIMIT{ 1  };
	std::cout << "Integers in the range of 1..10 in descending order" << endl;
	for (int icounter{ UPPER_LIMIT }; icounter >= LOWER_LIMIT; --icounter) {
		std::cout << "Value : " << icounter << std::endl;
	}
	
	// Any non zero value in C++ represents true
	// and only zero represents false.
	// Value of variable will act as results of expression.

	for (int icounter{ 10 }; icounter; --icounter) {
		std::cout << "Value : " << icounter << std::endl;
	}
}

// Print all odd integers in range 1 to n
void oddNumberRange() {
	int limit{};
	std::cout << "Please enter the integer : ";
	std::cin >> limit;

	for (int odd{ 1 }; odd <= limit; odd+=2) {
		std::cout << odd << "\n";
	}
	std::cout << std::endl;
}

// Print all odd integers in range 1 to n in descending order
void oddNumberRangeDesc() {
	int inum{};
	std::cout << "Please enter the integer : ";
	std::cin >> inum;

	inum = (inum % 2 == 0) ? (inum - 1) : inum;

	/* 
	*	Initialize counter of for loop may not have any expression
	*	Reevaluation parameter may also not have any expression
	*   Conditional test is optional
	*/
	for (; ; ) {
		std::cout << inum << "\n";
		inum -= 2;
		if (inum < 1) {
			break;
		}
	}
	std::cout << std::endl;
}
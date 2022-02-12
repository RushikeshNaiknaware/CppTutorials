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

// Guess the output of the below code.
void guessOutput() {
	int inum{};
	for (inum = 1 ; inum <= 5; inum++);
	{
		std::cout << inum << std::endl;
	}
}

// Accept an integer n and print all even numbers less than n.
void printEvenNumbersLessThanN() {
	int inum{};
	std::cout << "Please enter the positive integers : ";
	std::cin >> inum;
	
	for (int even{ 2 }; even < inum; even += 2 ) {
		std::cout << even << std::endl;
	}
}

// Accept an integer n and print first n even numbers.
void printFirstNEvenNumbers() {
	int inum{};
	std::cout << "Please enter the positive integers : ";
	std::cin >> inum;
	int even{ 2 };
	for (int i{ 1 }; i <= inum; ++i) {
		std::cout << even << std::endl;
		even += 2;
	}
}

// Get the Positive integer with validation. Input like 3n7 fails consider only 3 as input and remaining n7 is left into stream.
// Solution : Always remember user enters input from keyboard/files, developer reads input from stream consider input as character streams
// then perform necessary conversions to appropriate data type before using it. (stoi, stos)
int get_positive_integer() {
	int number{};
	do {
		std::cout << "Please enter a number : ";
		std::cin >> number;
		if ( std::cin.fail() ) {
			std::cout << "\n\tInvalid input, Please enter a number.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(),'\n');
		}
		else {
			if (number < 0) {
				std::cout << "Please enter the positive number only.\n";
			}
			else {
				//std::cout << number;
				break;
			}
		}
	} while (true);
	return number;
}

// Get positive integer with validation and user defined messages.
int get_positive_integer(std::string message) {
	int number{};
	do {
		std::cout << message;
		std::cin >> number; 

		if (std::cin.fail()) {
			std::cout << "\n\tInvalid input, "<< message << " .\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else {
			if (number < 0) {
				std::cout << "Please enter the positive number only.\n";
			}
			else {
				//std::cout << number;
				break;
			}		
		}
	} while (true);
	return number;
}

// Divides the number1 by number2 and returns the result.
float divide(int number1, int number2) {
	//formal arguments/parameters number1 and number2 receives the values.
	return static_cast<float> ( number1 ) / number2 ;
}

char getAlphabet() {	
	char alpha{};
	while (true) {
		std::cout << "Please enter the alphabet : \n";
		std::cin >> alpha;

		if (std::cin.fail()) {
			std::cerr << "\nInvalid input entered, Please enter the valid alphabet. \n";
			cin.clear();
			cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		else {
			if (isalpha(alpha)) {
				return alpha;
			}
			else {
				std::cerr << "\nCharacter entered is not a alphabet, Please enter only alphabets. \n";
				cin.clear();
				cin.ignore(std::numeric_limits<int>::max(), '\n');
			}
		}
	}
}

//Menu card contains only 10 items, if user enters digit more than 10 we should exit with error messsage.
int exitDemo() {
	std::cout << "\nLaundary Item List\n";
	constexpr int NUMBER_OF_ITEMS_LIST = 10;
	std::array< std::string, NUMBER_OF_ITEMS_LIST > laudaryItems = { "a1", "b2","c3","d4", "e5", "f6", "g7", "h8", "i9", "j10" };

	for (int item{ 0 }; item < NUMBER_OF_ITEMS_LIST; ++item) {
		std::cout << (item + 1) << " : " << laudaryItems.at(item) << "\n";
	}

	std::cout << "\nPlease enter the input from 1 to " << NUMBER_OF_ITEMS_LIST << " only.\n";
	auto input = get_positive_integer();
	if (input > NUMBER_OF_ITEMS_LIST) {
		std::cerr << "Error : Invalid input entered, allowed range is from 1 to " << NUMBER_OF_ITEMS_LIST << " only." << std::endl;
		exit(EXIT_FAILURE);
	}
	return 0;
}

void starPattern(const int inumber) {
	for (int rowno = 1; rowno <= inumber; ++rowno ) {
		for (int star = 1; star <= rowno; ++star ) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void starPattern2(const int inumber) {
/*
	for ( int rowno = 1; rowno <= inumber; ++rowno ) {
		for (int star = 1; star <= inumber - (rowno - 1); ++star ) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
*/
	for (int rowno = inumber; rowno; --rowno ) {
		for (int star = 1; star <= rowno; ++star) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}

void starPattern3(const int inumber) {
	for (int rowno = inumber; rowno; --rowno) {
		for (int space = 1; space <= inumber - rowno; ++space ) {
			std::cout << " ";
		}
		for (int star = 1; star <= rowno + (rowno - 1); ++star) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}

void starPattern4(const int inumber) {
	for (int rowno = 1; rowno <= inumber; ++rowno) {
		for (int space = 1; space <= inumber - rowno; ++space) {
			std::cout << " ";
		}
		for (int star = 1; star <= rowno; ++star) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
	std::cout << std::endl;
}
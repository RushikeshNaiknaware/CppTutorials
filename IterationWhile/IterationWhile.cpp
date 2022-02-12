// IterationWhile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "IterationFor.h"
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
#include <cmath>
using std::cout;
using std::endl;
using std::cin;

int globalVariable1;
int globalVariable2{ 10 };


//Accept name of student and display it 5 times.
void displayNames() {
    std::string name;
    cout << "Please enter the name of the Student : ";
    cin >> name;

    constexpr int LIMIT = 5;
    int counter = 1;
    while (counter <= LIMIT) {
        cout << "Hello " << name << endl;
        counter = counter + 1;
    }
}

//Please accept the number and display its factors
void displayFactors() {
    int iln{};
    cout << "Please enter the +ve integer : ";
    cin >> iln;
    int icounter{ 1 };
    while (icounter <= iln) {
        if ( iln % icounter == 0 ){
            cout << icounter << " is the factor of number " << iln << "\n";
        }        
        ++icounter;
        //cout << "++icounter: " << icounter << "\t";
    }
}
void displayFactorsTwicePerformance() {
    int inumber{};
    cout << "Please enter the +ve integer : ";
    cin >> inumber;
    int icounter{ 1 };
    while (icounter <= (inumber/2)) {
        if (inumber % icounter == 0) {
            cout << icounter << " is the factor of number " << inumber << "\n";
        }
        ++icounter;
        //cout << "++icounter: " << icounter << "\t";
    }
    cout << inumber << " is the factor of number " << inumber << "\n";
}
//Please accept the number and display if prime or not.
void checkPrimeOrNot(int inumber = 0) {
    if (!inumber) {
        cout << "Please enter the +ve integer : ";
        cin >> inumber;
    }
    if (inumber <= 1) {
        cout << inumber << " is not a prime number." << "\n";
        return;
    }
    int icounter{ 2 };
    bool foundFactor = false;
    while (icounter <= (sqrt(inumber))) {
        if (inumber % icounter == 0) {
            foundFactor = true;
            break;
        }
        ++icounter;
    }
    if (foundFactor == false) {
        cout << inumber << " is a prime number." << "\n";
    }
    else {
        cout << inumber << " is not a prime number." << "\n";
    }
    return;
}

bool isPrime(int inumber) {
    if (inumber <= 1) {
        return false;
    }
    int icounter{ 2 };
    bool foundFactor = false;
    while (icounter <= (sqrt(inumber))) {
        if (inumber % icounter == 0) {
            foundFactor = true;
            break;
        }
        ++icounter;
    }
    // if no factors are found which divides the number then it is prime number.
    if ( foundFactor == false) {
        return true;
    }   
    return false;
}

//Display all prime numbers between 1 to n
void allPrimeNumbers(int givenNumber) {
    for (int i{ 1 }; i <= givenNumber; ++i) {
        if (isPrime(i)) { std::cout << i << "\t\t "; }
    }
}

void cronoTimeDemo() {
    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    std::cout << "printing out 1000 stars...\n";
    for (int i{ 1 }; i <= 1000; ++i)
    {
        std::cout << "*";
    }
    std::cout << std::endl;
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;
}

void scopeOfVariables() {    
    // life time of local variables are only inside the local scope where they are defined.    
    //int localVariable;
    //std::cout << "local variables are by default assigned garbage value : " << localVariable << std::endl;
    std::cout << "global variables are by default assigned 0 value      : " << globalVariable1 << std::endl;
    std::cout << "global variable 1 : " << globalVariable1 << ", global variable 2 : " << globalVariable2 << std::endl;
}

void accessibilityOfVariables() {
    // global variable are accessible across the program, except for the function which defines it.
    // for some reason I want to use both the local variable with name globalVariable2 and global variable.
    int globalVariable2{ 5 };
    std::cout << "global variable 1 : " << globalVariable1 << ", global variable 2 : " << globalVariable2 << std::endl;
    std::cout << "global variable 1 : " << globalVariable1 << ", global variable 2 : " << ::globalVariable2 << std::endl;
}

void divideDemo()
{
    using namespace std::literals;
    std::string message = "Please enter the numerator : "s;
    int numerator = get_positive_integer(message);          // message : actual argument passed to function.
    std::cout << "numerator : " << numerator << "\n";

    int denominator = get_positive_integer("Please enter the denominator : "s);
    std::cout << "denominator : " << denominator << "\n";   

    float result = divide(numerator, denominator);      // numerator, denominator : actual argument passed to function.
    std::cout << numerator << " / " << denominator << " = " << result << std::endl;
}

void inlineDemo() {
    // define a function inline is just the suggestion to the compiler to replace the function call with its code.
    std::cout << "alphabet is : " << getAlphabet() << std::endl;
}

int main(void)
{
	//displayNames();
    //displayFactors();
    //displayFactorsTwicePerformance();
    //checkPrimeOrNot();
    
    //allPrimeNumbers(1000);
    //cronotimedemo();
    
    //whyForLoop();
    //descForLoop();
    //oddNumberRange();
    //oddNumberRangeDesc();
    //guessOutput();
    //printEvenNumbersLessThanN();
    //printFirstNEvenNumbers();
    //get_positive_integer();    
    //exitDemo();

    //TODO: Unit testing above code for { +ve, -ve, 0 } numbers, fractions, decimal numbers.
    //TODO: if user entered number which is out of integer range it will result in loss of data.
    //constexpr int NUM_OF_ROWS = 10;
    //starPattern(NUM_OF_ROWS);
    //starPattern2(NUM_OF_ROWS);
    //starPattern3(NUM_OF_ROWS);
    //starPattern4(NUM_OF_ROWS);
   
    //divideDemo();
    //scopeOfVariables();
    //accessibilityOfVariables();

    inlineDemo();


    return EXIT_SUCCESS;
}
// IterationWhile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
using std::cout;
using std::endl;
using std::cin;
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

int main()
{
	//displayNames();
    //displayFactors();
    //displayFactorsTwicePerformance();
    checkPrimeOrNot();

    
    for (int i{ 1 }; i <= 1000; ++i) {
       checkPrimeOrNot(i);
    }

    using namespace std::chrono;
    steady_clock::time_point t1 = steady_clock::now();
    std::cout << "printing out 1000 stars...\n";
    for (int i{ 1 }; i <= 1000; ++i)
    { std::cout << "*"; }
    std::cout << std::endl;
    steady_clock::time_point t2 = steady_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);

    std::cout << "It took me " << time_span.count() << " seconds.";
    std::cout << std::endl;

    //TODO: Unit testing above code for { +ve, -ve, 0 } numbers, fractions, decimal numbers.
}
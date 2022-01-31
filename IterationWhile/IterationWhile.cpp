// IterationWhile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
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
            cout << "\n";
            cout << icounter << " is the factor of number " << iln << "\n";
        }        
        ++icounter;
        //cout << "++icounter: " << icounter << "\t";
    }
}
void displayFactorsTwicePerformance() {
    int iln{};
    cout << "Please enter the +ve integer : ";
    cin >> iln;
    int icounter{ 1 };
    while (icounter <= (iln/2)) {
        if (iln % icounter == 0) {
            cout << "\n";
            cout << icounter << " is the factor of number " << iln << "\n";
        }
        ++icounter;
        //cout << "++icounter: " << icounter << "\t";
    }
    cout << iln << " is the factor of number " << iln << "\n";
}

int main()
{
	//displayNames();
    //displayFactors();
    displayFactorsTwicePerformance();
}
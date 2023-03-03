// Casino.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Casino.h"
#include <iostream>
using namespace std;
int main()
{
    const int size = 2;
    Casino casion("Lucky 7's Palace");
    Customer customers[size] = {Customer("Yura", 3000), Customer("Oleg", 2000)};


    casion.showResults(customers,1,size);
    


    casion.startGame(customers,1,size);
    casion.showResults(customers,1,size);

    casion.startGame(customers,2,size);
    casion.showResults(customers,2,size);

    Casino casion1("Royal Flush Casino");
    Customer customers1[size] = {Customer("Tamara", 5000), Customer("Bogdan", 8000)};

    casion1.startGame(customers1,1,size);
    casion1.showResults(customers1,1,size);

    casion1.startGame(customers1,2,size);
    casion1.showResults(customers1,2,size);



    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files
//   to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

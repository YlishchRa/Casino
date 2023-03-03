#pragma once
#include "Customer.h"

 
class Casino
{
    double balance_;
    int* number_;
    int table;
    const double winningRatio = 1.5;

public:
    Casino();

    int spinWheel();

    void startGame(Customer* cst, int table, int players);
    void showResults(Customer* cst, int table, int player);
};

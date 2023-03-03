#pragma once
#include "Customer.h"

 
class Casino
{
    std::string casinoName;
    int countTable;
    double balance_;
    int* number_;
    int table;
    const double winningRatio = 1.5;
   

public:
    Casino(std::string _name);

    int spinWheel();

    void startGame(Customer* cst, int table, int players);
    void showResults(Customer* cst, int table, int player);
};

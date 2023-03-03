#pragma once

#include <iostream>
class Customer
{
    double balance_;
    std::string name_;
    int number_;
    int rate_;
    bool win;

public:
    Customer();
    Customer(std::string name);
    Customer(std::string name, int money);



    void chooseNumber();
    void replenishBalance(int money);
    void massageAboutWin();
    void showDataAboutCustomer();
    int getNumber();
    void setRate();
    int getRate();
    void setWin(bool _win);
    
};

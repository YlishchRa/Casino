#include "Customer.h"

Customer::Customer() : win{0}, rate_{0} {}

Customer::Customer(std::string name) : win{0}, rate_{0}
{
    name_ = name;
}

Customer::Customer(std::string name, int money) : win{0}, rate_{0}
{
    name_ = name;
    balance_ = money;
}

void Customer::chooseNumber()
{
    std::cout << name_ << " Choose a number(0 - 100): ";
    std::cin >> number_;
}

void Customer::replenishBalance(int money)
{
    balance_ += money;
}

void Customer::massageAboutWin()
{
    if (win)
        std::cout << name_ << " won \n\n";
    else
        std::cout << name_ << " lost \n\n";
}

void Customer::showDataAboutCustomer()
{
    std::cout << "Name: " << name_ << "\n"
              << "Balance: " << balance_ << "\n"
              << "Number: " << number_ << "\n";
    this->massageAboutWin();
}

int Customer::getNumber()
{
    return number_;
}

void Customer::setRate()
{
    
    std::cout << name_ << " Your balance: " << balance_ << "\nPlease place a rate(min rate: 40): "; 

    std::cin >> rate_;
    if(rate_ > balance_)
        std::cout << "You don`t have so much money. You will skip this game\n";
}

int Customer::getRate()
{
    return rate_;
}

void Customer::setWin(bool _win)
{
    win = _win;
}

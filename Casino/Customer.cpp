#include "Customer.h"

Customer::Customer() :  name_{"No name"}, win{0}, rate_{0}, balance_{0}, number_{int(-1)}{}

Customer::Customer(std::string name) : name_{name}, win{0}, rate_{0}, balance_{0}, number_{int(-1)} {}

Customer::Customer(std::string name, double money) : name_{name}, win{0}, rate_{0}, balance_{money}, number_{-1} {}

void Customer::chooseNumber()  
{
    std::cout << name_ << " Choose a number(0 - 100): ";
    std::cin >> number_;
    if (number_ > 100 || number_ < 0)
    {
        std::cout << name_ << " you choose incorrect number. You will skip this game\n";
    }
}

void Customer::updateBalance(int money)
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
    if (rate_ > balance_)
    {
        std::cout << "You don`t have so much money. You will skip this game\n";
        rate_ = 0;
        number_ = -1;
    }
}

int Customer::getRate()
{
    return rate_;
}

void Customer::setWin(bool _win)
{
    win = _win;
}

std::ostream& operator<<(std::ostream& output, const Customer& cstmr) {

    output << "Name: " << cstmr.name_ << "\n\t\t" << "Number: " << cstmr.number_ << "\n\t\t" << "Rate: " << cstmr.rate_ << "\n\t\t";
    if(cstmr.win)
        output << "Status: Won\n\t\t";
    else
        output << "Status: Lost\n\t\t";


return output;
}

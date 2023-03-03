#include "Casino.h"
#include <cstdlib>
#include <ctime>
Casino::Casino(std::string _name) : balance_{100000},countTable{20}, number_{new int[countTable]}, table{1}, casinoName{_name}
{
    for (int i = 0; i < countTable; i++)
    {
        number_[i] = -1;
    }
}

int Casino::spinWheel()
{
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 100;
}

void Casino::startGame(Customer* cst, int table, int players)
{
    number_[table] = spinWheel();

    for (int i = 0; i < players; i++)
    {
        
        cst[i].setRate();
        cst[i].chooseNumber();

        if (cst[i].getNumber() == number_[table])
        {
            cst[i].updateBalance(cst[i].getRate() * winningRatio);
            cst[i].setWin(true);
            this->balance_ -= cst[i].getRate() * winningRatio;
        }
        else
        {
            cst[i].updateBalance(cst[i].getRate() * -1);
            cst[i].setWin(false);
            this->balance_ += cst[i].getRate();
        }
    }
}

void Casino::showResults(Customer* cst, int table, int player)
{
    std::cout << "\nCasino name: " << casinoName << "\n";
    std::cout << "Droped number: " << number_[table];
    std::cout << "\n----------------------------------------\n";
    for (int i = 0; i < player; i++)
    {
        cst[i].showDataAboutCustomer();
    }
    std::cout << "----------------------------------------\n";
}

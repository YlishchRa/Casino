#include "Casino.h"
#include <cstdlib>
#include <ctime>
Casino::Casino() : balance_{100000}, number_{new int[20]}, table{1} {}

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
        cst[i].chooseNumber();
        cst[i].setRate();


        if(cst[i].getNumber() == number_[table])
        {
            cst[i].replenishBalance(cst[i].getRate() * winningRatio );
            cst[i].setWin(true);
        }
        else
        {
            cst[i].replenishBalance(cst[i].getRate() * -1);
            cst[i].setWin(false);
        }
    }

}

void Casino::showResults( Customer* cst, int table, int player) {


    std::cout << "Droped number: " << number_[table];
    std::cout << "\n----------------------------------------\n";
    for (int i = 0; i < player; i++)
    {
        cst[i].showDataAboutCustomer();
    }
    std::cout << "----------------------------------------\n";


}

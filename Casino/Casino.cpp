#include "Casino.h"
#include <cstdlib>
#include <ctime>
Casino::Casino() : casinoName{""}, balance_{0}, countTable{0}, tables{nullptr} {}
Casino::Casino(std::string _name) : balance_{100000}, countTable{20}, tables{new Table[countTable]}, casinoName{_name}
{
    for (int i = 1; i < countTable; i++)
    {
        tables[i].setNumber(-1);
        tables[i].setTable(i);
    }
}

int Casino::spinWheel()
{
    srand(static_cast<unsigned int>(time(0)));
    return rand() % 100;
}

Casino Casino::operator=(const Casino& csn)
{
    casinoName = csn.casinoName;
    countTable = csn.countTable;
    balance_ = csn.balance_;
    if (tables == nullptr)
    {
        tables = new Table[csn.countTable];
    }
    else
    {
        delete[] tables;
        tables = new Table[csn.countTable];
        for (int i = 0; i < csn.countTable; i++)
        {
            tables[i] = csn.tables[i];
        }
    }

    return *this;
}

void Casino::startGame(Customer* cst, int table, int players)
{
    tables[table].setNumber(spinWheel());
    tables[table].setTable(table);
    tables[table].setPlayers(cst,players); 
    for (int i = 0; i < players; i++)
    {
        cst[i].setRate();
        cst[i].chooseNumber();

        if (cst[i].getNumber() == tables[table].getNumber())
        {
            cst[i].updateBalance(cst[i].getRate() * winningRatio);
            cst[i].setWin(true);
            balance_ -= cst[i].getRate() * winningRatio;
        }
        else
        {
            cst[i].updateBalance(cst[i].getRate() * -1);
            cst[i].setWin(false);
            balance_ += cst[i].getRate();
        }
    }
}

void Casino::showResults(Customer* cst, int table, int player)
{
    std::cout << "\nCasino name: " << casinoName;
    std::cout << "\nDroped number: " << tables[table].getNumber() << " by table: "<< tables[table].getTable();
    std::cout << "\n----------------------------------------\n";
    for (int i = 0; i < player; i++)
    {
        cst[i].showDataAboutCustomer();
    }
    std::cout << "----------------------------------------\n";
}

std::ostream& operator<<(std::ostream& output, const Casino& casino)
{
    output << "Name: " << casino.casinoName << "\n\t";
    output << "Balance: " << casino.balance_ << "\n\t";
    for (int i = 1; i < casino.countTable; i++)
    {
        output << "Droped number: " << casino.tables[i].getNumber() << " by table: " << casino.tables[i].getTable()
               << ". Players was playing here:\n\t\t "; 
        casino.tables[i].PlayersPlayed();
    }

    return output;
}

#pragma once
#include "Customer.h"
class Casino
{
    std::string casinoName;
    int countTable;
    double balance_;
    const double winningRatio = 1.5;
    class Table
    {
        int table;
        int number;
        const Customer* players;
        int countPlayers;

    public:
        Table() : table{0}, number{0}, players{nullptr}, countPlayers{0} {};
        int getTable() { return table; }
        int getNumber() { return number; }
        void setTable(int table_) { table = table_; }
        void setNumber(int number_) { number = number_; }
        void setPlayers(const Customer* _players, int _countPlayers)
        {
            players = _players;
            countPlayers = _countPlayers;
        }
        const Customer* getPlayers() { return players; }
        void PlayersPlayed()
        {

            if(countPlayers <= 0)
            {
                std::cout << "Nobody played here\n\t";
                return;
            }

            int i = 0;
            std::cout << "\n\t\t";
            while (i < countPlayers)
            {
                std::cout << *(players + i) << "\n\t\t";
                i++;
            }
            std::cout<< "\n\t";
        }
        Table operator=(const Table& tbl)
        {
            table = tbl.table;
            number = tbl.number;
            players = tbl.players;
            return *this;
        }

        ~Table() { delete[] players; }
    };
    Table* tables;

public:
    Casino();
    Casino(std::string _name);

    int spinWheel();
    Casino operator=(const Casino& csn);
    void startGame(Customer* cst, int table, int players);
    void showResults(Customer* cst, int table, int player);

    friend std::ostream& operator<<(std::ostream& output, const Casino& casino);
};

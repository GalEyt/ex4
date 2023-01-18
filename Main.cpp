//#include "Mtmchkin.h"
//#include "utilities.h"
#include <iostream>
int getTeamSize();
int getTeamSize()
{
    std::string input;
    int teamSize = 0;
    do {
        try {
            std::getline(std::cin,input,'\n');
            teamSize = stoi(input, nullptr,10);
        } catch (std::exception& e) {
            //printInvalidTeamSize();
            //printEnterTeamSizeMessage();
            std::cout << "wrong\n";
        }
        if(teamSize)
    }
    while(teamSize < 2 || teamSize > 6 );

    return teamSize;
}

int main()
{
    //printInsertPlayerMessage();
    std::cout << "enter num:\n";
    int test;
    test  = getTeamSize();
    std::cout << test;
    return 0;
}
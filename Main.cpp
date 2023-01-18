//#include "Mtmchkin.h"
//#include "utilities.h"
#include <iostream>
int getTeamSize();
int getTeamSize()
{
    std::string input;
    int teamSize;
    bool validTeamSize;
    do {
        validTeamSize = true;
        try {
            std::getline(std::cin,input,'\n');
            teamSize = stoi(input, nullptr,10);
        } catch (std::exception& e) {
            //printInvalidTeamSize();
            //printEnterTeamSizeMessage();
            std::cout << "wrong\n";
            validTeamSize = false;
            continue;
        }
        if(teamSize < 2 || teamSize > 6) {
            std::cout << "only 2-6\n";
            validTeamSize = false;
        }
        
    }
    while(!validTeamSize);

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
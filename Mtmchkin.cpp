#include "Mtmchkin.h"

bool isValidPlayerName(const std::string& name){
    if (name.length() > 15 || name.empty()){
        return false;
    }
    for (char const &c : name) {
        if(!islower(c) && !isupper(c)){
            return false;
        }
    }
    return true;
}

bool isValidPlayerClass(const std::string& job){
    if(job == "Wizard" || job == "Rogue" || job == "Fighter"){
        return true;
    }
    else{
        return false;
    }
}

std::deque<std::unique_ptr<Card>> Mtmchkin::getDeckHelper(std::ifstream &deckFile)
{
    int line = 0;
    std::deque<std::unique_ptr<Card>> cards;
    std::string cardType;
    while (getline(deckFile,cardType)){
        ++line;
        if(cardType == "Gremlin"){
            cards.push_back(std::unique_ptr<Gremlin>(new Gremlin()));
        } else if(cardType == "Witch") {
            cards.push_back(std::unique_ptr<Witch>(new Witch()));
        } else if(cardType == "Dragon"){
            cards.push_back(std::unique_ptr<Dragon>(new Dragon()));
        } else if(cardType == "Treasure"){
            cards.push_back(std::unique_ptr<Treasure>(new Treasure()));
        } else if(cardType == "Merchant"){
            cards.push_back(std::unique_ptr<Merchant>(new Merchant()));
        } else if(cardType == "Well"){
            cards.push_back(std::unique_ptr<Well>(new Well()));
        } else if(cardType == "Barfight"){
            cards.push_back(std::unique_ptr<Barfight>(new Barfight()));
        } else if(cardType == "Mana"){
            cards.push_back(std::unique_ptr<Mana>(new Mana()));
        } else{
            throw DeckFileFormatError(line);
        }
    }
    if(cards.size() < MIN_SIZE_OF_DECK){
        throw DeckFileInvalidSize();
    }
    return cards;
}

std::deque<std::unique_ptr<Card>> Mtmchkin::getDeck(const std::string &fileName)
{
    std::ifstream deckFile(fileName, std::ios::in);
    if(deckFile.good()){
        std::deque<std::unique_ptr<Card>> cards = getDeckHelper(deckFile);
        return cards;
    }
    else {
        throw DeckFileNotFound();
    }
}

int getTeamSize()
{
    std::string input;
    int teamSize = 0;
    while(teamSize < 2 || teamSize > 6 ) 
    {
        try {
            std::getline(std::cin,input,'\n');
            teamSize = stoi(input, nullptr,10);
        } catch (std::exception& e) {
            printInvalidTeamSize();
            printEnterTeamSizeMessage();
        }
    }

    return teamSize;
}

deque<unique_ptr<Player>> Mtmchkin::getTeam(int teamSize)
{
    std::string input;
    std::deque<std::unique_ptr<Player>> players;
    for (int i = 0; i < teamSize; ++i) {
        printInsertPlayerMessage();
        std::string playerName ,playerClass;
        std::getline(std::cin,input,'\n');
        std::stringstream str(input);
        str>>playerName>>playerClass;
        while(!isValidPlayerName(playerName) || !isValidPlayerClass(playerClass)){
            if(!isValidPlayerName(playerName)){
                printInvalidName();
            }
            else if(!isValidPlayerClass(playerClass)){
                printInvalidClass();
            }
            std::getline(std::cin,input,'\n');
            std::stringstream str(input);
            str>>playerName>>playerClass;
        }
        if(playerClass == "Wizard"){
            players.push_back(std::unique_ptr<Wizard> (new Wizard(playerName)));
        } else if(playerClass == "Rogue") {
            players.push_back(std::unique_ptr<Rogue>(new Rogue(playerName)));
        } else if(playerClass == "Fighter") {
            players.push_back(std::unique_ptr<Fighter>(new Fighter(playerName)));
        }

    }
    return players;
}
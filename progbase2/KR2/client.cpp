//
// Created by tgifr on 22.05.17.
//


#include "include/Remote.h"
#include <iostream>
#include <vector>
#include <sstream>
#include <vector>
#include <iterator>

using namespace std;
vector<std::string> getTokens(std::string str);
int analyzeTokens(vector<std::string> tokens);

int main(void) {
//    Remote interface;
//    std::cout << "Received: \n" << interface.PrintAndReturnWhatPrinted(CustomDataType{.name = "Marko"}).name << std::endl;
//}
    //! failed to implement user console input(not enough time)
    //! all functions for user are in "Remote.h"
}

vector<std::string> getTokens(std::string str){
    istringstream iss(str);
    vector<std::string> tokens{istream_iterator<std::string>{iss},
                               istream_iterator<std::string>{}};
    return tokens;
}
int analyzeTokens(vector<std::string> tokens){
    int size = tokens.size();
    if(size > 0){
        std::string first = tokens.at(0);
        if(!first.compare("print") && size > 1) return PRINT;
        if(!first.compare("GetState") ) return GET_STATE;
        if(!first.compare("AddSong")) return ADD_SONG;
        if(!first.compare("get") && size > 1) return GET_BY_INDEX;
        if(!first.compare("change") && size > 2) return CHANGE;
    }
    return ERR;
}
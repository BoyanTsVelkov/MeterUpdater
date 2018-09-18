/*
 *  GameEndData.hpp
 *
 *  Created on: 2018-09-17
 *      Author: Boyan Velkov
 */


#ifndef GAME_END_DATA_H
#define GAME_END_DATA_H


//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers

//Forward declarations

struct GameEndData
{
    GameEndData()
    {
        clearData();
    }
    ~GameEndData(){};

    void clearData()
    {
        gambleGamesPlayed = 0;
        gameWin = 0;
    }

    void printValues() const
    {
        std::cout << "" << std::endl;
        std::cout << "gameWin = " << gameWin << std::endl;
        std::cout << "gambleGamesPlayed = " << gambleGamesPlayed << std::endl;
        std::cout << "" << std::endl;
    }

    uint64_t gameWin;
    bool gambleGamesPlayed;
};

#endif //GAME_END_DATA_H

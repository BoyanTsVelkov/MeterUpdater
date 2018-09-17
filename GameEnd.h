/*
 *  GameEnd.h
 *
 *  Created on: 2017-09-13
 *      Author: Boyan Velkov
 */

#ifndef GAMEEND_H
#define GAMEEND_H

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MeterUpdate.h"
#include "GameEndData.hpp"

//Forward declarations

/**
*   @brief class GameEnd used to update meters after the end of games.
*/
class GameEnd: public MeterUpdate
{
    public:
        /** @brief GameEnd constructor
        *
        *   @param uint64_t gameWin - win from game paytable
        *   @param
        *
        *   @note now all off the parameters are combined in a single struct
        */
        GameEnd(const GameEndData & gameEndData):
                        _gameWin(gameEndData.gameWin),
                        _playedGambles(gameEndData.gambleGamesPlayed)
        {}

        virtual ~GameEnd()=default;

        int32_t updateGamesPlayedMeters();

        int32_t updateGamesWonMeters();

    private:

        uint64_t _gameWin;

        bool _playedGambles;
};

#endif // GAMEEND_H

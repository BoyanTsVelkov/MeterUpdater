/*
 *  UpdateAfterJPLimitExceed.h
 *
 *  Created on: 2018-08-15
 *      Author: Boyan Velkov
 */

#ifndef UPDATEAFTERJPLIMITEXCEED_H
#define UPDATEAFTERJPLIMITEXCEED_H

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MeterUpdate.h"
#include "GameEndData.hpp"

//Forward declarations

class UpdateAfterJPLimitExceed: public MeterUpdate
{
    public:
        UpdateAfterJPLimitExceed(const GameEndData & gameEndData):
                    _gameWin(gameEndData.gameWin),
                    _playedGambles(gameEndData.gambleGamesPlayed)
        {}

        virtual ~UpdateAfterJPLimitExceed() = default;

        int32_t update();

    private:
        uint64_t _gameWin;
        bool  _playedGambles;
};

#endif // UPDATEAFTERJPLIMITEXCEED_H

/*
 *  UpdateAfterCreditLimitExceed.h
 *
 *  Created on: 2018-08-14
 *      Author: Boyan Velkov
 */

#ifndef UPDATEAFTERCREDITLIMITEXCEED_H
#define UPDATEAFTERCREDITLIMITEXCEED_H

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MeterUpdate.h"
#include "GameEndData.hpp"

//Forward declarations

class UpdateAfterCreditLimitExceed: public MeterUpdate
{
    public:
        UpdateAfterCreditLimitExceed(const GameEndData & gameEndData):
                    _gameWin(gameEndData.gameWin),
                    _playedGambles(gameEndData.gambleGamesPlayed)
        {}

        virtual ~UpdateAfterCreditLimitExceed() = default;

        int32_t update();

    private:

        uint64_t _gameWin;
        bool  _playedGambles;
};

#endif // UPDATEAFTERCREDITLIMITEXCEED_H

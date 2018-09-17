/*
 *  CreditBet.h
 *
 *  Created on: 2017-09-15
 *      Author: Boyan Velkov
 */

#ifndef CREDITBET_H
#define CREDITBET_H

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MeterUpdate.h"

//Forward declarations

class CreditBet: public MeterUpdate
{
    public:
        /** @brief CreditBet constructor
        *
        *   @param uint64_t bet - amount of last betting
        *   @param relativeDenomIdx - denom ID from current game
        */
        CreditBet(const uint64_t bet, const uint8_t relativeDenomIdx):_bet(bet)
        {}

        virtual ~CreditBet() = default;

        /** @brief function that actually update meters
        *          use data set in constructor
        *
        *   @return error code
        */
        int32_t update();

    private:

        uint64_t _bet;
};

#endif // CREDITBET_H

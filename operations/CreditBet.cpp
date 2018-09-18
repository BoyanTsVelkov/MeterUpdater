/*
 *  CreditBet.cpp
 *
 *  Created on: 2017-09-15
 *      Author: Boyan Velkov
 */

//Corresponding header
#include "CreditBet.h"

//C system headers
#include <cstdlib>

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

int32_t CreditBet::update()
{
    int32_t err = EXIT_SUCCESS;

    // decrease curent credit
    err = removeFromMeter(Meters::Current_credit, _bet);

    if (EXIT_SUCCESS == err)
    {
        // increase coin in
        err = addToMeter(Meters::Total_coin_in_credits, _bet);
    }

    uint64_t restricted = 0;

    if (EXIT_SUCCESS == err)
    {
        err = getMeterValue(Meters::Current_restricted_credits, restricted);
    }

    // check for restricted credit
    if(restricted && EXIT_SUCCESS == err)
    {
        // if bet is bigger than restricted - set restricted to zero
        if(restricted < _bet)
        {
            _bet -= restricted;

            err = addToMeter(Meters::Total_restricted_amount_played_credits,
                                                                    restricted);

            if (EXIT_SUCCESS == err)
            {
                err = meterSetTo(Meters::Current_restricted_credits, 0);
            }
        }
        // if restricted is bigger than bet - set bet to zero
        else
        {
            err = removeFromMeter(Meters::Current_restricted_credits, _bet);

            if (EXIT_SUCCESS == err)
            {
                err = addToMeter(Meters::Total_restricted_amount_played_credits,
                                                                          _bet);
            }
            _bet = 0;
        }
    }

    uint64_t promotional = 0;

    if (EXIT_SUCCESS == err)
    {
        err = getMeterValue(Meters::Current_promotional_credits, promotional);
    }

    // check for promotional credit and bet isn't distributed
    if(promotional && _bet && EXIT_SUCCESS ==  err)
    {
        // if bet is bigger than promotional - set promotional to zero
        if(promotional < _bet)
        {
            _bet -= promotional;
            err = addToMeter(Meters::Total_promotional_amount_played_credits,
                                                                   promotional);
            if (EXIT_SUCCESS == err)
            {
                meterSetTo(Meters::Current_promotional_credits, 0);
            }
        }
        // if promotional is bigger than bet - set bet to zero
        else
        {
            err = removeFromMeter(Meters::Current_promotional_credits, _bet);

            if (EXIT_SUCCESS == err)
            {
                err = addToMeter(Meters::Total_promotional_amount_played_credits
                                                                        , _bet);
            }
            _bet = 0;
        }
    }

    // if bet isn't distributed take it from cashable
    if(_bet && EXIT_SUCCESS == err)
    {
        removeFromMeter(Meters::Current_cashable_credits, _bet);
    }

    // class MeterUpdate print what is the problem
    // here print when it is occurs
    if(EXIT_FAILURE == err)
    {
        std::cout << "Error in update after bet!" << std::endl;
    }

    // MeterUpdate::update() will print message if error occur
    err = MeterUpdate::update();

    return err;
}

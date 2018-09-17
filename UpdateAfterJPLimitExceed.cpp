/*
 *  UpdateAfterJPLimitExceed.cpp
 *
 *  Created on: 2018-08-15
 *      Author: Boyan Velkov
 */

//Corresponding header
#include "UpdateAfterJPLimitExceed.h"

//C system headers

//C++ system headers
#include <cstdlib>
#include <iostream>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

int32_t UpdateAfterJPLimitExceed::update()
{
    int32_t err = EXIT_SUCCESS;

    err = addToMeter(Meters::Total_coin_out_credits, _gameWin);

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_jackpot_credit, _gameWin);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_attendant_paid_paytable_win_credits,
                                                                      _gameWin);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_won_credits_coin_out_and_jackpot,
                                                                       _gameWin);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_hand_paid_credits_cancelled_and_jackpot,
                                                                       _gameWin);
    }

    // class MeterUpdate print what is the problem
    // here print when it is occurs
    if(EXIT_FAILURE == err)
    {
        std::cout << "Error in update meters after credit limit exceed!" << std::endl;
    }
    else
    {
        // MeterUpdate::update() will print message if error occur
        err = MeterUpdate::update();
    }

    return err;
}

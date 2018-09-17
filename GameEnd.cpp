/*
 *  GameEnd.cpp
 *
 *  Created on: 2017-09-13
 *      Author: Boyan Velkov
 */

//Corresponding header
#include "GameEnd.h"

//C system headers

//C++ system headers
#include <iostream>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

int32_t GameEnd::updateGamesPlayedMeters()
{
    int32_t err = EXIT_SUCCESS;

    err = addOneToMeter(Meters::Games_played);

    if(EXIT_SUCCESS == err)
    {
        err = addOneToMeter(Meters::Games_since_last_power_reset);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addOneToMeter(Meters::Games_since_last_door_closure);
    }

    if(_gameWin && EXIT_SUCCESS == err)
    {
        err = addOneToMeter(Meters::Games_won);
    }
    else
    {
        if(EXIT_SUCCESS == err)
        {
            if(_playedGambles)
            {
                err = addOneToMeter(Meters::Game_lost_in_gamble);
            }
            else
            {
                err = addOneToMeter(Meters::Games_lost);
            }
        }
    }

    // class MeterUpdate print what is the problem
    // here print when it is occurs
    if(EXIT_FAILURE == err)
    {
        std::cout << "Error in update games played meters!" << std::endl;
    }
    else
    {
        // MeterUpdate::update() will print message if error occur
        err = MeterUpdate::update();
    }

    return err;
}

int32_t GameEnd::updateGamesWonMeters()
{
    int32_t err = EXIT_SUCCESS;

    if( _gameWin )
    {
        err = addToMeter(Meters::Total_won_credits_coin_out_and_jackpot,
                                                                       _gameWin);

        if(EXIT_SUCCESS == err)
        {
            err = addToMeter(Meters::Total_coin_out_credits, _gameWin);
        }

        if(EXIT_SUCCESS == err)
        {
            err = addToMeter(Meters::Current_credit, _gameWin);
        }

        if(EXIT_SUCCESS == err)
        {
            err = addToMeter(Meters::Current_cashable_credits, _gameWin);
        }


        if(_gameWin && EXIT_SUCCESS == err)
        {
            err = addToMeter(
                     Meters::Total_machine_paid_paytable_win_credits, _gameWin);
        }
    }

    // class MeterUpdate print what is the problem
    // here print when it is occurs
    if(EXIT_FAILURE == err)
    {
        std::cout << "Error in update games win in machine meters!" << std::endl;
    }
    else
    {
        // MeterUpdate::update() will print message if error occur
        err = MeterUpdate::update();
    }

    return err;
}

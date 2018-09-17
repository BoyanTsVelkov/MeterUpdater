/*
 *  HandPayCashOut.cpp
 *
 *  Created on: 2017-12-04
 *      Author: Boyan Velkov
 */

//Corresponding .h file
#include "HandPayCashOut.h"

//C system headers

//C++ system headers
#include<cstdlib>
#include <iostream>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

int32_t HandPayCashOut::update()
{
    int32_t err = EXIT_SUCCESS;

    err = addToMeter(Meters::Total_hand_paid_cancelled_credits, _amount);

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_cancelled_credits, _amount);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_hand_paid_credits_cancelled_and_jackpot,
                                                                       _amount);
    }

    if(EXIT_SUCCESS == err)
    {
        err = removeFromMeter(Meters::Current_credit, _amount);
    }

    if(EXIT_SUCCESS == err)
    {
        uint64_t promotional = 0;

        err = getMeterValue(Meters::Current_promotional_credits, promotional);

        if(promotional && EXIT_SUCCESS == err)
        {
            // if promotional is bigger than amount - set amount to zero
            if(promotional > _amount)
            {
                promotional -= _amount;
                _amount = 0;

                err = removeFromMeter(Meters::Current_promotional_credits,
                                                                   promotional);
            }
            // if amount is bigger than promotional - set promotional to zero
            else
            {
                _amount -= promotional;

                err = removeFromMeter(Meters::Current_promotional_credits, 0);
            }
        }
    }

    if(_amount && EXIT_SUCCESS == err)
    {
        err = removeFromMeter(Meters::Current_cashable_credits, _amount);
    }

    // class MeterUpdate print what is the problem
    // here print when it is occurs
    if(EXIT_FAILURE == err)
    {
        std::cout <<  "Error in update for hand pay!" << std::endl;
    }

	// MeterUpdate::update() will print message if error occur
    err = MeterUpdate::update();

    return err;
}

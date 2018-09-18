/*
 *  AttendantCashIn.cpp
 *
 *  Created on: 2017-12-04
 *      Author: Boyan Velkov
 */

// Corresponding heder
#include "AttendantCashIn.h"

//C system headers

//C++ system headers
#include<cstdlib>
#include<iostream>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

int32_t AttendantCashIn::update()
{
    int32_t err = addToMeter(Meters::Current_credit, _amount);

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Current_cashable_credits, _amount);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_attendant_add_credit, _amount);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Electronic_cashable_transfer_to_GM_credits,
                                                                       _amount);
    }

    // class MeterUpdate print what is the problem
    // here print when it occurs
    if(EXIT_FAILURE == err)
    {
        std::cout << "Error in update for attendant add credit!" << std::endl;
    }

    err = MeterUpdate::update();

    return err;
}

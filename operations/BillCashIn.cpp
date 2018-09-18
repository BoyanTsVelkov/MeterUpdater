/*
 *  BillCashIn.cpp
 *
 *  Created on: 2018-04-20
 *      Author: Boyan Velkov
 */

// Corresponding heder
#include "BillCashIn.h"

//C system headers

//C++ system headers
#include <iostream>
#include <algorithm>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

const uint8_t numberOfAllBillValues = 24;

// 0x40 is number of bill equal to 1.00
// 0x41 for 2.00, 0x42 for 5.00 and so on and so on.
const uint8_t meterNumberForSmallestBill = 0x40;

const uint32_t billValues[numberOfAllBillValues] =
{
    1,
    2,
    5,
    10,
    20,
    25,
    50,
    100,
    200,
    250,
    500,
    1000,
    2000,
    2500,
    5000,
    10000,
    20000,
    25000,
    50000,
    100000,
    200000,
    250000,
    500000,
    1000000
};

int32_t BillCashIn::update()
{
    int32_t err = EXIT_SUCCESS;

    // convert to credit
    const uint64_t amount = (_bill * 100) / _accountingDenomValue;

    err = addToMeter(Meters::Current_credit, amount);

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Current_cashable_credits, amount);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addOneToMeter(Meters::Number_of_bills_currently_in_stacker);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_value_of_bills_currently_in_stacker,
                                                                        amount);
    }

    if(EXIT_SUCCESS == err)
    {
        err = addToMeter(Meters::Total_credits_from_bills_accepted, amount);
    }

    if(EXIT_SUCCESS == err)
    {
        const uint32_t * const lastElement = billValues + numberOfAllBillValues;

        // find pointer to position of this bill value in array
        const uint32_t * const point = std::find(billValues, lastElement,
                                                                         _bill);

        if( point == lastElement)
        {
            err = EXIT_FAILURE;
            std::cout << "Invalid bill" << std::endl;
        }

        if( EXIT_SUCCESS == err )
        {
            // calculate number of position
            const uint32_t  position = (uint32_t)std::distance(billValues,
                                                                         point);

            // to find meter for update we use its position in billValues array
            // and collect it with smallest bill meter number.
            const uint32_t meterForUpdate = meterNumberForSmallestBill +
                                                                       position;

            err = addOneToMeter(meterForUpdate);
        }
    }

    // class MeterUpdate print what is the problem
    // here print when it is occurs
    if(EXIT_FAILURE == err)
    {
        std::cout << "Error in update for accepted bill!" << std::endl;
    }

    // MeterUpdate::update() will print message if error occur
    err = MeterUpdate::update();

    return err;
}

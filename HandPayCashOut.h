/*
 *  HandPayCashOut.h
 *
 *  Created on: 2017-12-04
 *      Author: Boyan Velkov
 */

#ifndef HANDPAYCASHOUT_H
#define HANDPAYCASHOUT_H

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MeterUpdate.h"

//Forward declarations

class HandPayCashOut : public MeterUpdate
{
    public:
        HandPayCashOut(const uint64_t amount): _amount(amount) {}

        virtual ~HandPayCashOut() = default;

        /** @brief function that actually update meters
        *          use data set in constructor
        *
        *   @return error code
        */
        int32_t update();

    private:

        uint64_t _amount;
};

#endif // HANDPAYCASHOUT_H

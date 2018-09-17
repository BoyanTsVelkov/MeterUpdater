/*
 *  BillCashIn.h
 *
 *  Created on: 2018-09-17
 *      Author: Boyan Velkov
 */

#ifndef BILLCASHIN_H
#define BILLCASHIN_H

//C system headers

//C++ system headers

//Other libraries headers

//Own components headers
#include "MeterUpdate.h"

//Forward declarations

class BillCashIn: public MeterUpdate
{
    public:
        BillCashIn(const uint64_t bill, const uint32_t accountingDenomValue):
                                     _bill(bill),
                                     _accountingDenomValue(accountingDenomValue)
        {}

        virtual ~BillCashIn() = default;

        /** @brief function that actually update meters
        *          use data set in constructor
        *
        *   @return error code
        */
        int32_t update();
    private:

        const uint64_t _bill;

        const uint32_t _accountingDenomValue;
};

#endif // BILLCASHIN_H

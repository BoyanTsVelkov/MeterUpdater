/*
 *  MeterUpdate.cpp
 *
 *  Created on: 2017-09-13
 *      Author: Boyan Velkov
 */

//Corresponding header
#include "MeterUpdate.h"

//C system headers

//C++ system headers
#include <cstdlib>
#include <iostream>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

int32_t MeterUpdate::update()
{
    int32_t err = EXIT_SUCCESS; ///_masterMeters->save();

    if(EXIT_FAILURE == err)
    {
        std::cout << "Error to save group in NVRAM!" << std::endl;
    }

    return err;
}

int32_t MeterUpdate::addToMeter(const uint32_t meter, const uint64_t amount)
{
    int32_t err = EXIT_SUCCESS;

    // check for valid meter number
    if(Meters::Count <= meter)
    {
        err = EXIT_FAILURE;
        std::cout << "Not valid meter number " << meter << std::endl;
    }

    if(EXIT_SUCCESS == err)
    {
//        _masterMeters->writeMeter(meter) += amount;
    }

    return err;
}

int32_t MeterUpdate::addOneToMeter(const uint32_t meter)
{
    int32_t err = EXIT_SUCCESS;

    // check for valid meter number
    if(Meters::Count <= meter)
    {
        err = EXIT_FAILURE;
        std::cout << "Not valid meter number " << meter << std::endl;
    }

    if(EXIT_SUCCESS == err)
    {
//         _masterMeters->writeMeter(meter)++;
    }

    return err;
}

int32_t MeterUpdate::meterSetTo(const uint32_t meter, const uint64_t amount)
{
    int32_t err = EXIT_SUCCESS;

    // check for valid meter number
    if(Meters::Count <= meter)
    {
        err = EXIT_FAILURE;
        std::cout << "Not valid meter number " << meter << std::endl;
    }

    if(EXIT_SUCCESS == err)
    {
//         _masterMeters->writeMeter(meter) = amount;
    }

    return err;
}

int32_t MeterUpdate::removeFromMeter(const uint32_t meter, const uint64_t amount)
{
    int32_t err = EXIT_SUCCESS;

    // check for valid meter number
    if(Meters::Count <= meter)
    {
        err = EXIT_FAILURE;
        std::cout << "Not valid meter number " << meter << std::endl;
    }

    if( EXIT_SUCCESS == err && amount > 1000000/*_masterMeters->readMeter(meter)*/ )
    {
        err = EXIT_FAILURE;
        std::cout << "Roll-over meter " << meter << " with " << amount <<" amount" << std::endl;
    }

    if(EXIT_SUCCESS == err)
    {
//         _masterMeters->writeMeter(meter) -= amount;
    }

    return err;
}

uint32_t MeterUpdate::getMeterValue(const uint32_t meter, uint64_t& amount)const
{
    int32_t err = EXIT_SUCCESS;

    // check for valid meter number
    if(Meters::Count <= meter)
    {
        err = EXIT_FAILURE;
        std::cout << "Not valid meter number " << meter << std::endl;
    }

    if(EXIT_SUCCESS == err)
    {
//        amount = _masterMeters->readMeter(meter);
    }

    return err;
}

void MeterUpdate::print() const
{
    for(uint16_t i = 0; i < Meters::Count; i++)
    {
        uint64_t currentMeterAmount = 10;///_masterMeters->readMeter(i);

        if(currentMeterAmount)
        {
            std::cout << "Meter: " << i << " = " << currentMeterAmount << std::endl;
        }
    }
}






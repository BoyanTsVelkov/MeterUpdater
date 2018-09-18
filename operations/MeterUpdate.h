/*
 *  MeterUpdate.h
 *
 *  Created on: 2017-09-13
 *      Author: Boyan Velkov
 */

#ifndef METERUPDATE_H_
#define METERUPDATE_H_

//C system headers

//C++ system headers
#include <cstdint>

//Other libraries headers

//Own components headers
#include "Meters.hpp"

//Forward declarations

class MeterUpdate
{
    public:
        /**
        *   @brief MeterUpdate constructor
        */
        MeterUpdate() = default;

        virtual ~MeterUpdate() = default;

        /** @brief Return value of any meters
        *
        *   @param uint32_t meter - number of meter (example 0x25)
        *   @param uint64_t& amount - here store value of current meter
        *
        *   @return error code
        */
        uint32_t getMeterValue(const uint32_t meter, uint64_t& amount) const;

        /**
        *   @brief Print in console all meters different from zero
        */
        void print() const;

    protected:

        int32_t update();

        /** @brief Add value to meter
        *
        *   @param uint32_t meter - number of meter (example 0x25)
        *   @param uint64_t amount - value that will be add to meter
        *
        *   @return error code
        */
        int32_t addToMeter(const uint32_t meter, const uint64_t amount);

        /** @brief Increment with one to meter
        *
        *   @param uint32_t meter - number of meter (example 0x25)
        *
        *   @return error code
        */
        int32_t addOneToMeter(const uint32_t meter);

        /** @brief Set value to meter
        *
        *   @param uint32_t meter - number of meter (example 0x25)
        *   @param uint64_t amount - value that will be set to meter
        *
        *   @return error code
        */
        int32_t meterSetTo(const uint32_t meter, const uint64_t amount);

        /** @brief Pull out value from meter
        *
        *   @param uint32_t meter - number of meter (example 0x25)
        *   @param uint64_t amount - value that will be taken from meter
        *
        *   @return error code
        */
        int32_t removeFromMeter(const uint32_t meter, const uint64_t amount);

    private:

};

#endif // METERUPDATE_H_

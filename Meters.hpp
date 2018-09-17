/*
 *  Meters.hpp
 *
 *  Created on: 2017-09-13
 *      Author: Boyan Velkov
 */

#ifndef METERS_HPP
#define METERS_HPP

namespace Meters
{
    enum MainMeters
    {
        /*---------------  Game machine meters  ---------------*/
        // Basic meters
        Total_coin_in_credits                              = 0x00,
        Total_coin_out_credits                             = 0x01,
        Total_jackpot_credit                               = 0x02,
        Total_hand_paid_cancelled_credits                  = 0x03,
        Total_cancelled_credits                            = 0x04,
        Games_played                                       = 0x05,
        Games_won                                          = 0x06,
        Games_lost                                         = 0x07,
        Total_credits_from_bills_accepted                  = 0x0B,

        Current_credit                                     = 0x0C,

        // Duplicate SAS meters for backwards compatibility only
        Total_SAS_cashable_promotional_tickets_in_amounts  = 0x0D,
        Total_SAS_cashable_ticket_out_amounts              = 0x0E,
        Total_SAS_restricted_ticket_in_amounts             = 0x0F,
        Total_SAS_restricted_ticket_out_amounts            = 0x10,
        Total_SAS_cashable_promotional_tickets_in_quantity = 0x11,
        Total_SAS_cashable_ticket_out_quantity             = 0x12,
        Total_SAS_restricted_ticket_in_quantity            = 0x13,
        Total_SAS_restricted_ticket_out_quantity           = 0x14,

        // Basic meters
        Total_ticket_in_credits                            = 0x15,
        Total_ticket_out_credits                           = 0x16,
        Total_electronic_transfers_to_GM_or_ticket_credits = 0x17,
        Total_electronic_transfers_to_host_credits         = 0x18,//include wins
        Total_restricted_amount_played_credits             = 0x19,
        Total_promotional_amount_played_credits            = 0x1A,

        Current_restricted_credits                         = 0x1B,

        // Paid credit meters
        Total_machine_paid_paytable_win_credits            = 0x1C,
        Total_machine_paid_progressive_win_credits         = 0x1D,
        Total_machine_paid_external_bonus_credits          = 0x1E,
        Total_attendant_paid_paytable_win_credits          = 0x1F,
        Total_attendant_paid_progressive_win_credits       = 0x20,
        Total_attendant_paid_external_bonus_credits        = 0x21,
        Total_won_credits_coin_out_and_jackpot             = 0x22,
        Total_hand_paid_credits_cancelled_and_jackpot      = 0x23,

        /* TODO Boyan Velkov 13.09.17 - check this meter
           Total in? */
        Total_drop_credits                                 = 0x24,

        // Game after errors
        Games_since_last_power_reset                       = 0x25,
        Games_since_last_door_closure                      = 0x26,

        // Ticket credit meters
        Total_cashable_and_promotional_tickets_in_credits  = 0x28,
        Total_cashable_ticket_in_credits                   = 0x29,
        Total_restricted_ticket_in_credits                 = 0x2A,
        Total_promotional_ticket_in_credits                = 0x2B,
        Total_cashable_ticket_out_credits                  = 0x2C,
        Total_restricted_ticket_out_credits                = 0x2D,

        // Electronic transfers meters not including external bonus awards
        Electronic_cashable_transfer_to_GM_credits         = 0x2E,
        Electronic_restricted_transfer_to_GM_credits       = 0x2F,
        Electronic_promotional_transfer_to_GM_credits      = 0x30,
        Electronic_cashable_transfers_to_host_credits      = 0x32,
        Electronic_restricted_transfers_to_host_credits    = 0x33,
        Electronic_promotional_transfers_to_host_credits   = 0x34,

        // Ticket quantity meters
        Total_cashable_ticket_in_quantity                  = 0x35,
        Total_restricted_ticket_in_quantity                = 0x36,
        Total_promotional_ticket_in_quantity               = 0x37,
        Total_cashable_ticket_out_credits_quantity         = 0x38,
        Total_restricted_ticket_out_quantity               = 0x39,

        // Bill meters
        Number_of_bills_currently_in_stacker               = 0x3E,
        Total_value_of_bills_currently_in_stacker          = 0x3F,
        Total_number_of_$1_bills_accepted                  = 0x40,
        Total_number_of_$2_bills_accepted                  = 0x41,
        Total_number_of_$5_bills_accepted                  = 0x42,
        Total_number_of_$10_bills_accepted                 = 0x43,
        Total_number_of_$20_bills_accepted                 = 0x44,
        Total_number_of_$25_bills_accepted                 = 0x45,
        Total_number_of_$50_bills_accepted                 = 0x46,
        Total_number_of_$100_bills_accepted                = 0x47,
        Total_number_of_$200_bills_accepted                = 0x48,
        Total_number_of_$250_bills_accepted                = 0x49,
        Total_number_of_$500_bills_accepted                = 0x4A,
        Total_number_of_$1000_bills_accepted               = 0x4B,
        Total_number_of_$2000_bills_accepted               = 0x4C,
        Total_number_of_$2500_bills_accepted               = 0x4D,
        Total_number_of_$5000_bills_accepted               = 0x4E,
        Total_number_of_$10000_bills_accepted              = 0x4F,
        Total_number_of_$20000_bills_accepted              = 0x50,
        Total_number_of_$25000_bills_accepted              = 0x51,
        Total_number_of_$50000_bills_accepted              = 0x52,
        Total_number_of_$100000_bills_accepted             = 0x53,
        Total_number_of_$200000_bills_accepted             = 0x54,
        Total_number_of_$250000_bills_accepted             = 0x55,
        Total_number_of_$500000_bills_accepted             = 0x56,
        Total_number_of_$1000000_bills_accepted            = 0x57,

        // Theoretical payback percentage
        Weighted_average_theoretical_payback_percentage    = 0x7F,

        /*--------------------  SAS meters  --------------------*/
        // Ticket in
        Cashable_ticket_in_amounts                         = 0x80,
        Cashable_ticket_in_quantity                        = 0x81,
        Restricted_ticket_in_amounts                       = 0x82,
        Restricted_ticket_in_quantity                      = 0x83,
        Promotional_ticket_in_amounts                      = 0x84,
        Promotional_ticket_in_quantity                     = 0x85,

        // Ticket out
        Cashable_ticket_out_amounts                        = 0x86,
        Cashable_ticket_out_quantity                       = 0x87,
        Restricted_ticket_out_amounts                      = 0x88,
        Restricted_ticket_out_quantity                     = 0x89,

        // Validate handpays
        Validate_cancelled_credits_hp_receipt_amount       = 0x8C,
        Validate_cancelled_credits_hp_receipt_quantity     = 0x8D,
        Validate_JP_handpay_receipt_amaunt                 = 0x8E,
        Validate_JP_handpay_receipt_quantity               = 0x8F,
        Validate_cancelled_credits_hp_no_receipt_amount    = 0x90,
        Validate_cancelled_credits_hp_no_receipt_quantity  = 0x91,
        Validate_JP_handpay_no_receipt_amount              = 0x92,
        Validate_JP_handpay_no_receipt_quantity            = 0x93,

        // Transfer to gaming machine
        Cashable_transfers_to_gaming_machine_amount        = 0xA0,
        Cashable_transfers_to_gaming_machine_quantity      = 0xA1,
        Restricted_transfers_to_gaming_machine_amount      = 0xA2,
        Restricted_transfers_to_gaming_machine_quantity    = 0xA3,
        Promotional_transfers_to_gaming_machine_amount     = 0xA4,
        Promotional_transfers_to_gaming_machine_quantity   = 0xA5,

        // Transfer to ticket
        Cashable_transfer_to_ticket_amount                 = 0xA8,
        Cashable_transfer_to_ticket_quantity               = 0xA9,
        Restricted_transfer_to_ticket_amount               = 0xAA,
        Restricted_transfer_to_ticket_quantity             = 0xAB,

        // Bonus transfers
        Bonus_cashable_transfers_to_GM_amount              = 0xAE,
        Bonus_cashable_transfers_to_GM_quantity            = 0xAF,
        Bonus_promotional_transfers_to_GM_amount           = 0xB0,
        Bonus_promotional_transfers_to_GM_quantity         = 0xB1,

        // Transfer to host
        Cashable_transfer_to_host_amount                   = 0xB8,
        Cashable_transfer_to_host_quantity                 = 0xB9,
        Restricted_transfer_to_host_amount                 = 0xBA,
        Restricted_transfer_to_host_quantity               = 0xBB,
        Promotional_transfer_to_host_amount                = 0xBC,
        Promotional_transfer_to_host_quantity              = 0xBD,

        Last_meter_saved_for_SAS_protocol                  = 0xFF,

        // meters that we need out of standart
        //------------------------------------------------------------------//
        Current_cashable_credits,
        Current_promotional_credits,
        Total_attendant_add_credit,
        // save for future use
        Game_lost_in_gamble,

        // count of all meters
        Count,

    };
};

#endif // METERS_HPP

/**
 * @file can_filters.h
 *
 * @defgroup CANAPP    Filters for can application
 *
 * @brief Filters for canbus application
 *
 */

#ifndef CAN_FILTERS_H
#define CAN_FILTERS_H

#include "conf.h"
#include "can_ids.h"

// -----------------------------------------------------------------------------
/** Set filters and masks.
 *
 * The filters are divided in two groups:
 *
 * Group 0: Filter 0 and 1 with corresponding mask 0.
 * Group 1: Filter 2, 3, 4 and 5 with corresponding mask 1.
 *
 * If a group mask is set to 0, the group will receive all messages.
 *
 * If you want to receive ONLY 11 bit identifiers, set your filters
 * and masks as follows:
 *
 *  uint8_t can_filter[] PROGMEM = {
 *      // Group 0
 *      MCP2515_FILTER(0),              // Filter 0
 *      MCP2515_FILTER(0),              // Filter 1
 *
 *      // Group 1
 *      MCP2515_FILTER(0),              // Filter 2
 *      MCP2515_FILTER(0),              // Filter 3
 *      MCP2515_FILTER(0),              // Filter 4
 *      MCP2515_FILTER(0),              // Filter 5
 *
 *      MCP2515_FILTER(0),              // Mask 0 (for group 0)
 *      MCP2515_FILTER(0),              // Mask 1 (for group 1)
 *  };
 *
 *
 * If you want to receive ONLY 29 bit identifiers, set your filters
 * and masks as follows:
 *
 * \code
 *  uint8_t can_filter[] PROGMEM = {
 *      // Group 0
 *      MCP2515_FILTER_EXTENDED(0),     // Filter 0
 *      MCP2515_FILTER_EXTENDED(0),     // Filter 1
 *
 *      // Group 1
 *      MCP2515_FILTER_EXTENDED(0),     // Filter 2
 *      MCP2515_FILTER_EXTENDED(0),     // Filter 3
 *      MCP2515_FILTER_EXTENDED(0),     // Filter 4
 *      MCP2515_FILTER_EXTENDED(0),     // Filter 5
 *
 *      MCP2515_FILTER_EXTENDED(0),     // Mask 0 (for group 0)
 *      MCP2515_FILTER_EXTENDED(0),     // Mask 1 (for group 1)
 *  };
 * \endcode
 *
 * If you want to receive both 11 and 29 bit identifiers, set your filters
 * and masks as follows:
 */
const uint8_t can_filter[] PROGMEM =
{
    // Group 0
    MCP2515_FILTER(CAN_FILTER_MSG_MSC19_STATE), // Filter 0
    MCP2515_FILTER(CAN_FILTER_MSG_MSC19_ADC),   // Filter 1

    // Group 1
    MCP2515_FILTER(CAN_FILTER_MSG_MCS19_RELAY), // Filter 0
    MCP2515_FILTER(CAN_FILTER_MSG_MCS19_STATE), // Filter 0
    MCP2515_FILTER(CAN_FILTER_MSG_MT19_STATE),  // Filter 1
    MCP2515_FILTER(CAN_FILTER_MSG_MT19_RPM),    // Filter 1

    MCP2515_FILTER(CAN_MASK_MSC19),             // Mask 0 (for group 0)
    MCP2515_FILTER(CAN_MASK_MCS17),             // Mask 1 (for group 1)
};
// You can receive 11 bit identifiers with either group 0 or 1.


#endif /* ifndef CAN_FILTERS_H */

#include "can_app.h"

/**
 * @brief Prints a can message via usart
 */
inline void can_app_print_msg(can_t *msg)
{
#ifdef USART_ON
    usart_send_string("ID: ");
    usart_send_uint16(msg->id);
    usart_send_string(". D: ");

    for(uint8_t i = 0; i < msg->length; i++){
      usart_send_uint16(msg->data[i]);
      usart_send_char(' ');
    }

    usart_send_string(". ERR: ");
    can_error_register_t err = can_read_error_register();
    usart_send_uint16(err.rx);
    usart_send_char(' ');
    usart_send_uint16(err.tx);
    usart_send_char('\n');
#endif
}

/**
* @brief Manages the canbus application protocol
*/
inline void can_app_task(void)
{
    // check_can();
 
 
    if(can_app_send_state_clk_div++ >= CAN_APP_SEND_STATE_CLK_DIV){
#ifdef USART_ON
        VERBOSE_MSG_CAN_APP(usart_send_string("state msg was sent.\n"));
#endif
        can_app_send_state();
        can_app_send_state_clk_div = 0;
    }

    if(can_app_send_motor_clk_div++ >= CAN_APP_SEND_MOTOR_CLK_DIV)
    {
#ifdef USART_ON
        VERBOSE_MSG_CAN_APP(usart_send_string("motor msg was sent.\n"));
#endif
        can_app_send_motor();
        can_app_send_motor_clk_div = 0;
    }

    if(can_app_send_mcs_clk_div++ >= 10)
    {
        can_app_send_mcs_clk_div = 0;
        can_app_send_mcs();
#ifdef USART_ON
        VERBOSE_MSG_CAN_APP(usart_send_string("boat msg was sent.\n"));
#endif
    }

}

inline void can_app_send_state(void)
{
    can_t msg;
    msg.id                                  = CAN_FILTER_MSG_MIC17_STATE;
    msg.length                              = CAN_LENGTH_MSG_STATE;
    msg.flags.rtr = 0;

    msg.data[CAN_SIGNATURE_BYTE]            = CAN_SIGNATURE_SELF;
    msg.data[CAN_STATE_MSG_STATE_BYTE]      = (uint8_t) state_machine;
    msg.data[CAN_STATE_MSG_ERROR_BYTE]      = error_flags.all;

    can_send_message(&msg);
    VERBOSE_MSG_CAN_APP(can_app_print_msg(&msg));
}

inline void can_app_send_motor(void)
{
    
    can_t msg;
    msg.id                                      = CAN_FILTER_MSG_MIC17_MOTOR;
    msg.length                                  = CAN_LENGTH_MSG_MIC17_MOTOR;
    msg.flags.rtr = 0;

    msg.data[CAN_SIGNATURE_BYTE]                = CAN_SIGNATURE_SELF;

    controller_power_channel_t active_power_channel = controller_power_channel_active_channel_name();
    uint8_t motor_d_raw;

    if(active_power_channel == controller_power_channel_normal_name){
        motor_d_raw = controller_power_channel_normal_value();
    }else{
        motor_d_raw = controller_power_channel_turbo_value();
    }

    msg.data[CAN_MSG_MIC17_MOTOR_D_RAW_BYTE]    = motor_d_raw;

    /********* TESTE COM O MAM ACIONADO CONSTANTEMENTE **********/
    msg.data[CAN_MSG_MIC17_MOTOR_I_RAW_BYTE]    = 10;
    msg.data[CAN_MSG_MIC17_MOTOR_MOTOR_ON_BYTE] |= (1 << CAN_MSG_MIC17_MOTOR_MOTOR_ON_BIT);
    msg.data[CAN_MSG_MIC17_MOTOR_DMS_BYTE]      |= (1 << CAN_MSG_MIC17_MOTOR_DMS_BIT);
    /************************************************************/

    can_send_message(&msg);
    VERBOSE_MSG_CAN_APP(can_app_print_msg(&msg));
}


inline void can_app_send_mcs(void)
{
    can_t msg;

    msg.id                                  = CAN_FILTER_MSG_MIC17_MCS;
    msg.length                              = CAN_LENGHT_MSG_MIC17_MCS;

    for(uint8_t i = msg.length; i; i--)     msg.data[i-1] = 0;

    msg.data[CAN_SIGNATURE_BYTE]            = CAN_SIGNATURE_SELF;
    msg.data[CAN_MSG_MIC17_MCS_BOAT_ON_BYTE] = 0xFF; 

    can_send_message(&msg); 
    VERBOSE_MSG_CAN_APP(can_app_print_msg(&msg));
} 

/**
 * @brief redirects a specific message extractor to a given message
 * @param *msg pointer to the message to be extracted
 */
inline void can_app_msg_extractors_switch(can_t *msg)
{

    #ifdef CAN_DEPENDENT
    if(msg->data[CAN_SIGNATURE_BYTE] == CAN_SIGNATURE_MIC17)
    {
        can_app_checks_without_mic17_msg = 0;
    }
    #endif
}

/**
 * @brief Manages to receive and extract specific messages from canbus
 */
inline void check_can(void)
{
    
#ifdef CAN_DEPENDENT
      if(can_app_checks_without_mic17_msg++ >= CAN_APP_CHECKS_WITHOUT_MIC17_MSG){
#ifdef USART_ON
        VERBOSE_MSG_CAN_APP(usart_send_string("Error: too many cycles without message.\n"));
#endif
        can_app_checks_without_mic17_msg = 0;
        error_flags.no_canbus = 1;
        set_state_error();
      }
#endif

    if(can_check_message()){
        can_t msg;
        if(can_get_message(&msg)){
            can_app_msg_extractors_switch(&msg);
        }
    }
}

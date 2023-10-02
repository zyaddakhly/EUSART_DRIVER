/* 
 * File:   application.c
 * Author: zyadi
 *
 * Created on August 18, 2023, 8:01 AM
 */

/*---------------------------Section Include-----------------------------------------------*/
#include "application.h"

/*---------------------------Function Declaration -----------------------------------------------*/
void application_init(void);
void tx(void);
void rx(void);
uint8 data  = 0;
usart_t usart = 
{
    .baudrate = 9600,
    .baudrate_gen_config = BAUDRATE_ASYN_8BIT_LOW_SPEED,
    
    .usart_tx_cfg.usart_tx_enable = EUSART_ASYNCHRONOUS_TX_ENABLE,
    .usart_tx_cfg.usart_tx_interrupt_enable = EUSART_ASYNCCHRONOUS_INTERRUPT_TX_ENABLE ,
    .usart_tx_cfg.usart_tx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_TX_DISABLE,
    
    .usart_rx_cfg.usart_rx_enable = EUSART_ASYNCHRONOUS_RX_ENABLE,
    .usart_rx_cfg.usart_rx_interrupt_enable = EUSART_ASYNCCHRONOUS_INTERRUPT_RX_ENABLE,
    .usart_rx_cfg.usart_rx_9bit_enable = EUSART_ASYNCHRONOUS_9Bit_RX_DISABLE,
    
    .ESART_FramingErrorInterruptHandler = NULL,
    .ESART_OverrunErrorInterruptHandler = NULL,
    .ESART_RxDefaultInterruptHandler = rx,
    .ESART_TxDefaultInterruptHandler = NULL,
    
    
};

/*--------------------------- Global Variable -----------------------------------------------*/
Std_ReturnType ret;
uint8 data;




int main() {
    
     ret = EUSART_Init(&usart);
     application_init();

    while(1)
    {
          
      
           
      

    }
  


    return 0;
}



void application_init(void)
{
    Std_ReturnType ret = E_OK;
    ecu_initialize();


}


void rx(void)
{
    __delay_ms(250);
    EUSART_ReadByeNonBlocking(&data);
    if(data == 'a')
    {
        ret = led_turn_on(&led);
        ret = EUSART_WriteByeBlocking('c');
    }
    if( data == 'b')
    {
        ret = led_turn_off(&led);
        ret = EUSART_WriteByeBlocking('d');


    }
    
}

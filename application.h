/* 
 * File:   application.h
 * Author: zyadi
 *
 * Created on August 18, 2023, 8:00 AM
 */

#ifndef APPLICATION_H
#define	APPLICATION_H
#include "ECU_Layer/ecu_initialize.h"
#include "MCAL_Layer/interrupt/mcal_external_interrupt.h"

extern lcd_4bit_t lcd_1;
extern dc_motor_t motor1 ;
extern dc_motor_t motor2 ;
extern led_t led;
extern ccp2_t _ccp2;
extern ccp1_t _ccp1;


#endif	/* APPLICATION_H */


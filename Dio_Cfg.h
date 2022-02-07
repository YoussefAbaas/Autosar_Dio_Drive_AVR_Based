/*
 * Dio_Cfg.h
 *
 *  Created on: Feb 5, 2022
 *      Author: Yousif
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_
/***************************** PreCompile_Configuration *****************************/

/* Pre-compile option for Development Error Detect */
#define DIO_DEV_ERROR_DETECT                (STD_ON)

/*Adds / removes the service Dio_FlipChannel() from the code.*/
#define Dio_Flip_Channel_Api                (STD_ON)

/*Adds / removes the service Dio_GetVersionInfo() from the code.*/
#define Dio_Version_Info_Api                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNLES             (4U)

/* DIO Configured Port ID's  */
#define DioConf_LED1_PORT_NUM                (Dio_PortType)1 /* PORTA */
#define DioConf_LED2_PORT_NUM                (Dio_PortType)1 /* PORTA */
#define DioConf_SW1_PORT_NUM                 (Dio_PortType)2 /* PORTB */
#define DioConf_SW2_PORT_NUM                 (Dio_PortType)2 /* PORTB */

/* DIO Configured Channel ID's */
#define DioConf_LED1_CHANNEL_NUM             (Dio_ChannelType)1
#define DioConf_LED2_CHANNEL_NUM             (Dio_ChannelType)2
#define DioConf_SW1_CHANNEL_NUM              (Dio_ChannelType)3
#define DioConf_SW2_CHANNEL_NUM              (Dio_ChannelType)4


#endif /* DIO_CFG_H_ */

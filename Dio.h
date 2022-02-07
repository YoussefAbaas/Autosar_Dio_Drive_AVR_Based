/*
 * Dio.h
 *
 *  Created on: Feb 5, 2022
 *      Author: Yousif
 */

#ifndef DIO_H_
#define DIO_H_

#include "Std_Types.h"
#include "Dio_Cfg.h"

/*Company Id in Autosar*/
#define DIO_VENDOR_ID    (1000U)

/* Dio Module Id */
#define DIO_MODULE_ID    (120U)

/* Dio Instance Id */
#define DIO_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define DIO_SW_MAJOR_VERSION           (1U)
#define DIO_SW_MINOR_VERSION           (0U)
#define DIO_SW_PATCH_VERSION           (0U)

/************************************ Types_Definitions ********************************/

/* numeric id of dio channel */
typedef uint8 Dio_ChannelType;

/* numeric id of dio port */
typedef uint8 Dio_PortType;

typedef struct
{
	uint8 mask;
	uint8 offset;
	Dio_PortType port;
}Dio_ChannelGroupType;

/*possible levels a DIO channel*/
typedef uint8 Dio_LevelType;
/*Dio_PortLevelType inherits the size of the largest port*/
typedef uint8 Dio_PortLevelType;
typedef struct
{
	/* Member contains the ID of the Port that this channel belongs to */
	Dio_PortType Port_Num;
	/* Member contains the ID of the pin that this channel belongs to */
	Dio_ChannelType Pin_Num;
	/* Member contains the ID of the Channel*/
	Dio_ChannelType Ch_Num;
}Dio_ConfigChannel;

extern Dio_ConfigChannel PinsArr [DIO_CONFIGURED_CHANNLES];
/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for DIO read Channel */
#define DIO_READ_CHANNEL_SID           (uint8)0x00

/* Service ID for DIO write Channel */
#define DIO_WRITE_CHANNEL_SID          (uint8)0x01

/* Service ID for DIO GetVersionInfo */
#define DIO_GET_VERSION_INFO_SID       (uint8)0x12

/* Service ID for DIO flip Channel */
#define DIO_FLIP_CHANNEL_SID           (uint8)0x11

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* DET code to report Invalid Channel */
#define DIO_E_PARAM_INVALID_CHANNEL_ID (uint8)0x0A

/* Dio_Init API service called with NULL pointer parameter */
#define DIO_E_PARAM_CONFIG             (uint8)0x10

/* DET code to report Invalid Port */
#define DIO_E_PARAM_INVALID_PORT_ID    (uint8)0x14

/* DET code to report Invalid Channel Group */
#define DIO_E_PARAM_INVALID_GROUP      (uint8)0x1F

/*
 * The API service shall return immediately without any further action,
 * beside reporting this development error.
 */
#define DIO_E_PARAM_POINTER             (uint8)0x20

/*
 * API service used without module initialization is reported using following
 * error code (Not exist in AUTOSAR 4.0.3 DIO SWS Document.
 */
#define DIO_E_UNINIT                   (uint8)0xF0
/************************************ Functions Prototypes ********************************/

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId );
void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level );
Dio_PortLevelType Dio_ReadPort( Dio_PortType PortId );
void Dio_WritePort( Dio_PortType PortId, Dio_PortLevelType Level );
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId);
void Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo );



#endif /* DIO_H_ */

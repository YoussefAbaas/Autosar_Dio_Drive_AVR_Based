/*
 * Dio.c
 *
 *  Created on: Feb 5, 2022
 *      Author: Yousif
 */

#include "Dio.h"
#include "Common_Macros.h"
#include "avr/io.h"


/*************** Functions Definition ***************/

Dio_LevelType Dio_ReadChannel( Dio_ChannelType ChannelId )
{
	volatile uint8* Pin_Ptr=NULL_PTR;
	Dio_LevelType Level=STD_LOW;
		for(int i=0;i<DIO_CONFIGURED_CHANNLES;i++)
		{
			if(PinsArr[i].Ch_Num==ChannelId)
			{
				switch(PinsArr[i].Port_Num)
				{
				case 1:Pin_Ptr=&PINA;break;
				case 2:Pin_Ptr=&PINB;break;
				case 3:Pin_Ptr=&PINC;break;
				case 4:Pin_Ptr=&PIND;break;
				}
			if(BIT_IS_SET(*Pin_Ptr,PinsArr[i].Pin_Num))
				Level=STD_HIGH;
			else
				Level=STD_LOW;
			}
		}
	/*error in channel id (DET)*/
#if (DIO_DEV_ERROR_DETECT==STD_ON)
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_READ_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
		return Level;

}

void Dio_WriteChannel( Dio_ChannelType ChannelId, Dio_LevelType Level )
{
	volatile uint8* Port_Ptr=NULL_PTR;
	volatile uint8* DDR_Ptr=NULL_PTR;
	for(int i=0;i<DIO_CONFIGURED_CHANNLES;i++)
	{
		if(PinsArr[i].Ch_Num==ChannelId)
		{
			switch(PinsArr[i].Port_Num)
			{
			case 1:Port_Ptr=&PORTA;DDR_Ptr=&DDRA;break;
			case 2:Port_Ptr=&PORTB;DDR_Ptr=&DDRB;break;
			case 3:Port_Ptr=&PORTC;DDR_Ptr=&DDRC;break;
			case 4:Port_Ptr=&PORTD;DDR_Ptr=&DDRD;break;
			}

		if(Level==STD_HIGH)
		{
			SET_BIT(*DDR_Ptr,PinsArr[i].Pin_Num);
			SET_BIT(*Port_Ptr,PinsArr[i].Pin_Num);
		}
		else
		{
			SET_BIT(*DDR_Ptr,PinsArr[i].Pin_Num);
			CLEAR_BIT(*Port_Ptr,PinsArr[i].Pin_Num);
		}
		return ;
		}
	}
	/*error in channel (DET)*/
#if (DIO_DEV_ERROR_DETECT==STD_ON)
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_WRITE_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
}

#if (Dio_Flip_Channel_Api==STD_ON)
Dio_LevelType Dio_FlipChannel( Dio_ChannelType ChannelId )
{
	volatile uint8* Pin_Ptr=NULL_PTR;
	volatile uint8* Port_Ptr=NULL_PTR;
	Dio_LevelType Level=STD_LOW;
	for(int i=0;i<DIO_CONFIGURED_CHANNLES;i++)
		{
			if(PinsArr[i].Ch_Num==ChannelId)
			{
				switch(PinsArr[i].Port_Num)
				{
				case 1:Port_Ptr=&PORTA;Pin_Ptr=&PINA;break;
				case 2:Port_Ptr=&PORTB;Pin_Ptr=&PINB;break;
				case 3:Port_Ptr=&PORTC;Pin_Ptr=&PINC;break;
				case 4:Port_Ptr=&PORTD;Pin_Ptr=&PIND;break;
				}
			if(BIT_IS_SET(*Pin_Ptr,PinsArr[i].Pin_Num))
			{	CLEAR_BIT(*Port_Ptr,PinsArr[i].Pin_Num);
				Level=STD_LOW;
			}
			else
			{
				SET_BIT(*Port_Ptr,PinsArr[i].Pin_Num);
			    Level=STD_HIGH;
			}
			return Level;
			}
		}
	/*error in channel id (DET)*/
#if (DIO_DEV_ERROR_DETECT==STD_ON)
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_FLIP_CHANNEL_SID,DIO_E_PARAM_INVALID_CHANNEL_ID);
#endif
		return Level;

}
#endif

#if(Dio_Version_Info_Api==STD_ON)
void Dio_GetVersionInfo ( Std_VersionInfoType* VersionInfo )
{
#if(DIO_DEV_ERROR_DETECT==STD_ON)
	if(VersionInfo!=NULL_PTR)
	{
	VersionInfo->moduleID=DIO_MODULE_ID;
	VersionInfo->sw_major_version=DIO_SW_MAJOR_VERSION;
	VersionInfo->sw_minor_version=DIO_SW_MINOR_VERSION;
	VersionInfo->sw_patch_version=DIO_SW_PATCH_VERSION;
	VersionInfo->vendorID=DIO_VENDOR_ID;
	}
	else
	{
		Det_ReportError(DIO_MODULE_ID, DIO_INSTANCE_ID, DIO_GET_VERSION_INFO_SID,DIO_E_PARAM_POINTER);
	}
#endif
}
#endif


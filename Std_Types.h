/*
 * Std_Types.h
 *
 *  Created on: Feb 5, 2022
 *      Author: Yousif
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#include "Platform_Types.h"

typedef uint8 Std_ReturnType;

typedef struct
{
  uint16  vendorID;
  uint16  moduleID;
  uint8 sw_major_version;
  uint8 sw_minor_version;
  uint8 sw_patch_version;
} Std_VersionInfoType;

#define STD_LOW 0x00U
#define STD_HIGH 0x01U

#define E_OK ((Std_ReturnType)0x00U)
#define E_NOT_OK ((Std_ReturnType)0x01U)

#define STD_ACTIVE 0x01U
#define STD_NOT_ACTIVE 0x00U

#define STD_ON 0x01U
#define STD_OFF 0x00U







#endif /* STD_TYPES_H_ */

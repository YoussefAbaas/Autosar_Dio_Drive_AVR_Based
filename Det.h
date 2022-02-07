/*
 * Det.h
 *
 *  Created on: Feb 7, 2022
 *      Author: Yousif
 */

#ifndef DET_H_
#define DET_H_

#include "Std_Types.h"

extern uint16 Det_ModuleId;       /*DET module ID*/
extern uint8 Det_InstanceId;      /*DET instance ID*/
extern uint8 Det_ApiId;           /* DET API ID*/
extern uint8 Det_ErrorId;         /* DET Error ID*/

/************Functions_Prototypes**************/
Std_ReturnType Det_ReportError( uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);



#endif /* DET_H_ */

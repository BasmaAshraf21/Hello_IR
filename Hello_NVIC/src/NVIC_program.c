/*********************************************************************************/
/* Author    : Basma Ashraf                                                       */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                     */
/*********************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_voidInt(void)
{
	#define SCB_AIRCR  *((u32*)0xE000ED0C)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRUBUTION ;
}

void MNVIC_voidSetPriority(u8 Copy_PeripheralIdx , u8 Copy_u8Priority)
{

	if(Copy_PeripheralIdx < 60)
	{
		NVIC_IPR[Copy_PeripheralIdx] = Copy_u8Priority;
	}
	else
	{

	}
}

void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISER0= (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISER0= (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}


void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICER0= (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICER0= (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ISPR0= (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ISPR1= (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <= 31 )
	{
		NVIC_ICPR0= (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		NVIC_ICPR1= (1 << Copy_u8IntNumber);
	}
	else
	{
		
	}
}

u8 MNVIC_u8getActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if ( Copy_u8IntNumber <= 31 )
	{
		Local_u8Result = GET_BIT(NVIC_IABR0, Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -=32;
		Local_u8Result = GET_BIT(NVIC_IABR1, Copy_u8IntNumber);
	}
	else
	{
		
	}
	return Local_u8Result;
}

/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// Header file for Memory library for the Appointment Reservation Program

#pragma once

#include "ADT.h"

#define NUMBEROFDAYSINMONTH 30
#define ERROR -1
#define SUCCESS 0

int HeapMemoryAllocation(APPOINTMENT**);
void FreeMemory(APPOINTMENT**);
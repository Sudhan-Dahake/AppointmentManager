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

// Header file for Memory functions of appointment program
// including headerfiles and prototypes
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

#include "ADT.h"							// linking header file for ADT library

#define NUMBEROFDAYSINMONTH 30				// this constant is used to signify NUMBEROFDAYSINMONTH
#define ERROR -1							// this constant is used to signify ERROR
#define SUCCESS 0							// this constant is used to signify SUCCESS

int HeapMemoryAllocation(APPOINTMENT**);			// function declaration for HeapMemoryAllocation
void FreeMemory(APPOINTMENT**);						// function declaration for FreeMemory
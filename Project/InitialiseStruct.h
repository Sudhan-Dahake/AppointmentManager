/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// Header file for InitialiseStruct library for the Appointment Reservation Program

#pragma once

// Header file for InitialiseStruct functions of appointment program
// including headerfiles and prototypes
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

#include "ADT.h"								// linking header file for ADT library

#define ONE 1									// this constant is used to signify ONE
#define NUMBEROFDAYSINMONTH 30					// this constant is used to signify NUMBEROFDAYSINMONTH
#define NO 'N'									// this constant is used to signify NO
#define EMPTYSTRING ""							// this constant is used to signify EMPTYSTRING
#define NULLCHARACTER '\0'						// this constant is used to signify NULLCHARACTER

void InitialiseStruct(APPOINTMENT**);			// function declaration for InitialiseStruct
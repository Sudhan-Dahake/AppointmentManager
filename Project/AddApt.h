/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// Header file for AddApt library for the Appointment Reservation Program

#pragma once

// Header file for AddApt functions of appointment program
// including headerfiles and prototypes
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

#include "ADT.h"							// linking header file for ADT library

#define ONE 1								// this constant is used to signify ONE
#define MAXSIZE 20							// this constant is used to signify MAXSIZE
#define NO 'N'								// this constant is used to signify NO
#define YES 'Y'								// this constant is used to signify YES
#define NULLCHARACTER '\0'					// this constant is used to signify NULLCHARACTER
#define NUMBEROFDAYSINMONTH 30				// this constant is used to signify NUMBEROFDAYSINMONTH

void AddApt(APPOINTMENT**);					// function declaration for AddApt
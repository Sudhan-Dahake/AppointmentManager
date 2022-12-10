/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// Header file for InputValidation library for the Appointment Reservation Program

#pragma once
#include <stdio.h>
#include <stdbool.h>								// Use for boolean data type (true/false)
#include <string.h>									// Use for strlen() method

#define ASCIIZERO '0'	
#define ASCIININE '9'

bool ValidateUserInput(char*);						// A function declaration for ValidateUserInput
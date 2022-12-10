/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// implementation of InputValidation library for the Appointment Reservation Program


#include "InputValidation.h"							// Header file for validation library
#include <stdio.h>
#include <stdbool.h>									// Use for boolean data type (true/false)
#include <string.h>										// Use for strlen () method

bool ValidateUserInput(char* userInput)					// A function that validate userInput
{
	bool isValid = true;								// Initialize isValid to true state

	// iterate through the string, it will loop if it is less than string length and isValid is true
	for (int i = 0; i < strlen(userInput) && isValid; i++)
	{

		// check each char in the string based on its ascii char between '0' to '9' which will determine that it will be an integer
		if (userInput[i] >= ASCIIZERO && userInput[i] <= ASCIININE)
		{
			isValid = true;
		}
		else
			isValid = false;
	}
	return isValid;											// Return either true or false
}
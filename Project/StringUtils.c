/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// implementation of StringUtils library for the Appointment Reservation Program

#include "StringUtils.h"										// Header file for StringUtils Library

// A function that clean out newline from string which in this case when fgets is used and replace the first \n that it sees with a null terminator '\0'
void CleanNewLineFromString(char* string)
{
	for (int i = 0; i < strlen(string); i++)				// Iterate through the string until it encounter '\n' and replace it with '\0'
	{
		if (string[i] == NEWLINECHAR)							// Newline character	
		{
			string[i] = NULLTERMINATOR;							// Null Character
		}
	}
}
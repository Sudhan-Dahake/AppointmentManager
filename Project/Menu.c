/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// implementation of Menu library for the Appointment Reservation Program

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>																		// Used for boolean datatype (true/false)
#include "Menu.h"																			// Header File for Menu Library
#include "StringUtils.h"																	// Header File for StringUtils Library
#include "AddApt.h"																			// Header File for AddApt Library
#include "DeleteApt.h"																		// Header File for DeleteApt Library
#include "UpdateApt.h"																		// Header File for UpdateApt Library
#include "DisplayFunctions.h"																// Header File for DisplayFunctions Library
#include "SearchApt.h"																		// Header File for SearchApt Library
#include "InputValidation.h"																// Header File for InputValidation Library

// A Print Main Menu that display options for Appointment Booking System Menu
void PrintMainMenu(void)
{
	fputs("************************************************\n", stdout);
	fputs("   Welcome to Appointment Booking System Menu!\n", stdout);
	fputs("************************************************\n\n", stdout);
	fputs("1) Add a new appointment\n", stdout);
	fputs("2) Delete an existing appointment\n", stdout);
	fputs("3) Update an existing appointment\n", stdout);
	fputs("4) Display a single appointment\n", stdout);
	fputs("5) Display a range appointment\n", stdout);
	fputs("6) Display all appointment\n", stdout);
	fputs("7) Search for an appointment\n", stdout);
	fputs("8) Quit\n\n", stdout);
	fputs("Please choose one of the following option from 1 to 8\n", stdout);
	fputs("Option: ", stdout);
}


// Load Menu and Get User Input for menu option
void GetUserMenuOption(APPOINTMENT** ptrToHead)
{
	// declare temp variables
	char tempUserChoice[MAXSIZE];
	int userChoice = 0;
	bool isValid = false;

	do
	{
		// Print Out the Menu prior to prompting user for user choice
		PrintMainMenu();

		scanf("%s", tempUserChoice);

		// Validate User choice if it is number by comparing each character with an ascii char '0' to '9' which would return true, else false
		isValid = ValidateUserInput(tempUserChoice);

		// If User Choice is a valid number (int) then it can access the menu function (option) from 1 to 8, else it will return back to the main menu and reprompt user for choice unless they choose option 8 which would exit the program.
		if (isValid)
		{
			// Convert tempUserChoice which is a string and return an integer value
			userChoice = atoi(tempUserChoice);

			// Switch case statement that will go to specific case to perform function depending on user choice
			// It acts as an appointment menu
			// Case 1 to 7 will recieve double pointer ptrToHead that will later be used to perform various operations
			switch (userChoice)
			{
			case 1:
				// 1) add a new appt
				AddApt(ptrToHead);
				break;

			case 2:
				// 2) Delete an existing appt
				DeleteApt(ptrToHead);
				break;

			case 3:
				// 3) Update an existing appt
				UpdateApt(ptrToHead);
				break;

			case 4:
				// 4) Display single appt
				DisplaySingleApt(ptrToHead);
				break;

			case 5:
				// 5) Display all appt
				DisplayRangeApt(ptrToHead);
				break;

			case 6:
				// 6) Display all appt
				DisplayAllApt(ptrToHead);
				break;

			case 7:
				// 7) Search for appt
				SearchApt(ptrToHead);
				break;

			case 8:
				// 8) Quit
				printf("******** Thank you for Choosing Us! ********\n");
				break;

			default:
				printf("Invalid Entry! Please enter only one of the option from 1 to 8!\n\n");
			}
		}
		else
			printf("Invalid Entry! Please enter only one of the option from 1 to 8!\n\n");

	} while (userChoice != 8);								// If the User Choice is 8 then it will exit out of the loop

}
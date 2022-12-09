#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include "Menu.h"
#include "StringUtils.h"
#include "AddApt.h"
#include "DeleteApt.h"
#include "UpdateApt.h"
#include "DisplayFunctions.h"
#include "SearchApt.h"
#include "TextFile.h"
#include "InputValidation.h"

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

	char tempUserChoice[MAXSIZE];
	int userChoice = 0;
	char userFirstNameBuf[MAXSIZE];
	char userLastNameBuf[MAXSIZE];

	bool isValid = false;
	bool isExit = false;

	do
	{
		PrintMainMenu();

		scanf("%s", tempUserChoice);

		CleanNewLineFromString(tempUserChoice);

		isValid = ValidateUserInput(tempUserChoice);

		if (isValid)
		{
			userChoice = atoi(tempUserChoice);
		}


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
			puts("Please Enter your names to search for an existing appointment!");
			printf("First Name: ");
			scanf("%s", userFirstNameBuf);
			printf("Last Name: ");
			scanf("%s", userLastNameBuf);
			SearchApt(ptrToHead, userFirstNameBuf, userLastNameBuf);
			break;

		case 8:
			// 8) Quit
				// SaveToDisk Before Quit
			SaveAptToDisk(ptrToHead);
			isExit = true;
			printf("******** Thank you for Choosing Us! ********\n");
			break;

		default:
			printf("Invalid Entry! Please enter only one of the option from 1 to 8!\n\n");
		}

	} while (!isExit);

}
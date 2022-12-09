/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// implementation of SearchApt library for the Appointment Reservation Program

#define _CRT_SECURE_NO_WARNINGS
#include "SearchApt.h"												// Header File for SearchApt Library
#include "StringUtils.h"											// Header File for StringUtils Library

// A function that search for an appointment based on user first name and last name
void SearchApt(APPOINTMENT** ptrToHead)
{
	// Declare buffer variables
	char userFirstNameBuf[MAXSIZE]; 
	char userLastNameBuf[MAXSIZE];
	
	puts("Please Enter your names to search for an existing appointment!");

	// Prompt User for their First Name
	printf("\nFirst Name: ");
	scanf("%s", userFirstNameBuf);
	CleanNewLineFromString(userFirstNameBuf);						// Clean String to ensure that there is a null terminator

	// Prompt User for their Last Name
	printf("\nLast Name: ");
	scanf("%s", userLastNameBuf);
	CleanNewLineFromString(userLastNameBuf);						// Clean String to ensure that there is a null terminator

	bool isFound = false;

	// Not neccessary but incase if it was trying to read when the link is empty then it will exit
	if (ptrToHead == NULL)
	{
		puts(" Appointment sheet is empty. No appointment to search!");
		exit(EXIT_FAILURE);
	}

	// A temp pointer is declared with the prtToHead to be used to act as a temp Pointer we iterate through the link list nodes
	APPOINTMENT* temp = *ptrToHead;

	printf("\n %10s \t %10s \t %10s \n\n", "Date", "First Name", "Last Name");

	// Iterate until temp Pointer becomes NULL which means it is at the end the linked list
	while (temp != NULL)
	{
		// Compare both firstName and lastName with the requested FirstName and LastName
		if ((strcmp(temp->FirstName, userFirstNameBuf) == ZERO) && (strcmp(temp->LastName, userLastNameBuf) == ZERO))
		{
			printf(" %10d \t %10s \t %10s \n\n", temp->Date, temp->FirstName, temp->LastName);
			isFound = true;
		}

		// Temp Pointer will now point to the next (address) node
		temp = temp->Next;
	}

	// if no matching names are found through the linked list nodes then it will print a message to the user
	if (!isFound)
	{
		puts(" No matching name in any existing appointment!\n");
	}

}
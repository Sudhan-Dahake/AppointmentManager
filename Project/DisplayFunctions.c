// Source file for display functions of appointment program
// coding the work for the main program
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

#include "DisplayFunctions.h"

// writing function source code		<-- Work done by Owen

void DisplaySingleApt(APPOINTMENT** ptrToHead)
{
	// declare temporary values for use inside function locally
	int userChoice;
	bool userInputLoop = true;

	APPOINTMENT* temp = *ptrToHead;

	while (userInputLoop)
	{
		// could put user input function and validation function 
		printf("Please enter which appointment you would like to view by date (1-30):");
		if (scanf("%d", &userChoice) && userChoice <= DAYSINMONTH)
			userInputLoop = false;
		else
			printf("Invalid input...\n");
	}

	// loop to find the desired appointment date
	for (int i = 0; i < userChoice - ONE; i++) {
		temp = temp->Next;
	}

	// print the information depending on taken or not
	if (temp->AppointmentTaken == YES)
		printf("Date: %d, Appointment taken: %c, Name: %9s, %9s\n", temp->Date, temp->AppointmentTaken, temp->LastName, temp->FirstName);
	else
		printf("Date: %d, Appointment taken: %c\n", temp->Date, temp->AppointmentTaken);

}

void DisplayRangeApt(APPOINTMENT** ptrToHead)
{
	// declare temporary values for use inside function locally
	int userChoice1;
	int userChoice2;
	bool userInputLoop = true;
	APPOINTMENT* temp = *ptrToHead;

	while (userInputLoop)
	{
		//ask for range numbers and validate them
		printf("Please enter a lower limit (1-30):");
		if (scanf("%d", &userChoice1) && userChoice1 <= DAYSINMONTH && userChoice1 >= ONE)
			userInputLoop = false;
		else
			printf("Invalid input...\n");

		printf("Please enter an upper limit (1-30):");
		if (scanf("%d", &userChoice2) && userChoice2 <= DAYSINMONTH && userChoice2 >= ONE && !userInputLoop)
			userInputLoop = false;
		else
		{
			userInputLoop = true;
			printf("Invalid input...\n");
		}

		if (userChoice1 > userChoice2)
		{
			userInputLoop = true;
			printf("Invalid range...");
		}
	}

	// loop to find the lower limit appointment date
	for (int i = 0; i < userChoice1 - ONE; i++) {
		temp = temp->Next;
	}

	printf("Here is the list for the selected range of appointments:\n");
	// loop until reached upper limit appointment date
	for (int i = userChoice1 - ONE; i < userChoice2; i++)
	{
		// print the information depending on taken or not
		if (temp->AppointmentTaken == YES)
			printf("Date: %d, Appointment taken: %c, %9s, %9s\n", temp->Date, temp->AppointmentTaken, temp->LastName, temp->FirstName);
		else
			printf("Date: %d, Appointment taken: %c\n", temp->Date, temp->AppointmentTaken);

		// increment listnode to move onto next appointment
		temp = temp->Next;
	}
}

void DisplayAllApt(APPOINTMENT** ptrToHead)
{
	// declare temporary values for use inside function locally
	APPOINTMENT* temp = *ptrToHead;

	printf("Here is the list of all current appointments:\n");

	// Loop through all 30 possible appointments
	for (int i = 0; i < DAYSINMONTH; i++)
	{
		// print the information depending on taken or not
		if (temp->AppointmentTaken == YES)
			printf("Date: %d, Appointment taken: %c, %9s, %9s\n", temp->Date, temp->AppointmentTaken, temp->LastName, temp->FirstName);
		else
			printf("Date: %d, Appointment taken: %c\n", temp->Date, temp->AppointmentTaken);

		// increment listnode to move onto next appointment
		temp = temp->Next;
	}
}
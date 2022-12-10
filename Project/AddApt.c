// Source file for AddApt functions of appointment program
// coding the work for the main program
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

// functions	<-- Work done by Sudhan

#define _CRT_SECURE_NO_WARNINGS							// allows us to ignore unsafe warnings

#include "AddApt.h"										// Header file for AddApt library

void AddApt(APPOINTMENT** ptrToHead) {					// an AddApt function is created that takes 1 parameters a pointer of type APPOINTMENT*. It returns nothing.

	int aptDate;										// used to store user inputted date

	char firstName[MAXSIZE];							// these strings would be used to store user's first and last name
	firstName[MAXSIZE - 1] = NULLCHARACTER;

	char lastName[MAXSIZE];
	lastName[MAXSIZE - 1] = NULLCHARACTER;

	APPOINTMENT* temp = *ptrToHead;						// a variable of type APPOINTMENT* is initialised and is given the value that the pointer ptrToHead points to.

	printf("Please enter the Date on which you want Appointment: ");
	scanf("%d", &aptDate);													// asking the user for date and storing it in variable aptDate

	printf("\n");

	if (aptDate <= NUMBEROFDAYSINMONTH && aptDate >= ONE) {					// this is done for input validation, to make sure user enters values between 1 and 30 only

		for (int i = 0; i < aptDate - ONE; i++) {							// - ONE because temp is already pointing at the first node

			temp = temp->Next;
		}

		if (temp->AppointmentTaken == NO && temp->Date == aptDate) {			// if the date inside node and the date chosen by user is same and the node is empty then this block gets executed

			printf("Please enter your First Name: ");
			scanf("%s", firstName);												// asking for first and last names

			printf("Please enter your Last Name: ");
			scanf("%s", lastName);

			temp->AppointmentTaken = YES;										// setting the marker to YES

			strncpy(temp->FirstName, firstName, MAXSIZE);						// setting first and last names in the node to user inputted values
			temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

			strncpy(temp->LastName, lastName, MAXSIZE);
			temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

			printf("\nSuccessfully Scheduled Appointment!\n");					// upon successfull scheduling of appointment this msg is printed
		}
		else {

			printf("\nThe Appointment is already given to someone!\n");			// this is printed when the user choses a date that is already taken
		}
	}
	else {

		printf("\nInvalid Entry!\n");											// if the user enters anything other than values between 1 and 30 then this msg gets printed
	}
}
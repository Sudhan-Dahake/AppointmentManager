// Source file for DeleteApt functions of appointment program
// coding the work for the main program
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

// functions	<-- Work done by Sudhan

#define _CRT_SECURE_NO_WARNINGS						// allows us to ignore unsafe warnings
#include "DeleteApt.h"								// Header file for DeleteApt library

#include <stdio.h>									// is a header file that contains information to include the input/output related functions in our program
#include <string.h>									// allows us to use string functions

void DeleteApt(APPOINTMENT** ptrToHead) {			// an AddApt function is created that takes 1 parameters a pointer of type APPOINTMENT*. It returns nothing.

	int dateApt;									// used to store user inputted date

	APPOINTMENT* temp = *ptrToHead;					// a variable of type APPOINTMENT* is initialised and is given the value that the pointer ptrToHead points to.

	printf("Enter the Date on which you wanna Cancel appointment: ");
	scanf("%d", &dateApt);												// asking the user for date and storing it in variable dateApt

	if (dateApt <= NUMBEROFDAYSINMONTH && dateApt >= ONE) {				// this is done for input validation, to make sure user enters values between 1 and 30 only

		for (int i = 0; i < dateApt - ONE; i++) {						// - ONE because temp is already pointing at the first node

			temp = temp->Next;											// going to the node that the user requested
		}

		if (temp->AppointmentTaken == YES && temp->Date == dateApt) {		// if the date inside node and the date chosen by user is same and the node is not empty then this block gets executed

			temp->AppointmentTaken = NO;									// setting the marker to NO

			strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);					// setting first and last names in the node to user inputted values
			temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

			strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
			temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

			printf("\nSuccessfully Cancelled Appointment!\n");				// upon successfull deletion of appointment this msg is printed
		}
		else {

			printf("\nThere is no Appointment on that Day!\n");				// this is printed if the user chooses a date on which there was no appointment
		}
	}
	else {

		printf("\nInvalid Entry!\n");										// if the user enters anything other than values between 1 and 30 then this msg gets printed
	}
}
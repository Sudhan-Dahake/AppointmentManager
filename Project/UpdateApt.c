// Source file for UpdateApt functions of appointment program
// coding the work for the main program
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

// functions	<-- Work done by Sudhan

#define _CRT_SECURE_NO_WARNINGS							// allows us to ignore unsafe warnings

#include "UpdateApt.h"									// Header file for AddApt library

#include <stdio.h>										// is a header file that contains information to include the input/output related functions in our program
#include <string.h>										// allows us to use string functions

void UpdateApt(APPOINTMENT** ptrToHead) {				// an UpdateApt function is created that takes 1 parameters a pointer of type APPOINTMENT*. It returns nothing.

	APPOINTMENT* temp = *ptrToHead;						// a variable of type APPOINTMENT* is initialised and is given the value that the pointer ptrToHead points to.

	char firstName[MAXSIZE];							// these strings would be used to store user's first and last name
	firstName[MAXSIZE - 1] = NULLCHARACTER;

	char lastName[MAXSIZE];
	lastName[MAXSIZE - 1] = NULLCHARACTER;

	int newApt;											// used to store user inputted date

	bool haveAppointment = false;						// this checks if the person had existing appointment or not

	printf("Please enter the Date for New Appointment: ");
	scanf("%d", &newApt);											// asking the user for date and storing it in variable newDate

	if (newApt <= NUMBEROFDAYSINMONTH && newApt >= ONE) {			// this is done for input validation, to make sure user enters values between 1 and 30 only

		printf("Please enter your First Name: ");					// asking the user for names
		scanf("%s", firstName);

		printf("Please enter your Last Name: ");
		scanf("%s", lastName);

		for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {					// looping through the linked list

			if (!strncmp(temp->FirstName, firstName, MAXSIZE) && !strncmp(temp->LastName, lastName, MAXSIZE)) {			// if we find a node which has first and last name exactly similar to user inputted names then this block gets executed

				temp->AppointmentTaken = NO;							// the marker is set to NO

				strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);
				temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;			// the first and last name strings are cleared

				strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
				temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

				haveAppointment = true;									// set to true as it's confirmed that the user had previous appointment
			}
			else {

				temp = temp->Next;										// if the previous node does not match then we go to next node	
			}
		}

		temp = *ptrToHead;												// setting temp to point to the value that ptrToHead points to

		for (int j = 0; j < newApt - ONE; j++) {						// - ONE because temp is already pointing at the first node 

			temp = temp->Next;
		}

		if (temp->AppointmentTaken == NO && temp->Date == newApt) {				// if the date inside node and the date chosen by user is same and the node is empty then this block gets executed

			temp->AppointmentTaken = YES;										// setting the marker to YES

			strncpy(temp->FirstName, firstName, MAXSIZE);
			temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;						// setting first and last names in the node to user inputted values

			strncpy(temp->LastName, lastName, MAXSIZE);
			temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

			printf("\nSuccessfully Updated Appointment!\n");					// upon successfull updating of appointment this msg is printed
		}
		else if (!haveAppointment) {
																				// if user did not have any appointment then this block gets executed
			printf("\nYou do not have any appointments in the first place!\n");
		}
		else {

			printf("\nThe Appointment is already assigned to someone!\n");		// this is printed when the user choses a date that is already taken
		}
	}
	else {

		printf("\nInvalid Entry!\n");											// if the user enters anything other than values between 1 and 30 then this msg gets printed
	}
}
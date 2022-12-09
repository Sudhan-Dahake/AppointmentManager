/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// implementation of UpdateApt library for the Appointment Reservation Program

#define _CRT_SECURE_NO_WARNINGS

#include "UpdateApt.h"

#include <stdio.h>
#include <string.h>

void UpdateApt(APPOINTMENT** ptrToHead) {

	APPOINTMENT* temp = *ptrToHead;

	char firstName[MAXSIZE];
	firstName[MAXSIZE - 1] = NULLCHARACTER;

	char lastName[MAXSIZE];
	lastName[MAXSIZE - 1] = NULLCHARACTER;

	int newApt;

	printf("Please enter the Date for New Appointment: ");
	scanf("%d", &newApt);

	printf("Please enter your First Name: ");
	scanf("%s", firstName);

	printf("Please enter your Last Name: ");
	scanf("%s", lastName);

	for(int i = 0; i < NUMBEROFDAYSINMONTH; i++) {

		if (!strncmp(temp->FirstName, firstName, MAXSIZE) && !strncmp(temp->LastName, lastName, MAXSIZE)) {

			temp->AppointmentTaken = NO;

			strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);
			temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

			strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
			temp->LastName[MAXSIZE - 1] = NULLCHARACTER;
		}
		else {

			temp = temp->Next;
		}
	}

	temp = *ptrToHead;

	for(int j = 0; j < newApt - ONE; j++) {

		temp = temp->Next;
	}

	if (temp->AppointmentTaken == NO && temp->Date == newApt) {

		temp->AppointmentTaken = YES;

		strncpy(temp->FirstName, firstName, MAXSIZE);
		temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

		strncpy(temp->LastName, lastName, MAXSIZE);
		temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

		printf("Successfully Updated Appointment!\n");
	}
	else {

		printf("The Appointment is already assigned to someone!\n");
	}
}
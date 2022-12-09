/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// implementation of DeleteApt library for the Appointment Reservation Program

#define _CRT_SECURE_NO_WARNINGS
#include "DeleteApt.h"

#include <stdio.h>
#include <string.h>

void DeleteApt(APPOINTMENT** ptrToHead) {

	int dateApt;

	APPOINTMENT* temp = *ptrToHead;

	printf("Enter the Date on which you wanna Cancel appointment: ");
	scanf("%d", &dateApt);

	for (int i = 0; i < dateApt - ONE; i++) {

		temp = temp->Next;
	}

	if (temp->AppointmentTaken == YES && temp->Date == dateApt) {

		temp->AppointmentTaken = NO;

		strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);
		temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

		strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
		temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

		printf("Successfully Cancelled Appointment!\n");
	}
	else {

		printf("There is no Appointment on that Day!\n");
	}
}
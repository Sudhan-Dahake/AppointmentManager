#define _CRT_SECURE_NO_WARNINGS

#include "AddApt.h"

void AddApt(APPOINTMENT** ptrToHead) {

	int aptDate;

	char firstName[MAXSIZE];
	firstName[MAXSIZE - 1] = NULLCHARACTER;

	char lastName[MAXSIZE];
	lastName[MAXSIZE - 1] = NULLCHARACTER;

	APPOINTMENT* temp = *ptrToHead;

	printf("Please enter the Date on which you want Appointment: ");
	scanf("%d", &aptDate);

	printf("\n");

	if (aptDate <= NUMBEROFDAYSINMONTH && aptDate >= ONE) {

		for (int i = 0; i < aptDate - ONE; i++) {

			temp = temp->Next;
		}

		if (temp->AppointmentTaken == NO && temp->Date == aptDate) {

			printf("Please enter your First Name: ");
			scanf("%s", firstName);

			printf("Please enter your Last Name: ");
			scanf("%s", lastName);

			temp->AppointmentTaken = YES;

			strncpy(temp->FirstName, firstName, MAXSIZE);
			temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

			strncpy(temp->LastName, lastName, MAXSIZE);
			temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

			printf("\nSuccessfully Scheduled Appointment!\n");
		}
		else {

			printf("\nThe Appointment is already given to someone!\n");
		}
	}
	else {

		printf("\nInvalid Entry!\n");
	}
}
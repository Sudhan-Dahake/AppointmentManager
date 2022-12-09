#define _CRT_SECURE_NO_WARNINGS
#include "DeleteApt.h"

#include <stdio.h>
#include <string.h>

void DeleteApt(APPOINTMENT** ptrToHead) {

	int dateApt;

	APPOINTMENT* temp = *ptrToHead;

	printf("Enter the Date on which you wanna Cancel appointment: ");
	scanf("%d", &dateApt);

	if (dateApt <= NUMBEROFDAYSINMONTH && dateApt >= ONE) {

		for (int i = 0; i < dateApt - ONE; i++) {

			temp = temp->Next;
		}

		if (temp->AppointmentTaken == YES && temp->Date == dateApt) {

			temp->AppointmentTaken = NO;

			strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);
			temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

			strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
			temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

			printf("\nSuccessfully Cancelled Appointment!\n");
		}
		else {

			printf("\nThere is no Appointment on that Day!\n");
		}
	}
	else {

		printf("\nInvalid Entry!\n");
	}
}
#include "InitialiseStruct.h"

void InitialiseStruct(APPOINTMENT** ptrToHead) {

	APPOINTMENT* temp = *ptrToHead;

	for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {

		temp->Date = i + ONE;

		strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);
		temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;

		strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
		temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

		temp->AppointmentTaken = NO;
		temp = temp->Next;
	}
}
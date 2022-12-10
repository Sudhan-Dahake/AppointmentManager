
// Source file for InitialiseStruct functions of appointment program
// coding the work for the main program
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022


// functions	<-- Work done by Sudhan

#include "InitialiseStruct.h"							// Header file for InitialiseStruct library

void InitialiseStruct(APPOINTMENT** ptrToHead) {				// a InitialiseStruct function is created that takes 1 parameters a pointer of type APPOINTMENT*. It nothing.

	APPOINTMENT* temp = *ptrToHead;								// a variable of type APPOINTMENT* is initialised and is given the value that the pointer ptrToHead points to.

	for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {				// if i is less than NUMBEROFDAYSINMONTH then the loop continues executing.

		temp->Date = i + ONE;									// initialising the value inside node, + ONE because date doesn't start from 0

		strncpy(temp->FirstName, EMPTYSTRING, MAXSIZE);			// setting the string members empty
		temp->FirstName[MAXSIZE - 1] = NULLCHARACTER;			// this is to make sure the strings are null terminated

		strncpy(temp->LastName, EMPTYSTRING, MAXSIZE);
		temp->LastName[MAXSIZE - 1] = NULLCHARACTER;

		temp->AppointmentTaken = NO;							// setting the appointmentTaken as NO, cause no appointments are taken at this stage
		temp = temp->Next;										// going to the next node
	}
}
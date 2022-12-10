// Source file
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022
// By: Sudhan Dahake, Owen Covach and Hangsihak Sin

//*********************************************************************
/*
DESIGNING A APPOINTMENT MANAGER

This appointment managers allows users to book assignments in a month
i.e. from 1st day of a month till the 30th of a month.
*/
//*********************************************************************

#define _CRT_SECURE_NO_WARNINGS					// allows us to ignore warnings
#include <stdio.h>								// is a header file that contains information to include the input/output related functions in our program

#include "ADT.h"								// linking header file for ADT library
#include "Memory.h"								// linking header file for Memory library
#include "InitialiseStruct.h"					// linking header file for InitialiseStruct library

#define NUMBEROFDAYSINMONTH 30					// this constant is used to signify NUMBEROFDAYSINMONTH
#define ERROR -1								// this constant is used to signify ERROR


int main(void) {

	APPOINTMENT* head = NULL;									// a variable of type APPOINTMENT* is initialised and set to NULL		

	int returnFromHeap = HeapMemoryAllocation(&head);			// HeapMemoryAllocation function is called that takes 1 argument, the address of the head pointer. It returns an integer value.

	if (returnFromHeap == ERROR) {								// if value returned by function is equal to ERROR then this if block gets executed

		return ERROR;											// returning the value stored in ERROR
	}

	InitialiseStruct(&head);									// InitialiseStruct function is called that takes 1 argument, the address of the head pointer. It returns nothing.

	FreeMemory(&head);											// FreeMemory function is called that takes 1 argument, the address of the head pointer. It returns nothing.

	return 0;
}
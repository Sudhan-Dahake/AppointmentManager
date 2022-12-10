
// Write an appointment reservation program
// that has multiple ooptions for the user to choose
// and saves data between runs and
// loads the data on the next run through
// 
// Assignment 6 - Project
// Owen Covach, Sudhan Dahake, Hangsihak Sin - prog71985 - fall 2022

#include "ADT.h"				// linking header file for ADT library
#include "Memory.h"				// linking header file for Memory library
#include "InitialiseStruct.h"			// linking header file for InitialiseStruct library
#include "Menu.h"				// linking header file for Menu library
#include "TextFile.h"				// linking header file for TextFile library


int main(void) {

	APPOINTMENT* head = NULL;									// a variable of type APPOINTMENT* is initialised and set to NULL		

	int returnFromHeap = HeapMemoryAllocation(&head);			// HeapMemoryAllocation function is called that takes 1 argument, the address of the head pointer. It returns an integer value.

	if (returnFromHeap == ERROR) {								// if value returned by function is equal to ERROR then this if block gets executed

		return ERROR;											// returning the value stored in ERROR
	}

	InitialiseStruct(&head);									// InitialiseStruct function is called that takes 1 argument, the address of the head pointer. It returns nothing.

	// load file to fill in appointments
	LoadAptToProgram(&head);

	// load file to fill in appointments
	LoadAptToProgram(&head);

	GetUserMenuOption(&head);

	FreeMemory(&head);                      // FreeMemory function is called that takes 1 argument, the address of the head pointer. It returns nothing.

	return 0;
}

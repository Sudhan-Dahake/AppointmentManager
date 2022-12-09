#include <stdio.h>

#include "ADT.h"
#include "Memory.h"
#include "InitialiseStruct.h"
#include "Menu.h"
#include "TextFile.h"

#define NUMBEROFDAYSINMONTH 30
#define ERROR -1

int main(void) {

	APPOINTMENT* head = NULL;

	int returnFromHeap = HeapMemoryAllocation(&head);

	if (returnFromHeap == ERROR) {

		return ERROR;
	}

	InitialiseStruct(&head);

	// load file to fill in appointments
	LoadAptToProgram(&head);

	GetUserMenuOption(&head);

	FreeMemory(&head);

	return 0;
}
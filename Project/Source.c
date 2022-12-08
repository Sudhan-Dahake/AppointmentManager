#include <stdio.h>

#include "ADT.h"
#include "Memory.h"
#include "InitialiseStruct.h"

#define NUMBEROFDAYSINMONTH 30
#define ERROR -1

int main(void) {

	APPOINTMENT* head = NULL;

	int returnFromHeap = HeapMemoryAllocation(&head);

	if (returnFromHeap == ERROR) {

		return ERROR;
	}

	InitialiseStruct(&head);

	FreeMemory(&head);
}
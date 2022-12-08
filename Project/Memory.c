#include "Memory.h"

#include <stdlib.h>
#include <stdio.h>

int HeapMemoryAllocation(APPOINTMENT** ptrToHead) {

	APPOINTMENT* temp1 = *ptrToHead;

	for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {

		temp1 = (APPOINTMENT*)malloc(sizeof(APPOINTMENT));

		if (temp1 == NULL) {

			printf("Memory Allocation Error!\n");

			return ERROR;
		}

		if (i == 0) {

			*ptrToHead = temp1;
			temp1->Next = NULL;
		}
		else {

			APPOINTMENT* temp2 = *ptrToHead;

			for (int j = 0; j <= i - 2; j++) {

				temp2 = temp2->Next;
			}

			temp2->Next = temp1;
			temp1->Next = NULL;
		}
	}

	return SUCCESS;
}

void FreeMemory(APPOINTMENT** ptrToHead) {

	for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {

		APPOINTMENT* temp = *ptrToHead;
		*ptrToHead = temp->Next;

		free(temp);

		temp = NULL;
	}
}
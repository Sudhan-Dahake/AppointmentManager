
// Source file for Memory functions of appointment program
// coding the work for the main program
//
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022


// functions	<-- Work done by Sudhan

#include "Memory.h"					// Header file for Memory library

#include <stdlib.h>					// allows us to use malloc and free
#include <stdio.h>					// is a header file that contains information to include the input/output related functions in our program

int HeapMemoryAllocation(APPOINTMENT** ptrToHead) {				// a HeapMemoryAllocation function is created that takes 1 parameters a pointer of type APPOINTMENT*. It returns an integer.

	APPOINTMENT* temp1 = *ptrToHead;							// a variable of type APPOINTMENT* is initialised and is given the value that the pointer ptrToHead points to.

	for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {				// if i is less than NUMBEROFDAYSINMONTH then the loop continues executing.

		temp1 = (APPOINTMENT*)malloc(sizeof(APPOINTMENT));			// malloc is called to find memory in heap

		if (temp1 == NULL) {										// if malloc couldn't find memory in space then error is thrown

			printf("Memory Allocation Error!\n");

			return ERROR;											// the function is exited
		}

		if (i == 0) {								// if i equals 0 then this block gets executed, this is done for initial node

			*ptrToHead = temp1;						// the pointer that ptrToHead points to is made to point to the memory that temp1 points to
			temp1->Next = NULL;						// the next section inside the node is set to NULL as there is no other node at this time
		}
		else {										// for any other node this block gets executed

			APPOINTMENT* temp2 = *ptrToHead;			// a variable of type APPOINTMENT* is initialised that points to the first node

			for (int j = 0; j <= i - 2; j++) {			// i - 2 because we need to reach the node previous to our current node

				temp2 = temp2->Next;					// this is done till temp2 reaches the node that is previous to the node temp1 points to
			}

			temp2->Next = temp1;						// linking the new node that temp1 points to to the node that temp2 points to
			temp1->Next = NULL;							// since there is no next node temp1.next is set to NULL
		}
	}

	return SUCCESS;										// returning the constant SUCCESS upon successfull execution
}

void FreeMemory(APPOINTMENT** ptrToHead) {					// a FreeMemory function is created that takes 1 parameters a pointer of type APPOINTMENT*. It returns nothing.

	for (int i = 0; i < NUMBEROFDAYSINMONTH; i++) {			// if i is less than NUMBEROFDAYSINMONTH then the loop continues executing.

		APPOINTMENT* temp = *ptrToHead;						// temp is made to point to the first node
		*ptrToHead = temp->Next;							// pointer that ptrToHead points to is made to point to the next node

		free(temp);											// the memory that temp points to is freed

		temp = NULL;										// temp is set to NULL so that it can't access the freed memory
	}
}
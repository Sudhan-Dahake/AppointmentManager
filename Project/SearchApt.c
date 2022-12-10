
#include "SearchApt.h"


void SearchApt(APPOINTMENT** ptrToHead, char* userFirstNameBuf, char* userLastNameBuf)
{
	bool isFound = false;
	if (ptrToHead == NULL)
	{
		puts(" Task is empty. No appointment to search!");
		exit(EXIT_FAILURE);
	}
	APPOINTMENT* temp = *ptrToHead;

	printf(" %10s \t %10s \t %10s \n\n", "Date", "First Name", "Last Name");

	while (temp != NULL)
	{
		if ((strcmp(temp->FirstName, userFirstNameBuf) == ZERO) && (strcmp(temp->LastName, userLastNameBuf) == ZERO))
		{
			printf(" %10d \t %10s \t %10s \n\n", temp->Date, temp->FirstName, temp->LastName);
			isFound = true;
		}
		temp = temp->Next;
	}
	if (!isFound)
	{
		puts(" No matching name in any existing appointment!\n");
	}


}
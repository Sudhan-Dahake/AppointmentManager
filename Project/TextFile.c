#define _CRT_SECURE_NO_WARNINGS
#include "TextFile.h"
#include "StringUtils.h"

void SaveAptToDisk(APPOINTMENT** ptrToHead)
{
	FILE* fp;

	if ((fp = fopen("Appointment.txt", "w")) == NULL)
	{
		fprintf(stderr, "Cannot Create a text file\n");
		exit(EXIT_FAILURE);
	}

	APPOINTMENT* temp = *ptrToHead;

	if (temp == NULL)
	{
		printf("No Data to Save into TextFile\n");
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		if (temp->AppointmentTaken == YES)
		{
			fprintf(fp, "%d\n", temp->Date);
			fprintf(fp, "%s\n", temp->FirstName);
			fprintf(fp, "%s\n", temp->LastName);
			fprintf(fp, "%c\n", temp->AppointmentTaken);
		}
		temp = temp->Next;
	}

	fclose(fp);
}


// Load From TextFile

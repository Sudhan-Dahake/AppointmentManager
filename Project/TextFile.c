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
void LoadAptToProgram(APPOINTMENT** ptrToHead)
{
	FILE* fp;
	char chAptDate[MAXSIZE];
	char chFirstName[MAXSIZE];
	char chLastName[MAXSIZE];
	char chAptTaken[MAXSIZE];

	if ((fp = fopen("Appointment.txt", "r")) == NULL)
	{
		fprintf(stderr, "No File to Read...\n");
		exit(EXIT_FAILURE);
	}

	//read file and set seat values
	while ((fgets(chAptDate, MAXSIZE, fp)) != NULL)
	{

		chAptDate[strlen(chAptDate) - 1] = '\0'; //cleans string
		int aptDate = atoi(chAptDate);

		fgets(chFirstName, MAXSIZE, fp);
		chFirstName[strlen(chFirstName) - 1] = '\0'; //cleans string

		fgets(chLastName, MAXSIZE, fp);
		chLastName[strlen(chLastName) - 1] = '\0'; //cleans string

		fgets(chAptTaken, MAXSIZE, fp);
		chAptTaken[strlen(chAptTaken) - 1] = '\0'; //cleans string

		APPOINTMENT* temp = *ptrToHead;

		// loop to find the desired appointment date
		for (int i = 0; i < aptDate - ONE; i++) {
			temp = temp->Next;
		}

		strncpy(temp->FirstName, chFirstName, MAXSIZE);
		strncpy(temp->LastName, chLastName, MAXSIZE);
		temp->AppointmentTaken = chAptTaken[0];

	}

	fclose(fp);
}
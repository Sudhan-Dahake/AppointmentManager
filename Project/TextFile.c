// Source File for text file functions
// coding the work for the main program
// 
// Assignment 6 - Project
// Owen Covach, Sudhan Dahake, Hangsihak Sin - prog71985 - fall 2022

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
	// declaring temp values for load file use
	FILE* fp;
	char chAptDate[MAXSIZE];
	char chFirstName[MAXSIZE];
	char chLastName[MAXSIZE];
	char chAptTaken[MAXSIZE];

	// opening text file to read if possible
	if ((fp = fopen("Appointment.txt", "r")) == NULL)
	{
		fprintf(stderr, "No File to Read...\n");
	}

	//read file and set appointment values
	while ((fgets(chAptDate, MAXSIZE, fp)) != NULL)
	{

		chAptDate[strlen(chAptDate) - 1] = '\0'; //cleans string
		int aptDate = atoi(chAptDate); //used for loop limitation

		fgets(chFirstName, MAXSIZE, fp);
		chFirstName[strlen(chFirstName) - 1] = '\0'; //cleans string

		fgets(chLastName, MAXSIZE, fp);
		chLastName[strlen(chLastName) - 1] = '\0'; //cleans string

		fgets(chAptTaken, MAXSIZE, fp);
		chAptTaken[strlen(chAptTaken) - 1] = '\0'; //cleans string

		// declaring temp pointer back to the top every iteration
		APPOINTMENT* temp = *ptrToHead;

		//check if temp is not NULL
		if (temp != NULL)
		{
			// loop to find the desired appointment date
			for (int i = 0; i < aptDate - ONE; i++) {
				temp = temp->Next;
			}

			// filling in appointment slot
			strncpy(temp->FirstName, chFirstName, MAXSIZE);
			strncpy(temp->LastName, chLastName, MAXSIZE);
			temp->AppointmentTaken = chAptTaken[0];
		}
	}

	//close file
	fclose(fp);
}
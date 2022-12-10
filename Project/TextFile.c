// Source File for text file functions
// coding the work for the main program
// 
// Assignment 6 - Project
// Owen Covach, Sudhan Dahake, Hangsihak Sin - prog71985 - fall 2022

#define _CRT_SECURE_NO_WARNINGS
#include "TextFile.h"																// Header file for TextFile Library
#include "StringUtils.h"															// Header file for StringUtils Library

// Save Appointment(s) to Disk (textFile)
void SaveAptToDisk(APPOINTMENT** ptrToHead)
{
	// File pointer is declared that will later be used to open and stream data to disk (textfile)
	FILE* fp;

	// Check to make sure if we open the textfile to write. if it cannot then it will exit, else continue
	if ((fp = fopen("Appointment.txt", "w")) == NULL)
	{
		fprintf(stderr, "Cannot Create a text file\n");
		exit(EXIT_FAILURE);
	}

	// A temp pointer is declared with the prtToHead to be used to act as a temp Pointer we iterate through the link list nodes
	APPOINTMENT* temp = *ptrToHead;

	// Not neccessary but incase if it was trying to save when the link is empty then it will exit
	if (temp == NULL)
	{
		printf("No Data to Save into TextFile\n");
		exit(EXIT_FAILURE);
	}

	// Iterate through all the link list node until it finds a NULL which mean it has reached the end of the linked list
	while (temp != NULL)
	{
		// Check if the node contains an AppointmentTaken Marker with 'Y' meaning that there is data to be saved to the textfile
		if (temp->AppointmentTaken == YES)
		{
			fprintf(fp, "%d\n", temp->Date);							// 1st send the formatted date output to the textfile (stream)
			fprintf(fp, "%s\n", temp->FirstName);						// 2nd send the formatted First Name output to the textfile (stream)
			fprintf(fp, "%s\n", temp->LastName);						// 3rd send the formatted Last Name output to the textfile (stream)
			fprintf(fp, "%c\n", temp->AppointmentTaken);				// 4th send the formatted AppointmentTaken Marker output to the textfile (stream)
		}
		// The temp pointer will now point to the address of the next node 
		temp = temp->Next;
	}

	// Close file pointer when the the save operation is completed
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
	else {

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

}

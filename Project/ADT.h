#pragma once

#define MAXSIZE 20

typedef struct appointment {

	int Date;
	char FirstName[MAXSIZE];
	char LastName[MAXSIZE];
	char AppointmentTaken;
	struct appointment* Next;
} APPOINTMENT;
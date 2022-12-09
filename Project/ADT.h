#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define ONE 1
#define MAXSIZE 20
#define DAYSINMONTH	30
#define NO 'N'
#define YES 'Y'
#define NULLCHARACTER '\0'

typedef struct appointment {

	int Date;
	char FirstName[MAXSIZE];
	char LastName[MAXSIZE];
	char AppointmentTaken;
	struct appointment* Next;
} APPOINTMENT;
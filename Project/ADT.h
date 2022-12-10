/* Group 6: Group Project */

// PROG71985 - F22

/*	Group Members:
*
	- Owen Covach
	- Sudhan Dahake
	- Hangsihak Sin
*/

// Header file for ADT library for the Appointment Reservation Program

#pragma once

// Header file of ADT of appointment program
// Assignment 6 - Project
// Group 6 - prog71985 - fall 2022

// ADT	<-- Work done by Sudhan

#define _CRT_SECURE_NO_WARNINGS					// allows us to ignore warnings

#include <stdio.h>								// is a header file that contains information to include the input/output related functions in our program
#include <stdbool.h>							// allows us to bool values
#include <stdlib.h>								// allws us to use malloc
#include <string.h>								// allows us to use string functions

#define ONE 1									// this constant is used to store the value 1
#define MAXSIZE 20								// this constant is used to store the value 20
#define DAYSINMONTH	30							// this constant is used to store the value 30
#define NO 'N'									// this constant is used to signify NO
#define YES 'Y'									// this constant is used to signify YES
#define NULLCHARACTER '\0'						// this constant is used to signify NULLCHARACTER

typedef struct appointment {					// a structure of type appointment is created
												// It has 5 members
	int Date;									// a integer Date
	char FirstName[MAXSIZE];					// a string FirstName
	char LastName[MAXSIZE];						// a string LastName
	char AppointmentTaken;						// a char AppointmentTaken
	struct appointment* Next;					// since we are using a linked list therefore we need a pointer that points to next node
} APPOINTMENT;									// since typedef is used we can give the structure a name so that we don't have to type struct everytime when declaring a variable
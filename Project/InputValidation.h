#pragma once
#include <stdio.h>
#include <stdbool.h>								// Use for boolean data type (true/false)
#include <string.h>									// Use for strlen() method

#define ASCIIDECIMAL '.'
#define ASCIIMINUS '-'
#define ASCIIZERO '0'
#define ASCIININE '9'
#define DAYS_IN_A_WEEK 7

bool ValidateUserInput(char*);						// A function declaration for ValidateUserInput
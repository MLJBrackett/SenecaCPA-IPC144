/* -------------------------------------------
Name:Michael Brackett
Student number:160780177
Email:mbrackett@myseneca.ca
Section:SCP
Date:11-14-2018
----------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-1 Milestone-4 |
// |        function definitions below...            |
// +-------------------------------------------------+
#include "contacts.h"
// getName:
void getName(struct Name *namePtr)
{
	char checker = 'y'; // Using this as our check (This can be replaced by anything)

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf(" %[^\n]30s", namePtr->firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) { 
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]6s", namePtr->middleInitial);
	}


	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", namePtr->lastName);
}
// getAddress:
void getAddress(struct Address *addressPtr)
{
	char checker = 'y';
	
	// Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &(addressPtr->streetNumber));

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]40s", addressPtr->street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &(addressPtr->apartmentNumber));
	}

	printf("Please enter the contact's postal code: ");
	scanf(" %[^\n]7s", addressPtr->postalCode);


	printf("Please enter the contact's city: ");
	scanf(" %[^\n]40s", addressPtr->city);
}

// getNumbers:
void getNumbers(struct Numbers *numbersPtr)
{
	
	char checker = 'y';
	
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's cell phone number: ");
		scanf("%20s", numbersPtr->cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", numbersPtr->home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", numbersPtr->business);
	}
}

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+

// getContact:
// Define Empty function definition below:

void getContact( )
{
	
}
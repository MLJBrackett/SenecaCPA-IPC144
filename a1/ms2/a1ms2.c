#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
// to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"

int main(void)
{
	// Declare variables here:
	struct Name contactN;
	contactN.firstName[0] = '\0';//Declare structs and set them to 0
	contactN.lastName[0] = '\0';
	contactN.middleInitial[0] = '\0';

	struct Address contactA;
	contactA.apartmentNumber = '\0';
	contactA.city[0] = '\0';
	contactA.postalCode[0] = '\0';
	contactA.street[0] = '\0';
	contactA.streetNumber = '\0';

	struct Numbers contactNum;
	contactNum.business[0] = '\0';
	contactNum.cell[0] = '\0';
	contactNum.home[0] = '\0';

	char checker = 'y'; // Using this as our check (This can be replaced by anything)

	// Display the title
	printf("Contact Management System\n");
	printf("-------------------------\n");

	// Contact Name Input:
	printf("Please enter the contact's first name: ");
	scanf("%30s", contactN.firstName);

	printf("Do you want to enter a middle initial(s)? (y or n): ");
	
	scanf(" %c", &checker); 
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's middle initial(s): ");
		scanf(" %[^\n]6s", contactN.middleInitial);
	}


	printf("Please enter the contact's last name: ");
	scanf(" %[^\n]35s", contactN.lastName);


    // Contact Address Input:
	printf("Please enter the contact's street number: ");
	scanf("%d", &contactA.streetNumber); //Using address here since this is an int instead of a chararray.

	printf("Please enter the contact's street name: ");
	scanf(" %[^\n]40s", contactA.street);

	printf("Do you want to enter an apartment number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's apartment number: ");
		scanf("%d", &contactA.apartmentNumber);
	}

	printf("Please enter the contact's postal code: ");
	/*The %s input specifier terminates strings at whitespace. This causes our input of "A8A 4J4" to be interpreted as just "A8A", leaving the rest in the input buffer which screws up the rest of the
	program. We also use a space before scanf here for the same reason as on line 56(non-%s specifiers don't ignore leading newlines). */
	scanf(" %[^\n]", contactA.postalCode); 

	
	printf("Please enter the contact's city: ");
	scanf(" %[^\n]40s", contactA.city);


    // Contact Numbers Input:
	printf("Do you want to enter a cell phone number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's cell phone number: ");
		scanf("%20s", contactNum.cell);
	}

	printf("Do you want to enter a home phone number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's home phone number: ");
		scanf("%20s", contactNum.home);
	}

	printf("Do you want to enter a business phone number? (y or n): ");
	scanf(" %c", &checker);
	if (!(checker == 'n' || checker == 'N')) {
		printf("Please enter the contact's business phone number: ");
		scanf("%20s", contactNum.business);
	}

    // Display Contact Summary Details
	
	printf("\nContact Details\n"); //Two newlines here to add a blank line.
	printf("---------------\n");
	printf("Name Details\n");
	printf("First name: %s\n", contactN.firstName);
	printf("Middle initial(s): %s\n", contactN.middleInitial);
	printf("Last name: %s\n\n", contactN.lastName);//Two newlines here to add a blank line.

	printf("Address Details\n");
	printf("Street number: %d\n", contactA.streetNumber);
	printf("Street name: %s\n", contactA.street);
	printf("Apartment: %d\n", contactA.apartmentNumber);
	printf("Postal code: %s\n", contactA.postalCode);
	printf("City: %s\n\n", contactA.city);//Two newlines here to add a blank line.

	printf("Phone Numbers:\n");
	printf("Cell phone number: %s\n", contactNum.cell);
	printf("Home phone number: %s\n", contactNum.home);
	printf("Business phone number: %s\n\n", contactNum.business);//Two newlines here to add a blank line.


    // Display Completion Message

	printf("Structure test for Name, Address, and Numbers Done!\n");

    return 0;
}
    

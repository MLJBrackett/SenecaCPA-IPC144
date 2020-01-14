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
    
    // Create a variable of type Contact and call it something self-describing like "contact"
    // - HINT: Be sure to initialize the values to 0 and empty C strings
    // IMPORTANT:  Do NOT declare variables of type Name, Address, or Numbers
    struct Contact contact;
    
    contact.name.firstName[0] = '\0';
    contact.name.lastName[0] = '\0';
    contact.name.middleInitial[0] = '\0';
    
    contact.address.apartmentNumber = 0;
    contact.address.city[0] = '\0';
    contact.address.postalCode[0] = '\0';
    contact.address.street[0] = '\0';
    contact.address.streetNumber = 0;
    
    contact.number.business[0] = '\0';
    contact.number.cell[0] = '\0';
    contact.number.home[0] = '\0';
    
    // Display the title
    printf("Contact Management System\n");
    printf("=========================\n");
    
    // Call the Contact function getName to store the values for the Name member
    getName(&contact.name);
    
    // Call the Contact function getAddress to store the values for the Address member
    getAddress(&contact.address);
    
    // Call the Contact function getNumbers to store the values for the Numbers member
    getNumbers(&contact.number);
    
    // Display Contact summary details
    
    printf("\nContact Details\n"); //Two newlines here to add a blank line.
    printf("===============\n");
    printf("Name Details\n");
    printf("------------\n");
    printf("First name: %s\n", contact.name.firstName);
    printf("Middle initial(s): %s\n", contact.name.middleInitial);
    printf("Last name: %s\n\n", contact.name.lastName);//Two newlines here to add a blank line.
    
    printf("Address Details\n");
    printf("---------------\n");
    printf("Street number: %d\n", contact.address.streetNumber);
    printf("Street name: %s\n", contact.address.street);
    printf("Apartment: %d\n", contact.address.apartmentNumber);
    printf("Postal code: %s\n", contact.address.postalCode);
    printf("City: %s\n\n", contact.address.city);//Two newlines here to add a blank line.

    printf("Phone Numbers\n");
    printf("-------------\n");
    printf("Cell phone number: %s\n", contact.number.cell);
    printf("Home phone number: %s\n", contact.number.home);
    printf("Business phone number: %s\n\n", contact.number.business);//Two newlines here to add a blank line.
    
    // Display Completion Message
    printf("Structure test for Contact using functions done!\n");
    
    return 0;
}

/* -------------------------------------------
 Name: Michael Brackett
 Student number:160780177
 Email:mbrackett@myseneca.ca
 Section:SCP
 Date:11-15-2018
 ----------------------------------------------
 Assignment: 2
 Milestone:  2
 ---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:
#include "contacts.h"


// This source file needs to "know about" the functions you prototyped
//         in the contact helper header file too
// HINT-1: You will want to use the new yes() and getInt() functions to help
//         simplify the data input process and reduce redundant coding
//
// HINT-2: Put the header file name in double quotes so the compiler knows
//         to look for it in the same directory/folder as this source file
//         #include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        function definitions below...            |
// +-------------------------------------------------+
//
// HINT:  Update these function to use the helper
//        functions where applicable (ex: yes() and getInt() )



/*
These are generally the same as the a1 but instead of using a checker we use the function "yes" and clear the keyboard
after we use it. Other then that we can just copy and paste it in.
*/

// getName:
void getName(struct Name *namePtr)
{
    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]s", namePtr->firstName);
    clearKeyboard();
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]s", namePtr->middleInitial);
        clearKeyboard();
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]s", namePtr->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address *addressPtr)
{
    // Contact Address Input:
    printf("Please enter the contact's street number: ");
    addressPtr->streetNumber = getIntInRange(1, 65535);//Max of an unsigned int for two bytes
    
    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]s", addressPtr->street);
    clearKeyboard();
    printf("Do you want to enter an apartment number? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's apartment number: ");
        addressPtr->apartmentNumber = getIntInRange(1, 65536);// Max of an usgined int for two bytes
    }
    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]s", addressPtr->postalCode);
    clearKeyboard();
    printf("Please enter the contact's city: ");
    scanf("%40[^\n]s", addressPtr->city);
    clearKeyboard();
}

// getNumbers:
// NOTE:  Also modify this function so the cell number is
//        mandatory (don't ask to enter the cell number)
void getNumbers(struct Numbers *numbersPtr)
{
    printf("Please enter the contact's cell phone number: ");
    scanf(" %20[^\n]s", numbersPtr->cell);
    clearKeyboard();
    printf("Do you want to enter a home phone number? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's home phone number: ");
        scanf("%20[^\n]s", numbersPtr->home);
        clearKeyboard();
    }
    printf("Do you want to enter a business phone number? (y or n): ");
    if (yes() == 1) {
        printf("Please enter the contact's business phone number: ");
        scanf("%20[^\n]s", numbersPtr->business);
        clearKeyboard();
    }
}


// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// +-------------------------------------------------+

// getContact
void getContact(struct Contact *contactPtr)
{
    getName(&(contactPtr->name));
    getAddress(&(contactPtr->address));
    getNumbers(&(contactPtr->numbers));
}

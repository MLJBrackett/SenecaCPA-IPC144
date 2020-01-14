//
//  contacts.c
//  MS4
//
//  Created by Michael Brackett on 2018-11-26.
//  Copyright © 2018 Michael Brackett. All rights reserved.
//
/* -------------------------------------------
 Name: Michael Brackett
 Student number:160780177
 Email:mbrackett@myseneca.ca
 Section:SCP
 Date:11-26-2018
 ----------------------------------------------
 Assignment: 2
 Milestone:  4
 ---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// +-------------------------------------------------+
// | NOTE:  Include additional header files...       |
// +-------------------------------------------------+
#include "contacts.h"
#include "contactHelpers.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

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
    else
    {
        namePtr->middleInitial[0] = '\0';
    }
    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]s", namePtr->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address *addressPtr)
{
    
        printf("Please enter the contact's street number: ");
        addressPtr->streetNumber = getIntInRange(1, 100000000,1);
    
        printf("Please enter the contact's street name: ");
        scanf("%40[^\n]s", addressPtr->street);
        clearKeyboard();
    
        printf("Do you want to enter an apartment number? (y or n): ");
        if (yes() == 1) {
            printf("Please enter the contact's apartment number: ");
            addressPtr->apartmentNumber = getIntInRange(1, 100000000,2);
        }
        else
        {
            addressPtr->apartmentNumber = 0;
        }
        printf("Please enter the contact's postal code: ");
        scanf("%7[^\n]s", addressPtr->postalCode);
        clearKeyboard();
        printf("Please enter the contact's city: ");
        scanf("%40[^\n]s", addressPtr->city);
        clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers *numbersPtr)
{
    {
        printf("Please enter the contact's cell phone number: ");
        getTenDigitPhone(numbersPtr->cell);
        
        printf("Do you want to enter a home phone number? (y or n): ");
        if (yes() == 1) {
            printf("Please enter the contact's home phone number: ");
            getTenDigitPhone(numbersPtr->home);
        }
        else
        {
            numbersPtr->home[0] = '\0';
        }
        
        printf("Do you want to enter a business phone number? (y or n): ");
        if (yes() == 1) {
            printf("Please enter the contact's business phone number: ");
            getTenDigitPhone(numbersPtr->business);
        }
        else
        {
            numbersPtr->business[0] = '\0';
        }
    }
}



// getContact:
void getContact(struct Contact *contactPtr)
{
    getName(&(contactPtr->name));
    getAddress(&(contactPtr->address));
    getNumbers(&(contactPtr->numbers));
}

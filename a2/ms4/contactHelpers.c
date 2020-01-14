//
//  contactHelpers.c
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
#include <ctype.h>
#include <stdlib.h>
// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// ----------------------------------------------------------
// Include your contactHelpers header file on the next line:
#include "contactHelpers.h"


// ----------------------------------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5


//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard
void clearKeyboard(void)
{
    while (getchar() != '\n'); 
}
// pause1:
void pause1(void)
{
    printf("(Press Enter to Continue)\n");
    clearKeyboard();
}

// getInt:
int getInt(void)
{
    char NL = 'x';
    int value;
    scanf("%d%c", &value, &NL);
    while (NL != '\n') {
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &NL);
    }
    return value;
}
// getIntInRange:
int getIntInRange(int lower, int upper, int addchoice)
{
    int value = getInt();
    if (addchoice==1){
        while (value < lower || value > upper || value <= 0) {
            printf("Please enter the contact's street number: ");
            value = getInt();
        }
    }else if(addchoice==2)
    {
        while (value < lower || value > upper) {
            printf("Please enter the contact's apartment number: ");
            value = getInt();
        }
    }else{
    while (value < lower || value > upper) {
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lower, upper);
        value = getInt();
        }
    }
    return value;
}

// yes:
int yes(void)
{
    char NL = 'x';
    char value;
    scanf("%c%c", &value, &NL);
    while ((value != 'y' && value !='Y' && value != 'n' && value != 'N') || NL != '\n') {
        printf ("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        clearKeyboard();
        scanf("%c%c", &value, &NL);
    }
    if (value == 'y' || value == 'Y') {
        return 1;
    }
    return 0;
}

// menu:
int menu(void)
{
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    return getIntInRange(0, 6, 0);
}


// contactManagerSystem:
void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] =
    {
        {
            { "Rick", {'\0'}, "Grimes" },
            { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
            { "4161112222", "4162223333", "4163334444" }
        },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" }
        },
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" }
        },
        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555"}
        }
    };
    
    int selection = 0, done = 0;
    
    while (done == 0) {
        
        selection = menu();
        printf("\n");
        switch (selection) {
            case 1:
                displayContacts(contacts, MAXCONTACTS);
                pause1();
                break;
            case 2:
                addContact(contacts, MAXCONTACTS);
                pause1();
                break;
            case 3:
                updateContact(contacts, MAXCONTACTS);
                pause1();
                break;
            case 4:
                deleteContact(contacts, MAXCONTACTS);
                pause1();
                break;
            case 5:
                searchContacts(contacts, MAXCONTACTS);
                pause1();
                break;
            case 6:
                sortContacts(contacts, MAXCONTACTS);
                pause1();
                break;
            default:
                printf("Exit the program? (Y)es/(N)o: ");
                if (yes() == 1) {
                    printf("\nContact Management System: terminated\n");
                    done = 1;
                }
                else{
                    printf("\n");
                }
                break;
        }
    }
}

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:
    void getTenDigitPhone(char telNum[11])
    {
        int needInput = 10;
        
        while (needInput > 0) {
            
            needInput = 10;
            
            scanf("%10s", telNum);
            clearKeyboard();
            
            if (strlen(telNum) == 10) {
                int i = 0;
                for (i = 0; i < 10; i++) {
                    if (isdigit(telNum[i])) {
                        needInput--;
                    }
                }
            }
            if (needInput > 0) {
                printf("Enter a 10-digit phone number: ");
            }
        }
    }

// findContactIndex:
    int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
    {
        int i = 0;
        for (i = 0; i < size; i++) {
            if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
                return i;
            }
        }
        return -1;
    }

// displayContactHeader
    void displayContactHeader(void)
    {
        printf("+-----------------------------------------------------------------------------+\n");
        printf("|                              Contacts Listing                               |\n");
        printf("+-----------------------------------------------------------------------------+\n");
    }

// displayContactFooter
    void displayContactFooter(int total)
    {
        printf("+-----------------------------------------------------------------------------+\n");
        printf("Total contacts: %d\n\n", total);
    }

// displayContact:
    void displayContact(const struct Contact *contactPtr)
    {
        printf(" %s ", contactPtr->name.firstName);
        if (contactPtr->name.middleInitial[0] != '\0') {
            printf("%s ", contactPtr->name.middleInitial);
        }
        printf("%s\n", contactPtr->name.lastName);
        
        printf("    C: %-10s   H: %-10s   B: %-10s\n", contactPtr->numbers.cell, contactPtr->numbers.home, contactPtr->numbers.business);
        
        printf("       %d %s, ", contactPtr->address.streetNumber, contactPtr->address.street);
        if (contactPtr->address.apartmentNumber > 0) {
            printf("Apt# %d, ", contactPtr->address.apartmentNumber);
        }
        printf("%s, %s\n", contactPtr->address.city, contactPtr->address.postalCode);
    }

// displayContacts:
    void displayContacts(const struct Contact contacts[], int size)
    {
        int validCount = 0;
        
        displayContactHeader();
        
        int i = 0;
        
        for (i = 0; i < size; i++) {
            if (contacts[i].numbers.cell[0] != '\0') {
                displayContact(&(contacts[i]));
                validCount++;
            }
        }
        
        displayContactFooter(validCount);
    }

// searchContacts:
    void searchContacts(const struct Contact contacts[], int size)
    {
        char queryCellNumber[11];
        
        printf("Enter the cell number for the contact: ");
        
        getTenDigitPhone(queryCellNumber);
        
        int queryIndex = findContactIndex(contacts, MAXCONTACTS, queryCellNumber);
        
        if (queryIndex < 0) {
            printf("*** Contact NOT FOUND ***\n");
            printf("\n");
        }
        else {
            printf("\n");
            displayContact(&(contacts[queryIndex]));
            printf("\n");
        }
    }

// addContact:
    void addContact(struct Contact contacts[], int size)
    {
        int firstOpenSlot = -1;
        int i = 0;
        
        for (i = 0; i < size; i++) {
            if (firstOpenSlot < 0 && strlen(contacts[i].numbers.cell) == 0) {
                firstOpenSlot = i;
            }
        }
        
        if (firstOpenSlot > -1) {
            getContact(&(contacts[firstOpenSlot]));
            printf("--- New contact added! ---\n");
            printf("\n");
        }
        else {
            printf("*** ERROR: The contact list is full! ***\n");
            printf("\n");
        }
    }

// updateContact:
void updateContact(struct Contact contacts[], int size)
{
    char queryCellNumber[11];
    printf("Enter the cell number for the contact: ");
    
    getTenDigitPhone(queryCellNumber);
    int queryIndex = findContactIndex(contacts, MAXCONTACTS, queryCellNumber);
    
    if (queryIndex < 0) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else {
        int isUpdated = 0;
        printf("\nContact found:\n");
        displayContact(&(contacts[queryIndex]));
        printf("\n");
        
        
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1) {
            getName(&(contacts[queryIndex].name));
            isUpdated++;
        }
        
        
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1) {
            getAddress(&(contacts[queryIndex].address));
            isUpdated++;
        }
        
        
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1) {
            getNumbers(&(contacts[queryIndex].numbers));
            isUpdated++;
        }
        
        
        if (isUpdated > 0) {
            printf("--- Contact Updated! ---\n");
            printf("\n");
        }
    }
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size)
{
    char queryCellNumber[11];
    
    printf("Enter the cell number for the contact: ");
    
    getTenDigitPhone(queryCellNumber);
    
    int queryIndex = findContactIndex(contacts, MAXCONTACTS, queryCellNumber);
    
    if (queryIndex < 0) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else {
        printf("\nContact found:\n");
        displayContact(&(contacts[queryIndex]));
        printf("\nCONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1) {
            contacts[queryIndex].numbers.cell[0] = '\0';
            printf("--- Contact deleted! ---\n");
            printf("\n");
        }else{
            printf("\n");
        }
    }
}


// sortContacts:
    void sortContacts(struct Contact contacts[], int size)
    {
      
        int i, j, m;
        struct Contact temp;
        
        for (i = 0; i < size; i++) {
            m = i;
            for (j = i + 1; j < size; j++) {
                if (strcmp(contacts[j].numbers.cell, contacts[m].numbers.cell) < 1) {
                    m = j;
                }
            }
            if (m != i) {
                temp = contacts[i];
                contacts[i] = contacts[m];
                contacts[m] = temp;
            }
        }
        
        printf("--- Contacts sorted! ---\n");
    }

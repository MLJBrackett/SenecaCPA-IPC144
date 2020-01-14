/* -------------------------------------------
 Name: Michael Brackett
 Student number:160780177
 Email:mbrackett@myseneca.ca
 Section:SCP
 Date:11-15-2018
 ----------------------------------------------
 Assignment: 2
 Milestone:  1
 ---------------------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// This source file needs to "know about" the functions you prototyped
// in the contact helper header file.
// HINT: Put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
//       #include your contactHelpers header file on the next line:

#include "contactHelpers.h"
#include "contacts.h"
//------------------------------------------------------
// Function Definitions
//------------------------------------------------------

// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 2 =======       |
// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-1 |
// |        empty function definitions below and     |
// |        complete the definitions as per the      |
// |        Milestone-2 specifications               |
// |                                                 |
// | - The clearKeyboard function is done for you    |
// +-------------------------------------------------+


// Clear the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard(); //Since buffer will be empty when function is called, will wait for enter press to continue
}

// getInt function definition goes here:
int getInt(void)
{
    char NL = 'x';
    int value;
    scanf("%d%c", &value, &NL); //Store integer into value, and whatever following char is into NL
    while (NL != '\n') { //Input is invalid if not an integer followed by newline
        clearKeyboard();
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &NL);
    }
    return value;
}

// getIntInRange function definition goes here:
int getIntInRange(int lower, int upper)
{
    int value = getInt(); //Call getInt for initial value
    if (lower==1 && upper==65535) {
        while (value < lower || value > upper) {
            printf ("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            value = getInt();
        }
    }
    if (lower==1 && upper==65536) {
        while (value < lower || value > upper) {
            printf ("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
            value = getInt();
        }
    }
    while (value < lower || value > upper) { //Keep calling getInt until it's within range
        printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", lower, upper);
        value = getInt();
    }
    return value;
}

// yes function definition goes here:
int yes(void)
{
    char NL = 'x';
    char value;
    scanf("%c%c", &value, &NL); //Get a single char then another char, which should be a newline
    while ((value != 'y' && value !='Y' && value != 'n' && value != 'N') || NL != '\n') { //Enter if first char doesn't match [YyNn] or second char isnt a newline
        printf ("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        clearKeyboard();
        scanf("%c%c", &value, &NL);
    }
    if (value == 'y' || value == 'Y') { //Return 1 if Y or y, otherwise return 0
        return 1;
    }
    return 0;
}

// menu function definition goes here:
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
    return getIntInRange(0, 6);
}

// ContactManagerSystem function definition goes here:
void contactManagerSystem(void)
{
    int selection = 0, done = 0, i = 0;
    while (done == 0) {
        if (i != 0){
            printf("\n");
        }
        i = 1;
        selection = menu();
        printf("\n");
        switch (selection) {
            case 1:
                printf("<<< Feature 1 is unavailable >>>\n\n");
                pause();
                break;
            case 2:
                printf("<<< Feature 2 is unavailable >>>\n\n");
                pause();
                break;
            case 3:
                printf("<<< Feature 3 is unavailable >>>\n\n");
                pause();
                break;
            case 4:
                printf("<<< Feature 4 is unavailable >>>\n\n");
                pause();
                break;
            case 5:
                printf("<<< Feature 5 is unavailable >>>\n\n");
                pause();
                break;
            case 6:
                printf("<<< Feature 6 is unavailable >>>\n\n");
                pause();
                break;
            default:
                printf("Exit the program? (Y)es/(N)o: ");
                if (yes() == 1) {
                    printf("\nContact Management System: terminated\n");
                    done = 1;
                }
                break;
        }
    }
}

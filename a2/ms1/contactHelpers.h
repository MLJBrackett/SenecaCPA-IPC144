/* ------------------------------------------------------------------
Name:Michael Brackett
Student number:160780177
Email:mbrackett@myseneca.ca
Section:SCP
Date:11-14-2018
---------------------------------------------------------------------
Assignment: 2
Milestone:  1
---------------------------------------------------------------------
Description: This header file modularizes general helper functions to
             help reduce redundant coding for common repetitive tasks. 
---------------------------------------------------------------------*/

// HINT: 
// You will most likely want to include this header file
// in other files of the project since it provides general 
// helper functions that can be used throughout.


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------+
// | ====== Assignment 2 | Milestone 1 ======= |
// +-------------------------------------------+
#ifndef SICT_CONTACTS_H__
#define SICT_CONTACTS_H__
// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Put function prototype below:
void pause(void);

// getInt:
// Put function prototype below:
int getInt(void);

// getIntInRange:
// Put function prototype below:
int getIntInRange(int, int);

// yes:
// Put function prototype below:
int yes(void);

// menu:
// Put function prototype below:
int menu(void);

// ContactManagerSystem:
// Put function prototype below:
void ContactManagerSystem(void);
#endif
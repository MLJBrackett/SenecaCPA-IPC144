//
//  contacts.h
//  MS4
//
//  Created by Michael Brackett on 2018-11-26.
//  Copyright © 2018 Michael Brackett. All rights reserved.
//
// ----------------------------------------------------------------------------
// DO NOT remove the below 2 lines.
// The below two lines is needed to ensure only one copy
// of this header file is included when compiling the project.
// (it is referred to as "safeguarding")
// You will learn about this in C++ (OOP244/BTP200)
// For now, simply leave this code in!
#ifndef CONTACTS_H_
#define CONTACTS_H_
// ----------------------------------------------------------------------------

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


//------------------------------------------------------
// Structure Types
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        structures below:                        |
// +-------------------------------------------------+

// Structure type Name declaration
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};
// Structure type Address declaration
struct Address {
    unsigned int streetNumber;
    char street[41];
    unsigned int apartmentNumber;
    char postalCode[8];
    char city[41];
};
// Structure type Numbers declaration
struct Numbers {
    char cell[11];
    char home[11];
    char business[11];
};
// Structure type Contact declaration
struct Contact {
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function prototypes below...             |
// +-------------------------------------------------+

// getName:
void getName(struct Name *namePtr);
// getAddress:
void getAddress(struct Address *addressPtr);
// getNumbers:
void getNumbers(struct Numbers *numbersPtr);
// getContact:
void getContact(struct Contact *contactPtr);

// ----------------------------------------------------------------------------
// DO NOT remove the below line (closing of the "safeguard" condition)
#endif // !CONTACTS_H_

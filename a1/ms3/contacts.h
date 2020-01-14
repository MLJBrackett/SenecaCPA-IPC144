#ifndef SICT_CONTACTS_H__
#define SICT_CONTACTS_H__
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
// Place your code here...
struct Contact{
    struct Name name;
    struct Address address;
    struct Numbers number;
};


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------

// ====== Milestone 4 =======
// Get and store from standard input the values for Name
// Place your code here...
void getName(struct Name *namePtr);


// Get and store from standard input the values for Address
// Place your code here...
void getAddress(struct Address *addressPtr);

// Get and store from standard input the values for Numbers
// Place your code here...
void getNumbers(struct Numbers *numbersPtr);
#endif


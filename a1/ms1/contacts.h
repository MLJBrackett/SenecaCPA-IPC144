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

#endif

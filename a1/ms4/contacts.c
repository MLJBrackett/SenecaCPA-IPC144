#include <stdio.h>
#include "contacts.h"

void getName(struct Name *namePtr)
{
    char checker = 'y'; // Using this as our check (This can be replaced by anything)
    
    // Contact Name Input:
    printf("Please enter the contact's first name: ");
    scanf(" %[^\n]30s", namePtr->firstName);
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf(" %c", &checker);
    if (!(checker == 'n' || checker == 'N')) {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %[^\n]6s", namePtr->middleInitial);
    }
    
    
    printf("Please enter the contact's last name: ");
    scanf(" %[^\n]35s", namePtr->lastName);
}


// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *addressPtr)
{
    char checker = 'y';
    
    // Contact Address Input:
    printf("Please enter the contact's street number: ");
    scanf("%d", &(addressPtr->streetNumber));
    
    printf("Please enter the contact's street name: ");
    scanf(" %[^\n]40s", addressPtr->street);
    
    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c", &checker);
    if (!(checker == 'n' || checker == 'N')) {
        printf("Please enter the contact's apartment number: ");
        scanf("%d", &(addressPtr->apartmentNumber));
    }
    
    printf("Please enter the contact's postal code: ");
    scanf(" %[^\n]s", addressPtr->postalCode);
    
    
    printf("Please enter the contact's city: ");
    scanf(" %[^\n]40s", addressPtr->city);
}



// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:
void getNumbers(struct Numbers *numbersPtr)
{
    
    char checker = 'y';
    
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c", &checker);
    if (!(checker == 'n' || checker == 'N')) {
        printf("Please enter the contact's cell phone number: ");
        scanf("%20s", numbersPtr->cell);
    }
    
    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &checker);
    if (!(checker == 'n' || checker == 'N')) {
        printf("Please enter the contact's home phone number: ");
        scanf("%20s", numbersPtr->home);
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &checker);
    if (!(checker == 'n' || checker == 'N')) {
        printf("Please enter the contact's business phone number: ");
        scanf("%20s", numbersPtr->business);
    }
}

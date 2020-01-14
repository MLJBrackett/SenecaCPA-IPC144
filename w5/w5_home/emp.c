#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Define Number of Employees "SIZE" to be 2(Changed to 4 for at-home portion)
#define SIZE 4

// Declare Struct Employee
struct Employee
{
    int id, age;
    double salary;
};

/* main program */
int main(void) {
    
    int option = 0, i, EmployeeCount = 0, updateID, ExistingEmployee = 1,check = 0;
    printf("---=== EMPLOYEE DATA ===---\n\n");
    
    // Declare a struct Employee array "emp" with SIZE elements
    // and initialize all elements to zero
    
    struct Employee emp[SIZE] = {{ 0 }};
    
    do {
        // Print the option list
        printf("1. Display Employee Information\n");
        printf("2. Add Employee\n");
        printf("3. Update Employee Salary\n");
        printf("4. Remove Employee\n");
        printf("0. Exit\n\n");
        printf("Please select from the above options: ");
        
        // Capture input to option variable
        scanf("%d",&option);
        printf("\n");
        
        switch (option) {
            case 0:    // Exit the program
                printf("Exiting Employee Data Program. Good Bye!!!\n");
                break;
            case 1: // Display Employee Data
                    // @IN-LAB
                printf("EMP ID  EMP AGE EMP SALARY\n");
                printf("======  ======= ==========\n");
                for (i = 0; i < SIZE; i++) {
                    if (emp[i].id > 0) {
                        printf("%6d%9d%11.2lf\n", emp[i].id, emp[i].age, emp[i].salary);
                    }
                }
                printf("\n");
                break;
                // Use "%6d%9d%11.2lf" formatting in a
                // printf statement to display
                // employee id, age and salary of
                // all  employees using a loop construct
                
                // The loop construct will be run for SIZE times
                // and will only display Employee data
                // where the EmployeeID is > 0
                
                break;
            case 2:  // Adding Employee
                     // @IN-LAB
                
                printf("Adding Employee\n");
                printf("===============\n");
                check = 0;
                if (EmployeeCount >= SIZE) {
                    printf("ERROR!!! Maximum Number of Employees Reached\n\n");
                } else {
                    for (i = 0; i < SIZE && check == 0; i++) {
                        if (emp[i].id == 0) {//If emp id is empy then enter new information
                            printf("Enter Employee ID: ");
                            scanf("%d", &emp[i].id);
                            printf("Enter Employee Age: ");
                            scanf("%d", &emp[i].age);
                            printf("Enter Employee Salary: ");
                            scanf("%lf", &emp[i].salary);
                            EmployeeCount++;//Add employeecount so we can track how many there is
                            printf("\n");
                            check = 1;//Update check to exit loop
                        }
                    }
                }
                break;
            case 3: //Updating Employee Salary
                ExistingEmployee=0;//Reset
                printf("Update Employee Salary\n");
                printf("======================\n");
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &updateID);
                    check = 0;
                    for (i = 0; i < SIZE; i++) {
                        if (updateID == emp[i].id) {
                            printf("The current salary is %.2lf\n", emp[i].salary);
                            printf("Enter Employee New Salary: ");
                            scanf("%lf", &emp[i].salary);
                            check = 1;
                            ExistingEmployee=1;
                        }
                    }
                    if (ExistingEmployee!=1){//If there is no employee then display an error
                        printf("*** ERROR: Employee ID not found! ***\n");
                    }
                }while (check == 0);
                printf("\n");
                break;
            case 4:
                ExistingEmployee=0;//Reset
                printf("Remove Employee\n");
                printf("===============\n");
                do {
                    printf("Enter Employee ID: ");
                    scanf("%d", &updateID);
                    check = 0;
                    for (i = 0; i < SIZE; i++) {
                        if (updateID == emp[i].id) {
                            printf("Employee %d will be removed\n", emp[i].id);
                            emp[i].id = 0;//Remove everything in the struct
                            emp[i].age = 0;
                            emp[i].salary = 0;
                            check = 1;// Update checker
                            EmployeeCount--;//Minus employee count since we are getting rid of one
                            ExistingEmployee=1;
                        }
                    }
                    if (ExistingEmployee!=1){
                        printf("*** ERROR: Employee ID not found! ***\n");
                    }
                }
                while (check == 0);
                printf("\n");
                break;
            default://If they do not enter a correct option display an error message
                printf("ERROR: Incorrect Option: Try Again\n\n");
        }
    } while (option != 0);// Exit loop
    return 0;
}

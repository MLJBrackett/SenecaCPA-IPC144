#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n_days= 0, i=0;
	int lows[10] = { 0 }; //Declare array "low" and initialize it to 10 since that is the max number of days we can have
	int highs[10] = { 0 };// Declare array "highs" and initialize it to 10 since that is the max number of days we can have
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");// Print title
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &n_days);//Scan for days and store it in variable "n_days"
	printf("\n");
	while (n_days < 3 || n_days > 10){ //Ask use for number of days and repeat until condition is met (3 and 10 inclusive)
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &n_days);
		printf("\n");
	}
	for (i = 0; i < n_days; i++){ //Start for loop that does not go over the amount of days the user inputted
		printf("Day %d - High: ", i + 1); //Display the day is i+1 since array starts at 0
		scanf("%d", &highs[i]); //Get input for the high of the current day (i)
		printf("Day %d - Low: ", i + 1);
		scanf("%d", &lows[i]);
	}
	printf("\nDay  Hi  Low\n");//Display the output guide
	for (i = 0; i < n_days; i++){
		printf("%d    %d    %d\n", i + 1, highs[i], lows[i]); //Since our arrays are parallelized we can print both high and low using one printf statement 
	}
    return 0;
}

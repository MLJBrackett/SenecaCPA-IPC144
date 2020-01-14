#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int n_days= 0, i=0, lowest = 0, highest = 0, low_day = 0, high_day = 0, avg_days = 0;
    double avg = 0.0;
	int lows[10] = { 0 }; //Declare array "low" and initialize it to 10 since that is the max number of days we can have
	int highs[10] = { 0 };// Declare array "highs" and initialize it to 10 since that is the max number of days we can have
	printf("---=== IPC Temperature Calculator V2.0 ===---\n");// Print title
	printf("Please enter the number of days, between 3 and 10, inclusive: ");
	scanf("%d", &n_days);//Scan for days and store it in variable "n_days"
    printf("\n");
	while (n_days < 3 || n_days > 10){ //Ask use for number of days and repeat until condition is met (3 and 10 inclusive)
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &n_days);
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
        if (lows[i] <= lowest) //Check if new temperature is lowest one and add into low
		{
			lowest = lows[i];
			low_day = i + 1;

		}
		if (highs[i] >= highest) //Do the same thing but for high temps
		{
			highest = highs[i];
			high_day = i + 1;
		}
	}
	printf("\nThe highest temperature was %d, on day %d\n", highest, high_day);// Display the highest temperature and on which day it was on
	printf("The lowest temperature was %d, on day %d\n", lowest, low_day);// Dispaly the lowest temperature and on which day it was on
	do //Create loop to find the average temperature
	{
		printf("\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", n_days);
		scanf("%d", &avg_days);
		if (avg_days > n_days) //Simple check
		{
			do//Create input loop so the user must enter a number between the constraints
			{
				printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", n_days);
				scanf("%d", &avg_days);
			} while (avg_days < 1 || avg_days > n_days);
		}
		for(i = 0; i < avg_days; i++) //Get sum for each days average
		{
			avg += ( ( lows[i] + highs[i] ) / 2.0); //2.0 makes it go to the right side of += if the float
		}
		if (avg_days >= 0) //Display average
		{
			printf("\nThe average temperature up to day %d is: %0.2lf\n", avg_days, avg / avg_days ); 
		}
		avg = 0; //Reset average
	} while (avg_days >= 0); //Break the loop if a negative number is entered
	printf("\nGoodbye!\n");//Print goodbye statement
	return 0;
}

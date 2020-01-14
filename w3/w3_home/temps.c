#include <stdio.h>
#define NUMS 4
double getDouble (void);
double low, high, totalhigh = 0, totallow = 0;
int lowest = 0, lowestday = 0, highest = 0, highestday = 0;

int main() {
    int i;// Declare variable i
    printf ("---=== IPC Temperature Analyzer ===---\n");// Print title
    for (i = 1; i <= NUMS; i++)//Start for loop to get inputs for the high and low values of the days
	{
		printf("Enter the high value for day %d: ", i);// Ask for input
		scanf("%lf", &high);//Get input
		printf("\n");//Create a new line
		printf("Enter the low value for day %d: ", i);
		scanf("%lf", &low);
		printf("\n");
		while (low > high || low < -40 || high < -40 || low > 40 || high > 40)//Make sure the input is in between -40 and 40 & low cannot be greater that high
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");//Display the rules of input again
			printf("Enter the high value for day %d: ", i);//Re ask for input
			scanf("%lf",&high);//Get input
			printf("\n");// New line
			printf("Enter the low value for day %d: ", i);
			scanf("%lf",&low);
			printf("\n");
		} 
        totalhigh += high;//Add the high amount to the total high
        totallow += low;//Add the low amount to the total low
        if (high>=highest){//Sort through the temperatures for high
            highest=high;
            highestday=i;
        }
        if (low<=lowest){//Sort through the temperatures for low
            lowest=low;
            lowestday=i;
        }
    }
    printf("The average (mean) temperature was: %0.2lf\n",((totalhigh+totallow)/(NUMS * 2)));//Display the average temperature
	printf("The highest temperature was %d, on day %d\n", highest, highestday);//Display highest temperature and the day that it was on
	printf("The lowest temperature was %d, on day %d\n", lowest, lowestday);//Display the lowest temperature and the day that it was on
	return 0;
}


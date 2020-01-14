#include <stdio.h>
#define NUMS 3
double getDouble (void);
double low, high, totalhigh = 0, totallow = 0;
int lowest = 0, lowestday = 0, highest = 0, highestday = 0;

int main() {
    int i;//Delcare variable I
    printf ("---=== IPC Temperature Analyzer ===---\n");//Output title for project
    for (i = 1; i <= NUMS; i++)//Start for loop (Nums=3 so this will loop 3 times)
	{
		printf("Enter the high value for day %d: ", i);//Get input
		scanf("%lf", &high);//Store input
		printf("\n");
		printf("Enter the low value for day %d: ", i);
		scanf("%lf", &low);
		printf("\n");
		while (low > high || low < -40 || high < -40 || low > 40 || high > 40)//Make sure input follows rules for inbetween -40,40 and low is not greater than high
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");//Display rules if they inputed somthing else
			printf("Enter the high value for day %d: ", i);//Get input again
			scanf("%lf",&high);//Store input
			printf("\n");
			printf("Enter the low value for day %d: ", i);
			scanf("%lf",&low);
			printf("\n");
		} 
        totalhigh += high;//Add high to total high
        totallow += low;//Add low to total low
    }
    printf("The average (mean) temperature was: %0.2lf\n",((totalhigh+totallow)/(NUMS * 2)));//Display average temperature
return 0;
}


// Start your code below:
#include <stdio.h>
double total;
int dollars=0;
int quaters=0;
int main(void){
    printf("Please enter the amount to be paid: $");
    scanf("%lf",&total);
    dollars=total;
    total=total-dollars;
    printf("Loonies required: %d, balance owing $%.2f\n",dollars, total);
    quaters=total/0.25;
    total=total-quaters*0.25;
    printf("Quarters required: %d, balance owing $%.2f\n",quaters, total);
    return 0;
}

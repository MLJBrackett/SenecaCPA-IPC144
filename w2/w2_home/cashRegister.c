// Start your code below:
#include <stdio.h>
int main(void){
double total,GST;//Declare variables
int dollars, quaters, dimes, nickels,cents;//Declare variables
    printf("Please enter the amount to be paid: $");//Ask for input
    scanf("%lf",&total);//Get input of total
    GST = (total*0.13)+0.005;//Calculate GST
    printf("GST: %0.2f\n",GST);//Print GST
    total=total*1.13+0.005;//Add GST to total
    printf("Balance owing: $%0.2lf\n",total);//Show total with GST
    dollars=total;//Cast total into dollars (Just gives us the dollar value)
    cents=(total-dollars)*100;//Subtract dollars front cents then times by 100 so we can use modulus
    printf("Loonies required: %d, balance owing $%1.2f\n",dollars, (float)cents/100);//Turn into float temporarily
    quaters=cents/25;//Divide cents by 25 which will give us the amount of quaters we need
    cents%=25;//Take the remaining interger value
    printf("Quarters required: %d, balance owing $%1.2f\n",quaters, (float)cents/100);//Print values
    dimes=cents/10;//Same as quaters
    cents%=10;//Take remaining interger value
    printf("Dimes required: %d, balance owing $%1.2f\n",dimes,(float)cents/100);//Print values
    nickels=cents/5;//Same as nickels
    cents%=5;//Take remaining interger
    printf("Nickels required: %d, balance owing $%1.2f\n",nickels,(float)cents/100);//Print values
    printf("Pennies required: %d, balance owing $%1.2f\n",cents,(float)(cents%1)/100);//Print values

    return 0;
}

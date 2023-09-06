#include <stdio.h>
#include <stdlib.h>

int main()
{
    double cd_number;
    printf("Enter no. from which counting down starts ");
    label :
    scanf("%lf",&cd_number);
    if(cd_number>0&&((cd_number-round(cd_number))==0))//Checking its validity ,neither negative nor decimal
    {
        printf("No. is positive integer and its countdown is: \n");
        while(cd_number>0)
        {
            printf("%.2lf\n",cd_number);
            sleep(1);
            cd_number--;
        }
    }
    else
    {
        printf("No.is invalide enter a valid one \n");
        goto label;
    }
 printf("Blast off to the moon!");
    return 0;
}

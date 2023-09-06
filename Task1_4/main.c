#include <stdio.h>
#include <stdlib.h>

int main()
{
float mpu6050[10] = {0.0, 11.68, 18.95, 23.56, 25.72, 25.38, 22.65, 18.01, 10.14, -0.26};
float bno55[10] = {0.0,9.49, 16.36, 21.2, 23.16, 22.8, 19.5, 14.85, 6.79, -2.69};
float average[10];
printf("The average of 2 arrays is :\n");
for(int i=0;i<10;i++)
{
   average[i]=(mpu6050[i]+bno55[i])/2;   //fair level only :(
   printf("%.3f\n",average[i]);
}

return 0;
}


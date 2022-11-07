#include <stdio.h>
#define PI 3.14159

/******************************************************
 * A simple program to calculate the volume of a sphere
 ******************************************************/

int main(void)
{
    int radius;
    printf("Enter radius:");
    scanf("%d", &radius);
    printf("volume is: %.1lf \n\n", PI * 4 * radius * radius * radius / 3.0);
    return 0;
}
#include <stdio.h>
#include <math.h>

/*****************************************************************
 * Program to calculate sin of number in range 0-1(not inclusive)
 *****************************************************************/

int main()
{
    double number, result;
    printf("Enter number in the range of 0 and 1 only: ");
    scanf("%lf", &number);
    if (number > 0 && number < 1)
    {
        result = sin(number);
        printf("\nThe sin of %.2lf is %.2lf\n", number, result);
    }
    else
        printf("\nInvalid input,Number must be between 0 and 1.\n");
    return 0;
}
#include <stdio.h>
#include <math.h>

/***********************************************************************
 * A program that calculates sine and cosine of a value taken from input
 ***********************************************************************/

int	main(void)
{
    double	value;

    printf("Enter the desired value between 0 and 1: ");
    scanf("%lf", &value);
    if (value > 0 && value < 1)
    {
        printf("\nsin(%lf) = %lf\n", value, sin(value));
        printf("\ncos(%lf) = %lf\n", value, cos(value));
    }
    else
        printf("\nThis is an invalid input, Enter between 0 and 1\n");
    return (0);
}

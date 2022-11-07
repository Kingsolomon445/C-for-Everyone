#include <stdio.h>
#include <stdlib.h>

/************************************************************************************************
 * A simple program that calculates the average of weight data of elephant seal provided as input
 ************************************************************************************************/

void    populate_arr(int *arr, int size)
{
    int pos;

    pos = -1;
    while (++pos < size)
    {
        printf("Elephant seal weight is: ");
        scanf("\n%d", &arr[pos]);
    }
}

long long int calc_sum(const int *arr, int size)
{
    long long int sum;
    int pos;

    sum = 0;
    pos = -1;
    while (++pos < size)
    {
        sum += arr[pos];
    }
    return sum;
}

double calc_average(long long int sum, int size)
{
    double average;
    average =  sum / (size * 1.0);
    return average;
}

int main(void)
{
    int *arr;
    int size;

    printf("How many weight data would you like to input? ");
    scanf("%d", &size);
    arr = malloc(size * (sizeof (int*) + 1));
    populate_arr(arr, size);
    printf("The average of all the weight is %.2lf", calc_average(calc_sum(arr, size), size));
    free(arr);
    return 0;
}

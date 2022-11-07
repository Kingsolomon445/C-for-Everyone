#include <stdio.h>

typedef enum month{JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC} month;


void    print_date(char *month, int d)
{
    printf("%s %d",month, d);
}

void    nextday(char months[12][12], int day, enum month m)
{
    ++day;
    if (day > 28 && m == FEB)
    {
        m += 1;
        day = 1;
    }
    else if ((day > 30) && (m == SEP || m == APR || m == JUN || m == NOV))
    {
        m += 1;
        day = 1;
    }
    else if (day > 31 && m == DEC)
    {
        m = JAN;
        day = 1;
    }
    else if (day > 31)
    {
        m += 1;
        day = 1;
    }
    print_date(months[m], day);

}

int main(void)
{
    int mon[5] = {JAN, FEB, MAR, OCT, DEC}; // for the months requested
    int day[5] = {1, 28, 14, 31, 31}; // for their days
    char months[12][12] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
    };
    int pos;

    pos = -1;

    while (++pos < 5)
    {
        print_date(months[mon[pos]], day[pos]);
        printf(" && Next day is ");
        nextday(months, day[pos], mon[pos]);
        printf("\n");
    }
    return (0);
}
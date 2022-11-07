#include <stdio.h>
#include <stdlib.h>

/**********************************************************
This program stores the max and average of some an array 
into an output file given the elements from an input file
of which first integer in the file is  the size of the array
 ***********************************************************/

int main(void)
 {  
	FILE* ifp = fopen ("input_file", "r");
    FILE *ofp;
    int pos;
    int size;
    int max;
    double sum;
    int *data;

    if(fscanf(ifp, "%d", &size))
        printf ("%d ", size);
    data = (int*)malloc(sizeof(int) * size);
    pos = -1;
    while (++pos < size)
    {  
        if(fscanf (ifp, "%d", &data[pos]))
            printf ("%d ", data[pos]);
    }
    
    max = 0;
    sum = 0.0;
    pos = -1;
    while(++pos < size)
    {
        sum += data[pos];
        if (data[pos] > max)
            max = data[pos];
    }
    printf("\nAverage = %f",sum/size);
    printf("\nMax = %d\n", max);
    ofp = fopen("answer-hw3", "w");
    fprintf(ofp, "Average = %f",sum/size);  
    fprintf(ofp,"\nMax = %d", max);
    fclose (ifp); 
    fclose (ofp);
	return 0;
}
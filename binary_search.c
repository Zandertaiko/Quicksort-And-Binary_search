/*
* File: binary_search.c
* Programmer: Zander Møysal
* Date: 14.10.2015
*
* This program sorts, then finds an int in an array.
* 
*/

#include <stdio.h>
#include <stdbool.h>

// Prototypes
bool search(int value, int values[], int n);

void quickSort(int [], int , int);

int partition(int[], int, int);

// main function
int main(int argc, char **argv)
{
    int values[] = { 7, 12, 8, 0, 15, 4, 11, 9, 6, 2, 1, 63, 412, 512, 63, 22, 52, 521, 5, 7, 9, 15, 22, 13};
    int size_of_array = sizeof(values) / 4;
    
    int i;
    
    printf("\n\nUnsorted array is: ");
    for (i = 0; i < size_of_array; i++)
    {
        printf(" %d ", values[i]);
    }
    
    quickSort( values, 0, size_of_array - 1);
    
    printf("\n\nSorted array is:   ");
    for (i = 0; i < size_of_array; i++)
    {
        printf(" %d ", values[i]);
    }
    printf("\n");
    
    search(2, values, size_of_array);
    return 0;
}

// search function
bool search(int value, int values[], int n)
{
    int lower = 0;
    int upper = n - 1;
    
    while (lower <= upper)
    {
        int middle = (upper + lower) / 2;
        
        if (values[middle] == value)
        {
            printf("found %d\n", value);
            return true;
        }
        else if (values[middle] < value)
        {
            lower = middle + 1;
            printf("%d is less than %d\n", values[middle], value);
        }
        else if (values[middle] > value)
        {
            upper = middle - 1;
            printf("%d is larger than %d\n", values[middle], value);
        }
    }
    
    return false;
}

// quickSort function
void quickSort(int values[], int value, int length)
{
    int p;
    if (value < length)
    {
        p = partition(values, value, length);
        quickSort(values, value, p - 1);
        quickSort(values, p + 1, length);
    }
}

// partition function
int partition(int values[], int value, int length)
{
    int pivot, j, t, i;
    pivot = values[value];
    j = length + 1; i = value;
    while ( 1)
    {
        do
        {
            i++;
        }
        while (values[i] <= pivot && i <= length);
        do
        {
            j--;
        }
        while (values[j] > pivot);
        if (i >= j)
        {
            break;
        }
        t = values[i]; values[i] = values[j]; values[j] = t;   
    }
    t = values[value]; values[value] = values[j]; values[j] = t;
    return j;
}

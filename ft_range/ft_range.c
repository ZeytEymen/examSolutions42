/*
Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Write the following function:

nt 

It must allocate (with malloc()) an array of integers, fill it with consecutive
values that begin at start and end at end (Including start and end !), then
return a pointer to the first value of the array.

Examples:

- With (1, 3) you will return an array containing 1, 2 and 3.
- With (-1, 2) you will return an array containing -1, 0, 1 and 2.
- With (0, 0) you will return an array containing 0.
- With (0, -3) you will return an array containing 0, -1, -2 and -3.
*/
#include <stdlib.h>
int     *ft_range(int start, int end)
{
    int *array = malloc(sizeof(int)* 100);
    int i = 0;
    if (end >= 0)
    {
        while (start != end + 1)
        {
            array[i] = start;
            i++;
            start++;
        }
        return array;
    }
    if (end <= 0)
    {
        while (start != end - 1)
        {
            array[i] = start;
            i++;
            start--;
        }
    }
    return array;
}
/* 
#include <stdio.h>
int main()
{
    int s = 0; int s2= -3;
    int *array = ft_range(s,s2);
    int i = 0;
    while (i < 9)
    {
       printf("%d\n",array[i]);
       i++;
    }  
}
*/
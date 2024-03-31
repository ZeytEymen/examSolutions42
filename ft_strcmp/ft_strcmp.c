/*
Assignment name  : ft_strcmp
Expected files   : ft_strcmp.c
Allowed functions:
--------------------------------------------------------------------------------

Reproduce the behavior of the function strcmp (man strcmp).

Your function must be declared as follows:

int    ft_strcmp(char *s1, char *s2);
*/
int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 || *s2)
    {
        if (*s1 != *s2)
            return (int)(*s1 - *s2);
        s1++;
        s2++;
    }
    return (0);
}
/*
#include <string.h>
#include <stdio.h>
int main()
{
    char *s = "abcdef";
    char *s2 = "abcfe";
    printf("%d\n",strcmp(s,s2));
    printf("%d\n",ft_strcmp(s,s2));
}
*/
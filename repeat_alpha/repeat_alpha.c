/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/
#include <stdio.h>
#include <unistd.h>
void repeat_alpha(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            int repeat = s[i] -  ('a' - 1);
            while (repeat > 0)
            {
               write(1,&s[i],1);
               repeat--;
            }
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            int repeat = s[i] -  ('A' - 1);
            while (repeat > 0)
            {
               write(1,&s[i],1);
               repeat--;
            }
        }
        else
        {
            write(1,&s[i],1);
        }
        i++;
    }
    
}
int main(int argc, char **argv)
{
    if (argc == 2 && *argv[1])
       repeat_alpha(argv[1]);
    write(1,"\n",1);
    return 0;
}
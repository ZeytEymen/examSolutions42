/*
Assignment name  : rev_wstr
Expected files   : rev_wstr.c
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Write a program that takes a string as a parameter, and prints its words in 
reverse order.

A "word" is a part of the string bounded by spaces and/or tabs, or the 
begin/end of the string.

If the number of parameters is different from 1, the program will display 
'\n'.

In the parameters that are going to be tested, there won't be any "additional" 
spaces (meaning that there won't be additionnal spaces at the beginning or at 
the end of the string, and words will always be separated by exactly one space).

Examples:

$> ./rev_wstr "You hate people! But I love gatherings. Isn't it ironic?" | cat -e
ironic? it Isn't gatherings. love I But people! hate You$
$>./rev_wstr "abcdefghijklm"
abcdefghijklm
$> ./rev_wstr "Wingardium Leviosa" | cat -e
Leviosa Wingardium$
$> ./rev_wstr | cat -e
$
$>
*/
/*
string parametre alan bir program
kelime boşluk ve/veya tab, veya kelime başlangoç/bitiş karakterleri içindedir
paramtre sayısı 1 değilse yenisatır
falzdan satır olmayacak
*/
int is_space(char ch)
{
    if (ch == 32)
        return 1;
    return (0);
}
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(1,"\n",1);
        return (0);
    }
    char **array =(char**)malloc(sizeof(char*) * 50);
    int arg_i = 0;
    int arr_i = 0;
    int tmp_i = 0;
    while (argv[1][arg_i] != '\0')
    {
        char *temp = malloc(sizeof(char) * 50); 
        while (is_space(argv[1][arg_i]))
            arg_i++;
            
        if (!argv[1][arg_i])
            break;
        
        while (!is_space(argv[1][arg_i]) && argv[1][arg_i] != '\0')
        {
            temp[tmp_i] = argv[1][arg_i];
            arg_i++;
            tmp_i++;
        }
        temp[tmp_i] = '\0';
        array[arr_i] = temp;
        tmp_i = 0;
        arr_i++;
    }
    int f_i = arr_i;
    while (arr_i != -1)
    {
        printf("%s",array[arr_i]);
        arr_i--;
    }
    while (f_i != -1)
    {
        free(array[f_i]);
        f_i--;
    }
    write(1,"\n",1);
    return (0);
}
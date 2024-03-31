/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Write a program that takes a single string in lowerCamelCase format
and converts it into a string in snake_case format.

A lowerCamelCase string is a string where each word begins with a capital letter
except for the first one.

A snake_case string is a string where each word is in lower case, separated by
an underscore "_".

Examples:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
*/
#include <unistd.h>
#include <stdlib.h>
void camel_to_snake(char *s)
{
    int i = 0;
    int lenUpper = 0;
    while (s[i])
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            lenUpper++;
        i++;
    }
    char *snake = malloc(sizeof(char) * i + lenUpper + 1);
    i = 0;
    int s_i = 0;
    while (s[i])
    {
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            snake[s_i] = '_';
            write(1,&snake[s_i++],1);
            snake[s_i] = s[i] + 32;
        }
        else
            snake[s_i] = s[i];
            write(1,&snake[s_i],1);
        s_i++;
        i++;
    }
    snake[s_i] = '\0';
    free(snake);
}
int main(int argc, char **argv)
{
    if (argc == 2 && *argv[1])
        camel_to_snake(argv[1]);
    write(1,"\n",1);
    return 0;
}
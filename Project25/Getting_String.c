#include<stdio.h>
#include"Getting_String.h"

    char* Getting_String(char* string, int n)
{
    char* Value;
    char* Looking;

    Value = fgets(string, n, stdin);

    if (Value)
    {
        Looking = strchr(string, '\n');

        if (Looking)

            *Looking = '\0';

        else
            while (getchar() != '\n')

                continue;
    }
    return Value;
}
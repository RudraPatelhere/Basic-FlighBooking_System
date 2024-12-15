#include<stdio.h>
#include"Getting_The_Letter.h"
int Getting_The_Letter(const char* string)
{
    char Character;

    Character = getchar();

    while (strchr(string, Character) == NULL)

    {
        printf("Enter a character in the list %s\n", string);

        while (getchar() != '\n')

            continue;

        Character = getchar();
    }
    while (getchar() != '\n')

        continue;

    return Character;
}

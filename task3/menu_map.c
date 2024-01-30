#include <stdio.h>
#include <stdlib.h>

char my_get(char c)
{
    return fgetc(stdin);
}
/* Ignores c, reads and returns a character from stdin using fgetc. */

char cprt(char c)
{
    if (c <= 0x7E && c >= 0x20)
    {
        printf("%c\n", c);
    }
    else
    {
        printf(".\n");
    }
    return c;
}
/* If c is a number between 0x20 and 0x7E, cprt prints the character of ASCII value c followed by a new line. Otherwise, cprt prints the dot ('.') character. After printing, cprt returns the value of c unchanged. */

char encrypt(char c)
{
    if (c <= 0x7E && c >= 0x20)
    {
        return c + 1;
    }
    else
    {
        return c;
    }
}
/* Gets a char c and returns its encrypted form by adding 1 to its value. If c is not between 0x20 and 0x7E it is returned unchanged */

char decrypt(char c)
{
    if (c <= 0x7E && c >= 0x20)
    {
        return c - 1;
    }
    else
    {
        return c;
    }
}
/* Gets a char c and returns its decrypted form by reducing 1 from its value. If c is not between 0x20 and 0x7E it is returned unchanged */

char xprt(char c)
{
    printf("%x\n", c);
    return c;
}
/* xprt prints the value of c in a hexadecimal representation followed by a new line, and returns c unchanged. */

char *map(char *array, int array_length, char (*f)(char))
{
    char *mapped_array = (char *)(malloc(array_length * sizeof(char)));
    /* TODO: Complete during task 2.a */
    for (int i = 0; i < array_length; i++)
    {
        mapped_array[i] = f(array[i]);
    }
    return mapped_array;
}

void menu()
{
    char * carray =(char *)(malloc(5 * sizeof(char)));
    struct fun_desc
    {
        char *name;
        char (*fun)(char);
    };
    struct fun_desc menu[] = {{"Get string", my_get}, {"Print string", cprt}, {"Encrypt", encrypt}, {"Decrypt", decrypt}, {"Print Hex", xprt}, {NULL, NULL}};
    int menuLength = 0;
    while (menu[menuLength].name != NULL && menu[menuLength].fun != NULL)
    {
        menuLength++;
    }
    char input[100];
    char *isEOF;
    do
    {
        fprintf(stdout, "Select operation from the following menu:\n");
        for (int i = 0; i < menuLength; i++)
        {
            fprintf(stdout, "%d) %s\n", i, menu[i].name);
        }
        fprintf(stdout, "Option: ");
        isEOF = fgets(input, 100, stdin);
        int option = atoi(input);
        if (isEOF != NULL)
        {
            if (option >= 0 && option < menuLength)
            {
                fprintf(stdout, "Within bounds\n");
                carray = map(carray, 5, menu[option].fun);
                fprintf(stdout, "DONE.\n\n");
            }
            else
            {
                fprintf(stdout, "Not within bounds\n");
                break;
            }
        }
    } while (isEOF != NULL);
}

int main()
{
    menu();
    return 0;
}
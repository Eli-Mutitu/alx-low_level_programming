#include "main.h"

/**
 * print_alphabet - Prints the lowercase alphabet followed by a new line
 */
void print_alphabet(void)
{
    char letter;

    /* Loop through lowercase alphabet */
    for (letter = 'a'; letter <= 'z'; letter++)
    {
        _putchar(letter); /* Print each letter */
    }
    
    _putchar('\n'); /* Print a new line at the end */
}

#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase,
 * followed by a new line.
 * Return: Always 0 (Success)
 */
int mani(void)
{
	char ch;

	for (ch = 'a'; ch <= 'z'; ch++)
	{
		putchar(ch);
	}
	putchar('\n');

	return(0);
}

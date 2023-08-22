#include "main.h"

/**
 * _islower - Check if char is lowercase
 * @c: The char to be checked
 *
 * Return: 1 if char is lowercase, otherwise 0.
 */
int _islower(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}


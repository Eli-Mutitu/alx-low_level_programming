#include "main.h"

/**
 * print_number - Prints a number using _putchar
 * @n: The number to be printed
 */
void print_number(int n)
{
	if (n >= 10)
	{
		print_number(n / 10);
		_putchar((n % 10) + '0');
	}
	else
	{
		_putchar(n + '0');
	}
}

/**
 * print_times_table - Prints the n times table, starting with 0.
 * @n: Number of the times table.
 */
void print_times_table(int n)
{
	int i, j, k;

	if (n >= 0 && n <= 15)
	{
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j <= n; j++)
			{
				k = j * i;
				if (j != 0)
				{
					_putchar(',');
					_putchar(' ');
					if (k < 10)
					{
						_putchar(' ');
						_putchar(' ');
					}
				}
				print_number(k);
			}
			_putchar('\n');
		}
	}
}

#include "shell.h"
/**
 * main - prints the name of the program
 * @argc: name of integer
 * @argv: address to the ar
 * Return: 0
 */

int main()
{
	if (isatty(STDIN_FILENO))
	{
		/* code shell is running in interactive mode*/
		while (1)
		{
			run_in_interactive_mode();
		}
	}
	else
	{
	}

	return (0);
}

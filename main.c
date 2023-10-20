#include "shell.h"
/**
 * main - prints the name of the program
 * @argc: name of integer
 * @argv: address to the ar
 * Return: 0
 */

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	while (1)
	{
		run_in_interactive_mode();
	}

	return (0);
}

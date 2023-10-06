#include "shell.h"

/**
 * _eputs - prints an input string
 * _eputchar - write the characters to  stderr
 * _putfd - writes a character c to fd
 * _putsfd - points to the address str of fd
 * Return: 0
 */

void _eputs(char *str)
{
	int b = 0;
	if (str)
	{
		while(str [b] != '\0')
		{
			_eputchar(str[b]);
			b++;
		}
	}

}
int _eputchar (char a)
{
	static int o;
	static char buffer [1024];
	if (a == -1 || o >= 1024)
	{
		write(2, buffer, o);
		o = 0;
	}
	if (a != -1)
	buffer [o++] = c;
	return 1;
}
int _putfd(char a, int fd)
{
	static int o;
	static char buffer [1024];
	if (a == -1 || o >= 1024)
	{
		write(2, fd, buffer, o);
	}
	if (a != -1)
		buffer [o++] = a;
	return 1;
}
int _putsfd(char *str, int fd)
{
	int b = 0
	if (str)
	{
		while(*str)
		{
			b+= _putsfd(*str++, fd);
		}
		return b;
	}

}


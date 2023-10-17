#include "shell.h"

/**
 * execute_cmd - executes a command
 * @argv: array of arguments
 * Return: -1
 */

int execute_cmd(char **argv)
{
	char *cmd, *path2cmd;

	if (argv)
	{
		cmd = argv[0];
		path2cmd = get_cmd_path(cmd);
		if (execve(path2cmd, argv,   NULL) == -1)
			perror("Error:");
		return (0);
	}

	return (-1);
}

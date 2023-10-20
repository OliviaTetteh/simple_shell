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
		pid_t child_pid;

		cmd = argv[0];
		path2cmd = get_cmd_path(cmd);

		if (!path2cmd)
		{
			path2cmd = cmd;
		}

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork failed");
			return (-1);
		}

		if (child_pid == 0)
		{
			if (execve(path2cmd, argv, NULL) == -1)
			{
				perror("Error:");
				exit(1);
			}
		}
		else
		{
			int status;
			waitpid(child_pid, &status, 0);
			return (WEXITSTATUS(status));
		}
	}

	return (-1);
}
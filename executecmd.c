#include "shell.h"
/**
 * execute_cmd - Function to execute a command using the given tokens
 * @argv: array of arguments
 * @tokenCount: number of tokens
 */
void execute_cmd(char **tokens, int tokenCount)
{
	pid_t child_pid;
	int status, i;
	char *command = tokens[0];
	char *fullCommandPath;
	char **args = (char **)malloc((tokenCount + 1) * sizeof(char *));

	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork");
		exit(1);
	}
	if (child_pid == 0)
	{
		fullCommandPath = get_cmd_path(command);
		if (fullCommandPath == NULL)
		{
			fullCommandPath = command;
		}

		for (i = 0; i < tokenCount; i++)
		{
			args[i] = tokens[i];
		}
		args[tokenCount] = NULL;
		if (execve(fullCommandPath, args, NULL) == -1)
		{
			perror("execve");
			exit(1);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
		/* return (WEXITSTATUS(status));*/
	}
}

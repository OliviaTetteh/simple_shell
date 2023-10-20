#include "shell.h"
/**
 * get_cmd_path - function to find cmd path in sys env
 * @cmd: command
 * Return: path to the cmd does not exists
 */
char *get_cmd_path(const char *command)
{
	char *path = getenv("PATH");
	char *token = strtok(path, ":");
	char *fullCommandPath = NULL;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	while (token != NULL)
	{
		size_t buffer_size;

		buffer_size = strlen(token) + strlen(command) + 2;
		fullCommandPath = (char *)malloc(buffer_size);
		if (fullCommandPath == NULL)
		{
			perror("malloc");
			exit(1);
		}

		strcpy(fullCommandPath, token);
		strcat(fullCommandPath, "/");
		strcat(fullCommandPath, command);
		if (access(fullCommandPath, X_OK) == 0)
		{
			return (fullCommandPath);
		}
		free(fullCommandPath);
		token = strtok(NULL, ":");
	}

	return (NULL);
}

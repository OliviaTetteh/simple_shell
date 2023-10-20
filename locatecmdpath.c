#include "shell.h"
/**
 * get_cmd_path - function to find cmd path in sys env
 * @cmd: command
 * Return: path to the cmd does not exists
 */
char *get_cmd_path(const char *cmd)
{
	struct stat buffer;
	const char *paths = getenv("PATH");
	char *paths_dup = strdup(paths);
	char *p = strtok(paths_dup, ":");
	char *file_path = NULL;

	if (paths == NULL || cmd == NULL || *cmd == '\0')
		return (NULL);

	while (p)
	{
		size_t len = strlen(p) + strlen(cmd) + 2;

		file_path = (char *)malloc(len);
		if (file_path == NULL)
		{
			perror("Memory allocation error");
			free(paths_dup);
			return (NULL);
		}
		strcpy(file_path, p);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		if (stat(file_path, &buffer) == 0)
		{
			free(paths_dup);
			return (file_path);
		}
		free(file_path);
		file_path = NULL;
		p = strtok(NULL, ":");
	}
	free(paths_dup);
	if (stat(cmd, &buffer) == 0)
	{
		return (strdup(cmd));
	}
	return (NULL);
}
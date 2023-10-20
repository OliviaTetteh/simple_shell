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

	if (paths == NULL || cmd == NULL || *cmd == '\0')
		return (NULL);
	char *paths_dup;

	paths_dup = strdup(paths);
	if (paths_dup == NULL)
	{
		perror("Memory allocation error");
		return (NULL);
	}
	char *p, *file_path;

	p = strtok(paths_dup, ":");
	file_path = NULL;
	while (p)
	{
		size_t len;

		len = strlen(p) + strlen(cmd) + 2;
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
			return file_path;
		}
		free(file_path);
		file_path = NULL;
		p = strtok(NULL, ":");
	}
	free(paths_dup);
	if (stat(cmd, &buffer) == 0)
		return (strdup(cmd));
	return (NULL);
}

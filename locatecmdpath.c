#include "shell.h"
/**
 * get_cmd_path - function to find cmd path in sys env
 * @cmd: command
 * Return: path to the cmd does not exists
 */
char *get_cmd_path(char *cmd)
{
	struct stat buffer;
	const char *paths = getenv("PATH");
	if (paths == NULL || cmd == NULL || *cmd == '\0')
		return (NULL);

	char *p = strtok(strdup(paths), ":");
	char *file_path;
	while (p)
	{
		file_path = (char *)malloc(strlen(p) + strlen(cmd) + 2);
		if (file_path == NULL)
			return (NULL);

		strcpy(file_path, p);
		strcat(file_path, "/");
		strcat(file_path, cmd);

		if (stat(file_path, &buffer) == 0)
		{
			free(p);
			return (file_path);
		}
		free(file_path);
		p = strtok(NULL, ":");
	}

	if (stat(cmd, &buffer) == 0)
		return strdup(cmd);
	return (NULL);
}
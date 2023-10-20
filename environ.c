#include "shell.h"
/**
 * ocshellenv - get the current environment
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int ocshellenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: constant function prototype.
 * Return:  0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * ocshellsetenv - Initialize a new environment variable,
 * @info:  constant function prototype.
 *  Return:  0
 */
int ocshellsetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

#include "shell.h"
/**
 * find_builtin - finds a builtin command
 * @info: the parameter & return info struct
 *
 * Return: -1 if builtin not found,
 *			0 if builtin executed successfully,
 *			1 if builtin found but not successful,
 *			-2 if builtin signals exit()
 */
int find_builtin(info_t *info)
{
        int i, built_in_ret = -1;
        builtin_table builtintbl[] = {
            {"exit", ocshellexit},
            {"env", ocshellenv},
            {"help", ocshellhelp},
            {"history", ocshellhistory},
            {"setenv", ocshellsetenv},
            {"unsetenv", ocshellunsetenv},
            {"cd", ocshellcd},
            {"alias", ocshellalias},
            {NULL, NULL}};

        for (i = 0; builtintbl[i].type; i++)
                if (_strcmp(info->argv[0], builtintbl[i].type) == 0)
                {
                        info->line_count++;
                        built_in_ret = builtintbl[i].func(info);
                        break;
                }
        return (built_in_ret);
}

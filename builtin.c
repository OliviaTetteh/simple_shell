#include "shell.h"
/**
 * ocshellexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int ocshellexit(info_t *info)
{
	int exitcheck;

	if (info->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = _erratoi(info->argv[1]);
		if (exitcheck == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * ocshellhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int ocshellhelp(info_t *info)
{
	char *helptext =
	    "OAShell - the ALX Shell prj. "
	    "The following commands are available:\n"
	    "  cd       Change the working directory.\n"
	    "  exit     Exit the shell.\n"
	    "  help     Print this help text.\n";
	printf("%s", helptext);
	return (0);
}

#include "shell.h"
/**
 * check_permission - check the access permission
 * @fullCommandPath: the path to check
 */
void check_permission(char *fullCommandPath)
{
	struct stat st;

	if (stat(fullCommandPath, &st) != 0)
	{
		perror("stat");
		exit(1);
	}

	/* Check if it's a directory */
	if (!S_ISDIR(st.st_mode))
	{
		perror("is not a directory");
		exit(1);
	}

	/* Check directory permissions */
	if (access(fullCommandPath, X_OK) != 0)
	{
		perror("access");
		exit(1);
	}
}

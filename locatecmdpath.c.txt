#include "shell.h"
/**
 * get_cmd_path - function to find cmd path in sys env
 *
 * Return: path to the cmd does not exists
 */

char *get_cmd_path(char *cmd) {
        struct stat buffer;
        const char *paths;
        size_t cmd_len;
        char *paths_dup;
        char *p;
        size_t dir_len;
        char *file_path;

        paths = getenv("PATH");

        if (paths == NULL || cmd == NULL || *cmd == '\0')
                return (NULL);

        cmd_len = strlen(cmd);
        paths_dup = strdup(paths);
        p = strtok(paths_dup, ":");

        if (paths_dup == NULL)
        {
                perror("Memory allocation error");
                return (NULL);
        }

        while (p != NULL) {
                dir_len = strlen(p);
                file_path = (char *)malloc(cmd_len + 2 + dir_len);

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
                else
                {
                        free(file_path);
                        p = strtok(NULL, ":");
                }
        }

        free(paths_dup);


        if (stat(cmd, &buffer) == 0)
                return strdup(cmd);

        return (NULL);
}
                       
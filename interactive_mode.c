#include "shell.h"
/**
 * run_in_interactive_mode - Run the programme in interactive mode
 */
void run_in_interactive_mode()
{
        char cwd[1024], hostname[1024];
        char input[100];
        char *username;
        char *input = NULL;
        size_t len = 0;
        ssize_t read;

        username = getLogin();
        getcwd(cwd, sizeof(cwd));
        gethostname(hostname, sizeof(hostname));
        printf("%s@%s:%s ", username, hostname, cwd);
        read = getline(&input, &len, stdin);

        if (read == -1)
        {
                perror("getline");
                return (1);
        }

        int tokenCount;
        char **tokens;
        tokens = tokenizeString(input, &tokenCount);

        execute_cmd(tokens, tokenCount); /* Execute the command */

        /* Free allocated memory */
        for (int i = 0; i < tokenCount; i++)
        {
                free(tokens[i]);
        }
        free(tokens);
        free(input);
}
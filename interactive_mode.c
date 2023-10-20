#include "shell.h"
/**
 * run_in_interactive_mode - Run the programme in interactive mode
 */
void run_in_interactive_mode()
{
        char cwd[1024], hostname[1024];
        char *username;
        char *input = NULL;
        size_t len = 0;
        int i;
        ssize_t read;
        int tokenCount;
        char **tokens;

        username = getlogin();
        getcwd(cwd, sizeof(cwd));
        gethostname(hostname, sizeof(hostname));
        printf("%s@%s:%s ", username, hostname, cwd);
        read = getline(&input, &len, stdin);

        if (read == -1)
        {
                perror("getline");
                free(input);
                exit(0);
        }
        if (strcmp(input, "exit") == 0)
        {
                free(tokens);
                exit(0);
        }
        else
        {
                tokens = tokenize_string(input, &tokenCount);
                execute_cmd(tokens, tokenCount);
                for (i = 0; i < tokenCount; i++)
                {
                        free(tokens[i]);
                }
                free(tokens);
                free(input);
        }
}

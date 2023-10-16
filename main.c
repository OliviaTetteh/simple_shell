#include "shell.h"

int main(int ac, char **ar)
{
        char *cmd = "$ ";
        char *inputptr = NULL;
        size_t buffsize = 32;
        ssize_t input_len;
        char *input_token;
        int token_len = 0;
        char **argv = NULL;
        char *saveptr = NULL;
        const char *delimiter = " \n";

        (void) ac;
        (void) ar;

        while (1)
        {
                printf("%s", cmd);
                input_len = getline(&inputptr, &buffsize, stdin);

                token_len = 0;

                if (input_len == -1)
                {
                        printf("Exiting...\n");
                        free(inputptr);
                        exit(1);
                }

                input_token = strtok_r(inputptr, delimiter, &saveptr);

                while (input_token != NULL)
                {
                        token_len++;
                        argv = realloc(argv, token_len * sizeof(char *));
                        argv[token_len - 1] = strdup(input_token);
                        input_token = strtok_r(NULL, delimiter, &saveptr);
                }

                argv = realloc(argv, (token_len + 1) * sizeof(char *));
                argv[token_len] = NULL;

                execute_cmd(argv);
                free(argv);
        }

        free(inputptr);
        return (0);
}

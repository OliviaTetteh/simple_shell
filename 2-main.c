#include "shell.h"

int main(int ac, char **av)
{
    char *cmd = "$ ";
    char *inputptr = NULL;
    size_t buffsize = 32;
    ssize_t input_len;

    (void) ac;

    while (1)
    {
        printf("%s", cmd);
        input_len = getline(&inputptr, &buffsize, stdin);

        if (input_len == -1)
        {
            printf("Exiting...\n");
            free(inputptr);
            exit(1);
        }

        // Tokenize the input
        char *saveptr = NULL;
        char *input_token = strtok_r(inputptr, " \n", &saveptr);

        while (input_token != NULL)
        {
            printf("%s, ", input_token);
            input_token = strtok_r(NULL, " \n", &saveptr);
        }
        printf("\n");
    }

    free(inputptr);

    return 0;
}


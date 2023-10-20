#include "shell.h"
/**
 * tokenize_string - read input from the user and tokenized it
 *
 * Return: argv of inputs
 */
char **tokenize_string(const char *input, int *tokenCount)
{
        char *copy;

        copy = strdup(input);
        if (copy == NULL)
        {
                perror("strdup");
                exit(1);
        }

        char **tokens = malloc(20 * sizeof(char *));
        if (tokens == NULL)
        {
                perror("malloc");
                exit(1);
        }

        char *token = strtok(copy, " \t\n");
        *tokenCount = 0;

        while (token != NULL)
        {
                tokens[*tokenCount] = strdup(token);
                if (tokens[*tokenCount] == NULL)
                {
                        perror("strdup");
                        exit(1);
                }
                (*tokenCount)++;
                token = strtok(NULL, " \t\n");
        }
        free(copy);
        return (tokens);
}

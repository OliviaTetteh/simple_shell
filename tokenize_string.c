#include "shell.h"
/**
 * tokenize_string - read input from the user and tokenized it
 *@input: inputted text from user
 *@tokenCount: integer number of tokens
 * Return: argv of inputs
 */
char **tokenize_string(const char *input, int *tokenCount)
{
	char *copy = strdup(input);
	char **tokens = malloc(20 * sizeof(char *));
	char *token = strtok(copy, " \t\n");

	copy = strdup(input);
	if (copy == NULL)
	{
		perror("strdup");
		exit(1);
	}

	if (tokens == NULL)
	{
		perror("malloc");
		free(copy);
		exit(1);
	}

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

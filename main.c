#include "shell.h"

int main(int ac, char **av)
{
	char *cmd = "$ ";
	char *inputptr = NULL;
	size_t buffsize = 32;
	ssize_t input_len;
	char *input_token;
	int j, token_len = 0;
	const char *delimiter = " \n"; // Include newline character as a delimiter

	(void)ac;

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

		/* Tokenize the input */
		char **argv = NULL;
		char *saveptr = NULL;
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

		for (j = 0; j < token_len; j++)
		{
			printf("%s, ", argv[j]);
			free(argv[j]);
		}
		printf("\n");

		free(argv);
	}

	free(inputptr);

	return (0);
}

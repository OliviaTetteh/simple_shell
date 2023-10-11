#include "shell.h"

int main(int ac, char **av)
{
	char *cmd = "$ ";
	char *inputptr = NULL, *inputptr2nd = NULL;
	size_t buffsize = 32;
	ssize_t input_len;
	char *input_token;
	int j, token_len = 0;
	const char *delimiter = " ";

	(void)ac;

	while (1)
	{
		printf("%s", cmd);
		input_len = getline(&inputptr, &buffsize, stdin);

		if (input_len == -1)
		{
			printf("Exiting...\n");
			exit(1);
		}

		inputptr2nd = malloc(sizeof(char) * input_len);

		if (inputptr2nd == NULL)
		{
			perror("Memory allocation error!");
			return (-1);
		}

		strcpy(inputptr2nd, inputptr);

		input_token = strtok(inputptr2nd, delimiter);

		while (input_token != NULL)
		{
			token_len++;
			input_token = strtok(NULL, delimiter);
		}
		token_len++;

		char **argv = malloc(sizeof(char *) * token_len);

		input_token = strtok(inputptr2nd, delimiter);

		for (j = 0; input_token != NULL; j++)
		{
			argv[j] = malloc(strlen(input_token) + 1); // +1 for the null terminator
			strcpy(argv[j], input_token);
			input_token = strtok(NULL, delimiter);
		}
		argv[j] = NULL;

		for (int i = 0; i < token_len - 1; i++)
		{
			printf("%s, ", argv[i]);
			free(argv[i]); // Free individual token strings
		}
		printf("\n");

		free(argv); // Free the array of token pointers
	}

	free(inputptr);
	free(inputptr2nd);

	return (0);
}
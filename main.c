#include "shell.h"

int main(char **argv)
{
	char *cmd = "$ ";
	char *inputptr;
	size_t buffsize = 32;
	ssize_t input_len;
	char *input_token;
	(void) argv;

	while (1)
	{
		printf("%s", cmd);
		input_len = getline(&inputptr, &buffsize, stdin);
		
		if (input_len == -1)
			exit(1);
		
		printf("You typed: %s\n", inputptr);
		input_token = strtok(*input," ");
		
		argv = malloc(sizeof(char *) *input_len);
		for (int j = 0; input_token != NULL; j++)
		{
			argv[j] = malloc(sizeof(char) * strlen(input_token));
			strcpy(argv[j], input_token);
			input_token = strtok(NULL, " ");
		}
		argv[j] = NULL;
	}


	free(inputptr);
	return (0);
	
}

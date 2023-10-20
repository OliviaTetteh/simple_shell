#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

void run_in_interactive_mode();

int execute_cmd(char **argv);

char **tokenize_string(const char *input, int *tokenCount);

char *get_cmd_path(const char *cmd);

#endif

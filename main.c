#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * main - this is a simple shell command interpreter
 * @ac: number of arguments
 * @av: arguments
 * @env: environment of the program
 *
 * Return: Always 0
 */
int main(int ac, char **av, char **env)
{
	char **argv;
	char *line = NULL;
	size_t size;
	unsigned int i;

	if (ac > 1)
	{
		/*non interative moode*/
		fprintf(stderr, "Usage: simple_shell\n");
		return (1);
	}
	i = 1;
	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&line, &size, stdin) == -1)
		{
			perror("Error:");
			return (1);
		}
		line = strtok(line, "\n");
		if (!auth_one_word(line) || !findfile(line))
		{
			fprintf(stderr, "%s: No such file or directory\n", av[0]);
			continue;
		}
		argv = split(line, " ");
		if (argv == NULL)
		{
			fprintf(stderr, "Error: failed to split the string\n");
			return (1);
		}
		execute(argv, env);
		i++;
	}
	free(line);
	free(argv);
	return (0);
}

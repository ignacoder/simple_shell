#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "shell.h"

/**
 * execute - executes a specific program
 * @argv: array of pointers to informations of the program
 * @env: environment of the program
 *
 * Return: 0 on sucess, -1 on failure
 */
int execute(char **argv, char **env)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (-1);
	}
	else if (child_pid == 0)
	{
		if (execve(argv[0], argv, env) == -1)
		{
			perror("Error:");
		}
	}
	else
		waitpid(child_pid, &status, 0);
	return (0);
}

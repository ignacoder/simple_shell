#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "shell.h"

/**
 * auth_one_word - checks for existence of more than one word in @str
 * @str: string
 *
 * Return: 1 if one word match, 0 otherwise
 */
int auth_one_word(char *str)
{
	unsigned int i;

	if (str == NULL || *str == '\0')
		return (0);
	for (i = 0; str[i]; i++)
		if (str[i] == ' ')
			return (0);
	return (1);
}

/**
 * findfile - checks for existence of a file
 * @path: path to the file
 *
 * Return: 1 if the file exist, 0 otherwise
 */
int findfile(char *path)
{
	struct stat st;

	if (path == NULL || *path == '\0')
		return (0);
	if (stat(path, &st) == 0)
		return (1);
	return (0);
}

/**
 * split - split a string
 * @str: string
 * @delim: delimiter for the string
 *
 * Return: pointer to array of strings
 */
char **split(char *str, char *delim)
{
	char *word;
	char **argv;
	int i;

	argv = malloc(sizeof(char *));
	if (argv == NULL)
		return (NULL);
	word = strtok(str, delim);
	*argv = word;
	for (i = 1; word != NULL; i++)
	{
		word = strtok(NULL, delim);
		argv = realloc(argv, (i + 1) * sizeof(char *));
		if (argv == NULL)
			return (NULL);
		argv[i] = word;
	}
	return (argv);
}

#ifndef SHELL_H
#define SHELL_H

int auth_one_word(char *str);
int findfile(char *path);
char **split(char *str, char *delim);
int execute(char **argv, char **env);

#endif

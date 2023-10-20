#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_COMMAND_LENGTH 100

extern char **environ;
char **strtostrs(const char *str, char *delim);
char *_which(char *str);
void env(void);
void _exit(int n);
void freecmd(char **strar);
void ownexecve(char *cmd, char **commands, char *argvo);
void noninteract(char *argvo);
void print(char *str, int stream);
void rm_newline(char *input);
void rm_comment(char *input);
<<<<<<< HEAD
int execute_builtin(char **command, char *argvo);
=======
void ctrlc(int sig);
>>>>>>> 4b44b06538838803918dcf5e371e218659baa461

#endif

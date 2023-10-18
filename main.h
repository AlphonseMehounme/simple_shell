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
char **strtostrs(const char *str);
char *_which(char *str);
void env(void);
void _exit(int n);
void freecmd(char **strar);
void ownexecve(char *cmd, char **commands, char *argvo);

#endif

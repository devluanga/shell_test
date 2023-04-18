#ifndef main_h
#define main_h


#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void execfile(char **argv);
char *filepath(char *command);

#endif

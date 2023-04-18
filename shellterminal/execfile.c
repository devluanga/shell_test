#include "main.h"

void execfile(char **argv)
{
    char *command = NULL, *comloc = NULL;
    if (argv)
    {
        command = argv[0];

        /*we need to implement filepath in this file*/
        comloc = filepath(command); /*comloc holds the return value of filepath*/

        if (execve(comloc, argv, NULL) == -1)
        {
            perror("failed:error!!\n");
        }
        
    }
        
}
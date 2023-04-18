#include "main.h"

char *filepath(char *command)
{
    char *path, *cpath, *ptokens, *fpath; /*two variables will hold the path for the given command*/
    struct stat bufsize;
    int clength, dirl;

    path = getenv("PATH");
    
    if (path)
    {
        cpath = strdup(path); /*duplicate path*/
        ptokens = strtok(cpath, ":");/*create tokens of the path*/

        clength = strlen(command);

        while (ptokens != NULL)
        {
            dirl = strlen(ptokens);
            fpath = malloc(clength+dirl+2);

            strcpy(fpath, ptokens);
            strcat(fpath, "/");
            strcat(fpath, '\0');
            strcat(fpath, command);

            if (stat(fpath, &bufsize) == 0)
            {
               free(cpath);

               return (fpath);
            }
            else
            {
                free(cpath);
                ptokens = strtok(NULL, ":");
            }           
            
        }
        free(cpath);

        if (stat(command, &bufsize) == 0)
        {
            return (command);
        }
        return (NULL);
    }
    return (NULL);
}
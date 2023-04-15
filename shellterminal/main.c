#include "main.h"

/*ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/

int main(int var, char **argv)
{
    
    char *prompt, *lineptr;
    ssize_t input_;
    size_t n = 0;

    /*print prompt*/
    prompt = "devluanga: ~$";

    (void)var; (void)argv;

    while (1)
    {
        /* */
        printf("%s", prompt);

        input_ = getline(&lineptr, &n, stdin);

        if (input_ == -1)
        {
            printf(" exit..\n");
            /*exit(EXIT_FAILURE);*/
	    return (-1);
        }
        
        printf("%s\n", lineptr);
        free(lineptr);
    }
    return (0);
}

#include "main.h"

/*ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/

int main(int var, char **argv)
{
    /*lineptr & lineptr2 will hold user input*/
    char *prompt, *lineptr = NULL;
    char *lineptr2 = NULL, *token_t; /*holds a copy of input without delimeters*/
    ssize_t input_; 
    size_t n = 0;
    const char *delim = "\n";
    int x, tokenval;

    /*print prompt*/
    prompt = "devluanga: ~$";

    (void)var;

    /*creating an infinite loop for prompt input*/
    while (1)
    {
        printf("%s", prompt);
        input_ = getline(&lineptr, &n, stdin);

        /*check if EOF or getline failed*/
        if (input_ == -1)
        {
            printf("quit..\n");
            exit(EXIT_FAILURE);
            return (-1);
        }

        /*dynamic memory allocation*/
        lineptr2 = malloc(sizeof(char)*input_);
        if (lineptr2 == NULL)
        {
            perror("Memory allocation failed\n");
            return (-1);            
        }
        /*copy user input*/
        strcpy(lineptr2, lineptr);

        /**
         *needs to split the input string to an array of chars
         *get the total tokens use strtok
         *use strtok function to get tokens
         */

        token_t = strtok(lineptr, delim);
        
        while (token_t != NULL)
        {
            tokenval++;
            token_t = strtok(NULL, delim);
            
        }
        tokenval++;

        /*
         *allocate memory to hold tokens
         *use strtok to get tokens (tokenization)
         *then store the tokens in an array
         */
        argv = malloc(sizeof(char *)*tokenval);
        token_t = strtok(lineptr2, delim);

        for (x = 0; token_t != NULL; x++)
        {
            argv[x] = malloc(sizeof(char )* strlen(token_t));
            strcpy(argv[x], token_t);

            /*printf("%s ", argv[x]); check if our array is create*/

            token_t = strtok(NULL, delim);

        }
        argv[x] =NULL;

        /*call the execve function*/
        execfile(argv);  
         
        for (x = 0; argv[x] != NULL; x++)
        {
            free(argv[x]);
        }
        free(argv);
    }

    /*free all the allocated memories*/
    free(lineptr2);
    free(lineptr);
    return (0);
}
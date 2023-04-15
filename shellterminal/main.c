#include "main.h"

/*ssize_t getline(char **lineptr, size_t *n, FILE *stream);*/

int main(int var, char **argv)
{
    /*lineptr & lineptr2 will hold user input*/
    char *prompt, *lineptr;
    char *lineptr2, *token_t; /*holds a copy of input without delimeters*/
    ssize_t input_; 
    size_t n = 0;
    const char *delim = '\n';
    int x, tokenval;

    /*print prompt*/
    prompt = "devluanga: ~$";

    (void)var;

    while (1)
    {
        /* */
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

        /*get the total tokens use strtok*/

        token_t = strtok(lineptr, delim);
        
        while (token_t != NULL)
        {
            tokenval++;
            token_t = strtok(NULL, delim);
            
        }
        tokenval++;
        /*allocate memory to hold tokens*/
        argv = malloc(sizeof(char *)*tokenval);

        /*create array to store the tokens*/
        token_t = strtok(lineptr2, delim);
        for (x = 0; token_t != NULL; x++)
        {
            argv[x] = malloc(sizeof(char )* strlen(token_t));
            strcpy(argv[x], token_t);

            token_t = strtok(NULL, delim);

        }
        argv[x] =NULL;               

        /*test on our array*/

        for (int i = 0; i < tokenval-1; i++)
        {
            printf("%s ", argv[x]);
            return (0);
        }
        
                
        printf("%s\n", lineptr);
        free(lineptr);


        free(lineptr2);
        free(argv);
    }
    return (0);
}

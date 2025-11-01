#include "my_shell.h"


// shell loop
// input parser
//command execution
//handle built in commands
//environment variables
//manage path
//error handling

void shell_loop(char** env){

    char* input = NULL;
    size_t input_size = 0;

    char** args;
    while (1){
        printf("[lucid_shell]> ");
        if (getline(&input, &input_size, stdin) == -1) // means end of file (EOF), CTRL + D
        {
            perror("getline");
            break;
        }
        //printf("input: %s", input);
        
        args = input_parser(input);
    }
}

int main(int argc, char** argv, char** env){
    (void)argc;
    (void)argv;

    shell_loop(env);
    return 0;
}
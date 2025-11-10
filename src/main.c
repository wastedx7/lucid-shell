#include "my_shell.h"

//shell loop
//input parser
//command execution
//handle built in commands
//environment variables
//manage path
//error handling

//cd, pwd, echo, env, setenv, unsetenv, which, exit
int shell_built(char** args, char** env, char* initial_directory){

    (void)initial_directory;

    if(my_strcmp(args[0], "cd") == 0){
        return command_cd(args, initial_directory);
    }
    else if(my_strcmp(args[0], "pwd") == 0){
        return command_pwd();
    }
    else if(my_strcmp(args[0], "echo") == 0){
        return command_echo(args, env);
    }
    else if(my_strcmp(args[0], "env") == 0){
        return command_env(env);
    }
    else if(my_strcmp(args[0], "which") == 0){
        // return command_which(args, env);
    }
    else if(my_strcmp(args[0], "exit") == 0 || my_strcmp(args[0], "quit") == 0){
        printf("nikal bkl\n");
        exit(EXIT_SUCCESS);
    }
    else {
        // not a builtin command
        // executor(); // -- for Binary commands: ls, cat, grep
    }
    return 0;
}

void shell_loop(char** env){

    char* input = NULL;
    size_t input_size = 0;

    char** args;
    char* initial_directory = getcwd(NULL, 0);
    while (1){
        printf("[lucid-shell]> ");
        if (getline(&input, &input_size, stdin) == -1) // means end of file (EOF), CTRL + D
        {
            perror("getline");
            break;
        }
        // printf("input: %s", input);
        
        args = input_parser(input);
        // for(size_t i=0; args[i]; i++){
        //     printf("Args: %s", args[i]);
        //     printf("\n");
        // }
        if (args[0]){
            shell_built(args, env, initial_directory); 
        }
    }
    free_tokens(args);

}

int main(int argc, char** argv, char** env){
    (void)argc;
    (void)argv;

    shell_loop(env);
    return 0;
}


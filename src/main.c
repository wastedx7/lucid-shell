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
    if(strcmp(args[0], "cd")){
        return command_cd(args, initial_directory);
    }
    else if(strcmp(args[0], "pwd")){
        command_pwd();
    }
    else if(strcmp(args[0], "echo")){
        command_echo(args, env);
    }
    else if(strcmp(args[0], "env")){
        command_env(env);
    }
    else if(strcmp(args[0], "which")){
        command_which(args, env);
    }
    else if(strcmp(args[0], "exit") || strcmp(args[0], "quit")){
        exit(EXIT_SUCCESS);
    }
    else {
        // not a builtin command
    }
}


void shell_loop(char** env){

    char* input = NULL;
    size_t input_size = 0;

    char** args;
    char* initial_directory = getcwd(NULL, 0);
    while (1){
        printf("[lucid_shell]> ");
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
        if (!args[0]){
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


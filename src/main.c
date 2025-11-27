#include "my_shell.h"

//shell loop
//input parser
//command execution
//handle built in commands
//environment variables
//manage path
//error handling

void display_help() {
    printf("Available commands:\n");
    printf("\tcd <directory>      - Change the current directory.\n");
    printf("\tpwd                 - Print the current working directory.\n");
    printf("\techo <text>         - Print the given text.\n");
    printf("\tenv                 - Display all environment variables.\n");
    printf("\tsetenv VAR=value    - Set an environment variable.\n");
    printf("\tunsetenv <variable> - Remove an environment variable.\n");
    printf("\twhich <command>     - Locate an executable in the system's PATH.\n");
    printf("\t.help               - Display this help message.\n");
    printf("\texit or quit        - Exit the shell.\n");
}

//cd, pwd, echo, env, setenv, unsetenv, which, exit
int shell_built(char** args, char** env, char* initial_directory){

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
        return command_which(args, env);
    }
    else if(my_strcmp(args[0], ".help") == 0){
        display_help();
        return 0;
    }
    else if(my_strcmp(args[0], "exit") == 0 || my_strcmp(args[0], "quit") == 0){
        printf("exit successful\n");
        exit(EXIT_SUCCESS);
    }
    else {
        return executor(args, env); // -- for Binary commands: ls, cat, grep
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

        if(!args[0]){
            return;
        } else if(my_strcmp(args[0], "setenv") == 0){
            env = command_setenv(args, env);
        } else if(my_strcmp(args[0], "unsetenv") == 0){
            env = command_unsetenv(args, env);
        } else {
            shell_built(args, env, initial_directory); 
        }
    }
    free_tokens(args);
    free(env);
}

int main(int argc, char** argv, char** env){
    (void)argc;
    (void)argv;

    shell_loop(env);
    return 0;
}


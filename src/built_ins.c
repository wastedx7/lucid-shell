#include "my_shell.h"

int command_cd(char** args, char* initial_directory){
    (void)initial_directory;
    if(args[1] == NULL){
        printf("cd: expected path\n");
    } else if(chdir(args[1]) == 0){
        printf("Trying to cd into %s\n", args[1]);
    } else {
        perror("CD");
    }
    return 0;
}
int command_pwd(){
    char* cwd = NULL;
    size_t size = 0;
    // use dynamic allocation
    cwd = getcwd(NULL, size);
    if (cwd != NULL){
        printf("cwd : %s\n", cwd);
        free(cwd);
    } else {
        perror("getcwd");
    }
    return 0;
}

int command_echo(char** args, char** env){
    (void)env;
    int new_line = 1; // default echo ends with newline
    int i = 1; // for skipping newline

    if(args[1] && my_strcmp(args[1], "-n") == 0){
        new_line = 0;
        i++;
    }

    for(; args[i]; i++){
        if(args[i][0] == '$') { // to handel env variables
            char* value = my_getenv(args[i] + 1, env); // skip $ and fetch the main variable
            if(value){
                printf("%s", value);
            }
        } else {
            printf("%s", args[i]);
        }
        if(args[i+1]){
            printf(" ");
        }
    }
    if(new_line){
        printf("\n");
    }
    return 0;
}

int command_env(char** env){
    size_t index = 0;
    while(env[index]){
        printf("%s\n", env[index]);
        index++;
    }
    return 0;
}
int command_which(char** args, char** env){
    
    if(!args[1]){
        printf("which: required argument\n");
        return 1;
    }
    // list of built in cmds
    const char* built_in_commands[] = {"cd", "pwd", "echo", "env", "setenv", "unsetenv", "which", "exit", NULL};
    for(size_t i=0; built_in_commands[i]; i++){
        if(my_strcmp(args[1], built_in_commands[i]) == 0){
            printf("%s: built in command\n", args[1]);
            return 0;
        }
    }
    // check external commands
    // char* full_path = 
    find_command_in_path(args[1], env);
    
    return 1;
}

// function to search command in path
char* find_command_in_path(const char* command, char** env){
    char* path_env = NULL;
    char* path = NULL;
    char* token = NULL;
    char full_path[1024];

    //locate the path env
    path_env = my_getenv("PATH", env);
    
    if(!path_env){
        return NULL; // no path
    }

    // duplicate the path to avoid conflict 
    path = my_strdup(path_env);
    return NULL;
}
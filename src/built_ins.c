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
    
    int new_line = 1; // default echo ends with newline
    int i = 1; // for skipping newline

    if(args[1] && my_strcmp(args[1], "-n") == 0){
        new_line = 0;
        i++;
    }

    for(; args[i]; i++){
        if(args[i][0] == '$') { // to handel env variables
            (void)env;
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

// int command_env(char** env){}
// int command_which(char** args, char** env){}

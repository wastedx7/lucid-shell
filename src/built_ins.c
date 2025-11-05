#include "my_shell.h"

int command_cd(char** args, char* initial_directory){
    (void)initial_directory;
    if(args[1] == NULL){
        printf("cd: expected path\n");
    } else if(chdir(args[1]) != 0){
        printf("CD worked\n");
    } else {
        perror("CD");
    }
    return 0;
}
// int command_pwd(){

// }
// int command_echo(char** args, char** env){

// }
// int command_env(char** env){

// }
// int command_which(char** args, char** env){

// }

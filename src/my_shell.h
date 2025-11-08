#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

#define MAX_INPUT 1024
#define MAX_PATH 4096

char** input_parser(char* input);
void free_tokens(char** tokens);
int shell_built(char** args, char** env, char* initial_directory);

// Built-in command funtion implementations 
int command_cd(char** args, char* initial_directory);
int command_pwd();
int command_echo(char** args, char** env);
int command_env(char** env);
int command_which(char** args, char** env);

char** command_setenv(char** args, char** env);
char** command_unsetenv(char** args, char** env);

//helper 
int my_strcmp(const char* str1, const char* str2);
char* my_getenv(const char* name, char** env);
int my_strlen(const char* str);
int my_strncmp(const char* str1, const char* str2, size_t n);

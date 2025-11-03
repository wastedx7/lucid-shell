#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT 1024
char** input_parser(char* input);
void free_tokens(char** tokens);
int shell_built(char** args, char** env, char* initial_directory);
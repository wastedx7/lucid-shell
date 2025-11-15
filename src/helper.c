#include "my_shell.h"

//0: strings are equal 
//0< : str1 < str2
//0> : str1 > str2
int my_strcmp(const char* str1, const char* str2){
    while(*str1 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

int my_strlen(const char* str){
    size_t len = 0;
    while(*str){
        len++;
        str++;
    }
    return len;
}

// 0: if strings are equal to n characters
// <0: if str1 < str2 in the first n characters
// >0 : if str1 > str2 in the first n characters
int my_strncmp(const char* str1, const char* str2, size_t n){
    size_t i = 0;
    while(i<n && str1[i] && str2[i]){
        if(str1[i] != str2[i]){
            return (unsigned char)str1[i] - (unsigned char)str2[i];
        }
        i++;
    }
    if(i == n){
        return 0;
    }
    
    return (unsigned char)str1[i] - (unsigned char)str2[i];
}

char* my_getenv(const char* name, char** env){
    if(name == NULL || env == NULL){
        return NULL;
    }
    size_t name_len = my_strlen(name);
    for(size_t i=0; env[i]; i++){
        if(my_strncmp(env[i], name, name_len) == 0 && env[i][name_len] == '='){
            return &env[i][name_len + 1];
        }
    }
    return NULL;
}

char* my_strdup(const char* str){
    if(!str) {return NULL;}
    size_t len = my_strlen(str);
    char* duplicated = (char*)malloc((len+1)*sizeof(char));
    if (!duplicated) {return NULL;}
    my_strcpy(duplicated, str);
    return duplicated;
}

char* my_strcpy(char* dest, const char* src){
    char* ret = dest;
    while(*src){
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return ret;
}
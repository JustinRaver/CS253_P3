//-----------------------------------------------------------------
//
//definition of function doCopy copies lines of test read from stdin to stdout,just as would the linux cat utility
//-----------------------------------------------------------------

#include <stdio.h>
#include<string.h>
#include "copy.h"
#define MAX 1024

int doCopy(void){
    //char to store input from std in
    char line[MAX];
    //while fgets doesnt return null or EOF reads in lines and prints to stdout
    while(fgets(line, MAX,stdin) != NULL){
        fputs(line,stdout);  
    }
    return 0;
}   

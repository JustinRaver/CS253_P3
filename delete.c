//------------------------------------------------------------------------
//definiton of function doDelete deletes user soecified lines in file
//returns int representing state of program at completion 0 for normal 
//non-zero for abnormal exit
//------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "delete.h"
# define MAX 1024

int doDelete(char *line1, char *line2){
    //char array to store input from std in
    char line[MAX];
    //counter for line number starting at line 1
    int i = 1;
    //while fgets doesnt return 0 or EOF
    while(fgets(line, MAX,stdin) != NULL){
        //startLine variable equal to the value passed in by user 
        int startLine = atoi(line1);
        //finshLine variable equal to the value passed in by user 
        int finishLine = atoi(line2);
        //if i less that start or greater then finish then print line to standard out
        if(i < startLine ||  i > finishLine){
            fputs(line, stdout);
        }
        i++;
    }   
    return 0; 
}

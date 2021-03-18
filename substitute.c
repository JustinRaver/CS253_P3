//-----------------------------------------------------------------------------
//definition of function doSubstitute substitutes user specified string with 
//pattern passed in as parameters to function. returns int representing state of 
//program at completion 0 for normal and non-zero for abnormal status
//----------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "substitute.h"
# define MAX 1024

int doSubstitute(char *regex, char *string){
    int oldWordLength = strlen(regex);			//int value for length of patter
    int newWordLength = strlen(string);			//int value for length of string to be inserted
    char line[MAX];					//char array to store input from stdin
    char *linePointer;					//pointer to the line array  
    int sizeOfLine;
    char newLine[MAX];					// char array for the newline created 
    char *newLinePointer;				// char pointer to the newLine array
    char *match;
   
    while(fgets(line, MAX,stdin) != NULL){		//while fgets doesnt return 0 or EOF
        linePointer = line;				//line pointer points to the start address of line
        newLinePointer = newLine;			//newLine pointer points to the start of the newLine
        strcpy(newLine, "");				//clears the newLine
        match = strstr(linePointer,regex);		//sets match pointer to location of the first match
        if(match == NULL){
            fputs(line,stdout);
        }else{
            while(match != NULL){			//while the match pointer isnt null

                sizeOfLine = strlen(linePointer);	//size of the string with current linePointer position
                //concats the portion before the match
                strncat(newLinePointer,linePointer,match-linePointer);
                //concats the replacement word
                strncat(newLinePointer,string,newWordLength);
 	        //increments the line pointer to address after the replaced word
 	        linePointer += sizeOfLine-strlen(match)+oldWordLength;        
                //updates the match location to the next match
                match = strstr(linePointer,regex);
            }
            //concats the end of the line
            strncat(newLinePointer,linePointer,sizeOfLine);
            fputs(newLine,stdout);			//print line to standard out 
            }
        }
    return 0;						//return 0 to for normal exit
}

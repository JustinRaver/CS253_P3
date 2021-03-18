//-----------------------------------------------------------------------------
//
// NAME
//  sed253 -- Simplified editor
//
// SYNOPSIS
//  sed253
//  sed253 -s regex string
//  sed253 -d line1 line2
//
// DESCRIPTION
//  Simplified editor.  Copies lines read from stdin to stdout.  Options:
//
//  -s Substitute every occurrence of regex with string
//  -d Delete line1 through line2 inclusive
//
// ERRORS
//  Prints usage message and exits abnormally for invalid commands.  Prints an
//  error message and exits abnormally for other issues.
//
// LIMITATIONS
//  Lines of text are limited to a maximum of 1023 chars.
//
// AUTHORS
//  Epoch...................................................................jrc
//
//-----------------------------------------------------------------------------

//Bring in the definitions for our helper functions
#include "copy.h"
#include "substitute.h"
#include "delete.h"


//-----------------------------------------------------------------------------
// function prints usage for sed exits with abnormal status 2
// ----------------------------------------------------------------------------
void usage(void) {
    //print usage message to stderr
    printf("usage: sed253 [-s pattern string] [-d line1 line2] ");
    //force exit abnormal status 1
    exit(1);
}
//-----------------------------------------------------------------------------
// main -- the main function
//-----------------------------------------------------------------------------
int main(int argc, char **argv) {

    int exitStatus = 0; //intitialize normal exit status
    //checks for args of length 4
    if(argc == 4){
        //checks content for the delete flag
        if(strcmp(argv[1],"-d")==0){   
            char *line1 = argv[2];
            char *line2 = argv[3];
            //Verifies that the strings are not empty
            if((strlen(line1)==0) || (strlen(line2)==0)){
                usage();
            }else{
                //sets exit status to the return int of the doDelete method
                exitStatus = doDelete(line1,line2);
            }
         //checks for the subsitute flag
         }else if(strcmp(argv[1],"-s") == 0){
            char *pattern = argv[2];
            char *string = argv[3];
            //Verifies that the string are not empty
            if((strlen(pattern)==0) || (strlen(string)==0)){
                //prints usage to user
                usage();
            }else{ 
                //sets exit status to return int of the doSub method
                exitStatus = doSubstitute(pattern,string);
            }    
        } else{
            //print usage 
            usage();
            }          
    }else if(argc == 1){
        exitStatus = doCopy();        
    }else{
        //prints usage
        usage();
    }
    
  return exitStatus;
}


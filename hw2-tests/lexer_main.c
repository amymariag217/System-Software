/* $Id: lexer_main.c,v 1.14 2023/10/06 07:56:47 leavens Exp $ */

#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include "file_location.h"
#include "ast.h"
//#include "pl0_lexer.l"

//We pass the name of a text file to be tokenized
int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

     // Loop through the input files provided in the command-line arguments
    for (int i = 1; i < argc; i++) 
    {
        char *filename = argv[i];

        if (filename == NULL) 
        {
            fprintf(stderr, "Input file not provided.\n");
            return 1;
        }

        lexer_init(filename);
        lexer_output();
    }

    return 0;
}


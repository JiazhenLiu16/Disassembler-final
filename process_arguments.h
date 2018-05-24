/*
 * This file provides the signature for the process_arguments function.
 */

#ifndef _PROCESS_ARGUMENTS_H
#define _PROCESS_ARGUMENTS_H

#include <stdio.h>
#include <string.h>

#include "printFuncs.h"

FILE * process_arguments(int argc, char * argv[]);

extern const int SAME;		/* useful for making strcmp readable */
                                /* e.g., if (strcmp (str1, str2) == SAME) */

#endif

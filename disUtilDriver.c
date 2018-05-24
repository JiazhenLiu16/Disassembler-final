/*
 * main function in disassembler.c
 *
 * This program reads lines from a file.  For each line, the program
 *      calls verifyMIPSInstruction.  If the line contains characters
 *      representing a valid MIPS instruction, the program will translate
 *      the binary number into the MIPS instruction.
 *
 * Usage:
 *          name [ filename ] [ 0|1 ]
 *      where "name" is the name of the executable, "filename" is an
 *      optional file containing the input to read, and " 0" or
 *      "1" specifies that debugging should be [l.turned off or on,
 *      respectively, regardless of any calls to debug_on, debug_off,
 *      or debug_restore in the program.  Both arguments are optional;
 *      if both are present they may appear in either order.  If no
 *      filename is provided, the program reads its input from stdin.
 *      If no debugging choice is provided, the program prints debugging
 *      messages, or not, depending on indications in the code.
 *
 * Input:
 *      The program reads its input from a file passed in as a parameter
 *      on the command line, or reads from the standard input.
 *      To test verifyMIPSInstruction, the file should contain ...
 *
 *              DESCRIBE NECESSARY TEST CASES HERE
 *
 * Output:
 *      For each valid line, the program prints a series of instructions.
 *
 *      For each invalid line, the program prints an error message to
 *      stderr saying so.  (The program also prints an error message if
 *      it cannot open the file.)
 *
 * Author: Jiazhen Liu
 *
 * Creation Date: 2018/5/13
 *
 */

/* include files go here */
#include "disUtil.h"

const int SAME = 0;		/* useful for making strcmp readable */
                                /* e.g., if (strcmp (str1, str2) == SAME) */

int main (int argc, char *argv[])
{
    FILE * fptr;               /* file pointer */
    char   buffer[BUFSIZ];     /* place to store line that is read in */
    int    length;             /* length of line read in */
    int    lineNum = 0;        /* keep track of input line numbers */
    char *bufferpointer;       
     
    /* Process command-line arguments (if any) -- input file name
     *    and/or debugging indicator (1 = on; 0 = off).
     */
    fptr = process_arguments(argc, argv);
    if ( fptr == NULL )
    {
        return 1;   /* Fatal error when processing arguments */
    }

    /* Can turn debugging on or off here (debug_on() or debug_off())
     * if not specified on the command line.
     */

    /* Continuously read next line of input until EOF is encountered.
     * Each line should contain a valid MIPS machine language instruction
     * (represented as 32 character '0's and '1's) and newline.
     */
    while (fgets (buffer, BUFSIZ, fptr))   /* fgets returns NULL if EOF */
    {
        lineNum++;

        /* If the last character in the string is a newline, "remove" it
         * by replacing it with a null byte.
         */
        length = strlen(buffer);
        if (buffer[length - 1] == '\n')
            buffer[--length] = '\0';      /* remove; pre-decrement length */
        printf ("\nLine %d: %s\n", lineNum, buffer);
        printDebug ("Length: %d\n", length);

        /* Verify that the string contains 32 '0' and '1' characters.  If
         * it does,translates the characters into instructions.
         * If the string is invalid, verifyMIPSinstruction should print
         * an informative error message.
         */
        bufferpointer=buffer;
        verifyMIPSInstruction(lineNum,bufferpointer);
        //If the number is wrong, print the error.
        if (verifyMIPSInstruction(lineNum,bufferpointer)==0)
        {
            printf("error on line %d", lineNum);
            continue;
        }
        //R format.
        int opcode = binToDec(buffer,0,5);
        if (opcode==0)
        {
            int functcode = binToDec(buffer,26,31);
         if (functcode==0||functcode==2)
         printf("%s %s %s %d\n",proRformat(functcode),getRegName(binToDec(buffer,16,20)),getRegName(binToDec(buffer,11,15)),binToDec(buffer,21,25));
         else if (functcode==8)
         printf("%s %s\n","jr",getRegName(binToDec(buffer,6,10)));
         else
         printf("%s %s %s %s\n",proRformat(functcode),getRegName(binToDec(buffer,16,20)),getRegName(binToDec(buffer,6,10)),getRegName(binToDec(buffer,11,15)));
        }
        //J format.
        else if (opcode==2)
        printf("%s %d\n","j",binToDec(buffer,6,31)*4);
        else if (opcode==3)
        printf("%s %d\n","jal",binToDec(buffer,6,31)*4);
        //I format.
        else if (opcode==4||opcode==5)
        printf("%s %s %s %d\n",proIformat(opcode),getRegName(binToDec(buffer,6,10)),getRegName(binToDec(buffer,11,15)),binToDec(buffer,16,31));
        else if (opcode==8||opcode==9||opcode==12||opcode==13)
        printf("%s %s %s %d\n",proIformat(opcode),getRegName(binToDec(buffer,11,15)),getRegName(binToDec(buffer,6,10)),binToDec(buffer,16,31));
        else if (opcode==15)
        printf("%s %s %d\n",proIformat(opcode),getRegName(binToDec(buffer,11,15)),binToDec(buffer,16,31))；
        else if (opcode==35||opcode==43)
        printf("%s %s %d %s\n", proIformat(opcode),getRegName(binToDec(buffer,11,15)),binToDec(buffer,16,31),getRegName(binToDec(buffer,6,10)));
    }

    /* End-of-file encountered; close the file. */
    fclose (fptr);
    return 0;
}

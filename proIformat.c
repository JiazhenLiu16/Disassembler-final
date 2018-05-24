/*
 * proIformat
 *
 * This function translates the decimal numbers(parameter) into the I format 
 * operations.
 *
 * char proIformat(int number)
 *   Pre-condition:  the decimal number is meaningful to I format operation.
 *   Returns: the I format operation.
 *
 *
 * Implementation:
 * The proIformat function converts the decimal numbers(parameter) into the I format 
 * operations. 
 * 
 *
 * Author: Jiazhen Liu
 *	with assistance from: TAs
 *
 * Creation Date: 2018/5/13
 *
 */

char * proIformat (int number)
/* returns the I format operation */
{
/* Create a static (persistent) array of I format operations.
*/
static char * funcArray[] = {	
"beq","bne","fyx","www","addi","addiu","yuw","weg","andi","ori","esv","lui"
};
if (number==35)
return "lw";
else if (number==43)
return "sw";
else if (number>4||number<15 && number!=6&&number!=7&&number!=10&&number!=11&&number!=14)
return funcArray[number-4];
/* DOES NOT RETURN CORRECT VALUE !!! */
else 
 return "This is not the correct return value.";
}
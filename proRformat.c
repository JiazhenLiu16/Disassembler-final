/*
 * proRformat
 *
 * This function translates the decimal numbers(parameter) into the R format 
 * operations.
 *
 * char proIformat(int number)
 *   Pre-condition:  the decimal number is meaningful to R format operation.
 *   Returns: the R format operation.
 *
 *
 * Implementation:
 * The proIformat function converts the decimal numbers(parameter) into the R format 
 * operations. 
 * 
 *
 * Author: Jiazhen Liu
 *	with assistance from: TAs
 *
 * Creation Date: 2018/5/13
 *
 */

char * proRformat (int number)
/* returns the R format operation */
{
/* Create a static (persistent) array of R format operations.
*/
static char * funcArray[] = {	
"add","addu","sub","subu","and","or","ahhhh","nor","qwe","jya","slt","sltu"
};
if (number==0)
return "sll";
else if (number==2)
return "srl";
else if (number==8)
return "jr";
else if (number>32||number<43 && number!=38&&number!=40&&number!=41)
return funcArray[number-32];
/* DOES NOT RETURN CORRECT VALUE !!! */
else 
 return "This is not the correct return value.";
}
#ifndef PA03_H
#define PA03_H

#include <stdlib.h>

char *strcat_ex(char * *dest, int *n, const char *src);
/*      This function will Append the C-String 'src' to the end of the C-string '	*dest'. The parameter n is the address of an int that specifies how many	character can safely be stored in '*dest'.
 *      If *dest is NULL or not large enough to contain the result, then the fun	ction will do the following: 
 *      - Malloc a new buffer of size 1 + 2 * (strlen(*dest) + strlen(src))
 *      - Set *n to the size of the new buffer
 *      - copy *dest into the beginning of the new buffer
 *      - Free the memory of *dest and then set it to point to the new buffer
 *      - Concatenate src onto the end of *dest
 *
 *      This function always returns pointer *dest
 */
char * *explode(const char *str, const char *delims, int *arrLen);
/*	This function takes a string and splits into an array of strings according to the delimiter. The memory location *arrLen is initialized to the length of the returned array.
 *	str: A string to split.
 *	delims: A string that contains a set of delimiter characters. 
 *	arrLen: pointer to an int that is used to store the resultant length of 	the returned array.
 *
 */
char *implode(char * *strArr, int len, const char *glue)
/*	This function takes an array of strings and concatenates the characters 	into a single string.
 *	strArr: an array of strings
 *	len: the length of the strArr
 *	glue: string to concatenate between each element of 'strArr'
 *
 */

void sortStringArray(char * *arrString, int len);
/* 	This function takes an array of C-strings, and sorts them alphabetically 	ascending. 
 */

void sortStringCharacters(char *str);
/*	This function sorts the characters in a string, alphabeticaly ascending
 *
 */

void destroyStringArray(char * *strArr, int len);
/*	This function safely frees all memory associated with strArr, and the nstrArr itself. 
 *	Passing NULL as the first parameter has no effect.
 */

#endif




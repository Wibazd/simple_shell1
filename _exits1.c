#include "shell.h"
#include<stdlib.h>

/**
 **_strncpy - This copies the strings passed in the programs
 * given.
 *@dest: This is the destination of a file that is going to be
 *passed to the program.
 *@src: This is the source of the program and it holds the file
 * which is going to be copy to another location or destination.
 *@num: This is the number of characters to be copied to specified
 * location.
 *Return: This returns the concatenated strings to the console
 * of the output.
 */
char *_strncpy(char *dest, char *src, int num)
{
	int pp;
	int jj;
	char *scrr = dest;

	pp = 0;

	do {
		dest[pp] = src[pp];
		pp++;
	} while (src[pp] != '\0' && pp < num - 1);
	if (pp < num)
	{
		jj = pp;
		do {
			dest[jj] = '\0';
			jj++;
		} while (jj < num);
	}
	return (scrr);
}

/**
 **_strncat - This is the concatenator of 2 strings togther.
 *@dest: This is the first string to be concate.
 *@src: This is the second string to be concte.
 *@num: This is the amount of bytes to be mounted or to be concatenated.
 *Return: This will always return the concatenated strings.
 */
char *_strncat(char *dest, char *src, int num)
{
	int pp;
	int jj;
	char *scrr = dest;

	pp = 0;
	jj = 0;
	while (dest[pp] != '\0')
		pp++;
	do {
		dest[pp] = src[jj];
		pp++;
		jj++;
	} while (src[jj] != '\0' && jj < num);
	if (jj < num)
		dest[pp] = '\0';
	return (scrr);
}

/**
 **_strchr - This is a  string locator in the program.
 *@str: This shows the string to be passed in  the program.
 *@cha: This is the character to be looked at when searching for them.
 *Return: This will always the pointer to the strings given.
 */
char *_strchr(char *str, char cha)
{
	while (*str++ != '\0')
	{
		if (*str == cha)
			return (str);
	}

	return (NULL);
}

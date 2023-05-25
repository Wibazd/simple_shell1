#include "shell.h"
#include<stdlib.h>

/**
 * _strlen - This is the string len and returns the
 * length.
 * @str: this is the string whose length to check and
 * return to the console.
 * Return: this is an integer length of the strings
 * to be returned.
 */
int _strlen(char *str)
{
	int pp = 0;

	if (!str)
		return (0);

	while (*str++)
		pp++;
	return (pp);
}

/**
 * _strcmp - This will always make lecihophical comaparison
 * between the string given.
 * @num1: This is the first the first strang to be passed.
 * @num2: This is the second strang to be passed.
 * Return: if num1<num1, it print 1 to the console and
 * if num2>num1 it prints yes to the console.
 */
int _strcmp(char *num1, char *num2)
{
	do {
		if (*num1 != *num2)
			return (*num1 - *num2);
		num1++;
		num2++;
	} while (*num1 && *num2);

	if (*num1 == *num2)
		return (0);
	else
		return (*num1 < *num2 ? -1 : 1);
}

/**
 * starts_with - This checks the needle if it start with
 * h stack passed.
 * @hstack: This is the string to be searched in by the
 * function.
 * @point: This is the substring to find by the
 * function.
 * Return: This return an address of next character
 * of the hstack or NULL if nothing is found.
 */
char *starts_with(const char *hstack, const char *point)
{
	while (*point)
		if (*point++ != *hstack++)
			return (NULL);
	return ((char *)hstack);
}

/**
 * _strcat - This will concatenates two strings in the
 * given codes.
 * @dest: This is the destination buffer of the files
 * passed in the program.
 * @src: This is the source buffer where the file is
 * imported or kept.
 * Return: This will always return a pointer to
 * destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *retu = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (retu);
}

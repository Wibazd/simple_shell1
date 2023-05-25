#include "shell.h"
#include<stdlib.h>

/**
 * _strcpy - This will always copy the strings
 * present or passed as parameter
 * @dest: this is the destination where the strings
 * are kept.
 * @src: this is the source of the string where they will
 * be kept.
 * Return: this will return pointers to destination of
 * a file.
 */
char *_strcpy(char *dest, char *src)
{
	int pp = 0;

	if (dest == src || src == 0)
		return (dest);
	do {
		dest[pp] = src[pp];
		pp++;
	} while (src[pp]);
	dest[pp] = 0;
	return (dest);
}

/**
 * _strdup - This duplicates a strings present in the
 * code or passed as  parameter.
 * @stri: This is the string to to duplicated when checking.
 * Return: This will return the duplicated string.
 */
char *_strdup(const char *stri)
{
	int legth = 0;
	char *retun;

	if (stri == NULL)
		return (NULL);
	while (*stri++)
		legth++;
	retun = malloc(sizeof(char) * (legth + 1));
	if (!retun)
		return (NULL);
	for (legth++; legth--;)
		retun[legth] = *--stri;
	return (retun);
}

/**
 *_puts - this will print to the console an input string.
 *@stri: this is the string to be printed to the output.
 * Return: Nothing or NULL.
 */
void _puts(char *stri)
{
	int pp = 0;

	if (!stri)
		return;
	do {
		_putchar(stri[pp]);
		pp++;
	} while (stri[pp] != '\0');
}

/**
 * _putchar - This will write the characters to stdout.
 * @cha: This is the character toto be printed to
 * stdout.
 * Return: On success 1 is returned to the console
 * and -1 is returned when failed.
 */
int _putchar(char cha)
{
	static int pp;
	static char bufff[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || pp >= WRITE_BUF_SIZE)
	{
		write(1, bufff, pp);
		pp = 0;
	}
	if (cha != BUF_FLUSH)
		bufff[pp++] = cha;
	return (1);
}

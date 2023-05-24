#include "shell.h"
#include<stdlib.h>


/**
 *_eputs -This will print an input to the strings passed.
 * @stri: This is the string to be printed in the console
 * of the output.
 * Return: Nothing to be printed to the console or ouput.
 */
void _eputs(char *stri)
{
	int pp = 0;

	if (!stri)
		return;
	do {
		_eputchar(stri[pp]);
		pp++;
	} while (stri[pp] != '\0');
}

/**
 * _eputchar - This will write the character c to the stderr
 * in the program given.
 * @cha: This is the character to be printed in the program.
 * Return: on sucess 0 is returned to the console and failure
 * or error, -1 is returned, to the console.
 */
int _eputchar(char cha)
{
	static int pp;
	static char bufff[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || pp >= WRITE_BUF_SIZE)
	{
		write(2, bufff, pp);
		pp = 0;
	}
	if (cha != BUF_FLUSH)
		bufff[pp++] = cha;
	return (1);
}

/**
 * _putfd - This will char c to the fd passed in the program.
 * @cha: This is the character to be printed.
 * @fil: This describes the file passed in the program and gives
 * its full meaning.
 * Return: On success 1 is returned to the console and when fails
 * -1 is returned to the console.
 */
int _putfd(char cha, int fil)
{
	static int pp;
	static char bufff[WRITE_BUF_SIZE];

	if (cha == BUF_FLUSH || pp >= WRITE_BUF_SIZE)
	{
		write(fil, bufff, pp);
		pp = 0;
	}
	if (cha != BUF_FLUSH)
		bufff[pp++] = cha;
	return (1);
}

/**
 *_putsfd - This is an input passed to print and input
 * strings.
 * @stri: this is the string to be printed in the console of
 * the output.
 * @fil: this is the file descriptor which gives the meaning of
 * the files passed.
 * Return: This will return the number of character output
 * passed in the program.
 */
int _putsfd(char *stri, int fil)
{
	int pp = 0;

	if (!stri)
		return (0);
	do {
		pp += _putfd(*stri++, fil);
	} while (*stri);
	return (pp);
}

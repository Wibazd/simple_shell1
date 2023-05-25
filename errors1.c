#include "shell.h"
#include <stdlib.h>

/**
 * _erratoi - This will convert integers to a string.
 * @stri: This is the string to be converted.
 * Return: 0 is returned when no strings in a number
 * and -1 is returned when there is an error.
 */
int _erratoi(char *stri)
{
	int pp = 0;
	unsigned long int answer = 0;

	if (*stri == '+')
		stri++;
	for (pp = 0;  stri[pp] != '\0'; pp++)
	{
		if (stri[pp] >= '0' && stri[pp] <= '9')
		{
			answer *= 10;
			answer += (stri[pp] - '0');
			if (answer > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (answer);
}

/**
 * print_error - This will print an error message to the
 * console.
 * @info: This is the parameter to returned the info struct
 * in the program passed.
 * @cestr: This contains specfics error to be reported.
 * Return: 0 is always returned if no strings found in the strings
 * and -1 is returned when there is error detected.
 */
void print_error(info_t *info, char *cestr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(cestr);
}

/**
 * print_d - This is a fucntion which prints a integer
 * base 10 to the console.
 * @input: This is the input passed in the program.
 * @fil: This is the file description, which gives the meaning of a file
 * passed in the program.
 * Return: This returns  number of character passed or printed.
 */
int print_d(int input, int fil)
{
	int (*__putchar)(char) = _putchar;
	int pp, counters = 0;
	unsigned int absolt;
	unsigned int showCurrent;

	if (fil == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		absolt = -input;
		__putchar('-');
		counters;
	}
	else
		absolt = input;
	showCurrent = absolt;
	for (pp = 1000000000; pp > 1; pp /= 10)
	{
		if (absolt / pp)
		{
			__putchar('0' + showCurrent / pp);
			counters++;
		}
		showCurrent %= pp;
	}
	__putchar('0' + showCurrent);
	counters++;

	return (counters);
}

/**
 * convert_number - This is a converter function which is cloned from
 * itoa and convert fucntions accordingly.
 * @num2: This is the number to be converted by converter function.
 * @base: This is the base where all the functions will lie.
 * @flags: This is the argms that will be returned from the base.
 * Return: This will return the string characters passed in the program.
 */
char *convert_number(long int num2, int base, int flags)
{
	static char *numArr;
	static char bufff[50];
	char sgnn = 0;
	char *pptt;
	unsigned long num1 = num2;

	if (!(flags & CONVERT_UNSIGNED) && num2 < 0)
	{
		num1 = -num2;
		sgnn = '-';

	}
	numArr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	pptt = &bufff[49];
	*pptt = '\0';

	do {
		*--pptt = numArr[num1 % base];
		num1 /= base;
	} while (num1 != 0);

	if (sgnn)
		*--pptt = sgnn;
	return (pptt);
}

/**
 * remove_comments - A function which replace # with 0, or replace
 * comment # with 0.
 * @buff: This is the address of the string to be  modified.
 * Return: On success 0 is returned or printed to the console.
 */
void remove_comments(char *buff)
{
	int pp;

	for (pp = 0; buff[pp] != '\0'; pp++)
		if (buff[pp] == '#' && (!pp || buff[pp - 1] == ' '))
		{
			buff[pp] = '\0';
			break;
		}
}

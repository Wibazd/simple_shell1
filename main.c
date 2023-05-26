#include "shell.h"

/**
 * main - This is the entry point of codes
 * that are going to be passed to the inputs.
 * @acces: This is an argument counter which checks for the codes
 * passed.
 * @argn: This is an argument  vector present in the codes.
 * Return: On succes 0 is returned to the console and -1
 * is returned to the console if fails to get anything.
 */
int main(int acces, char **argn)
{
	info_t info[] = { INFO_INIT };
	int fil = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fil)
		: "r" (fil));

	if (acces == 2)
	{
		fil = open(argn[1], O_RDONLY);
		if (fil == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(argn[0]);
				_eputs(": 0: Can't open ");
				_eputs(argn[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fil;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, argn);
	return (EXIT_SUCCESS);
}

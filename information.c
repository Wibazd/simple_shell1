#include "shell.h"

/**
 * clear_info - This is an initializer of the info_t struct.
 * @info:This is the informtion to be retrieved to the console
 * and provide a clear path way to output.
 */
void clear_info(info_t *info)
{
	info->arg = NULL;
	info->argv = NULL;
	info->path = NULL;
	info->argc = 0;
}

/**
 * set_info - this is an initializer to an info_t struct which
 * gives definition to the file.
 * @info: this is the struct adress which adresses struct address the
 * informtion to be passed.
 * @argu: this is an argument to the  vector passed in the program.
 */
void set_info(info_t *info, char **argu)
{
	int pp = 0;

	info->fname = argu[0];
	if (info->arg)
	{
		info->argv = strtow(info->arg, " \t");
		if (!info->argv)
		{

			info->argv = malloc(sizeof(char *) * 2);
			if (info->argv)
			{
				info->argv[0] = _strdup(info->arg);
				info->argv[1] = NULL;
			}
		}
		for (pp = 0; info->argv && info->argv[pp]; pp++)
			;
		info->argc = pp;

		replace_alias(info);
		replace_vars(info);
	}
}

/**
 * free_info - This will free info_t struct fields, it free spaces
 * for the inforation.
 * @info: This is a struct address to be addressed.
 * @riek: This will return true if freeing all fields is successfull.
 */
void free_info(info_t *info, int riek)
{
	ffree(info->argv);
	info->argv = NULL;
	info->path = NULL;
	if (riek)
	{
		if (!info->cmd_buf)
			free(info->arg);
		if (info->env)
			free_list(&(info->env));
		if (info->history)
			free_list(&(info->history));
		if (info->alias)
			free_list(&(info->alias));
		ffree(info->environ);
			info->environ = NULL;
		bfree((void **)info->cmd_buf);
		if (info->readfd > 2)
			close(info->readfd);
		_putchar(BUF_FLUSH);
	}
}

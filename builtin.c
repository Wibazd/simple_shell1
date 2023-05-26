#include "shell.h"

/**
 * _myhistory - This displays the history of shell, th command used
 * and number of line inputed.
 * @info: This is a struct containing all the informations
 * about the shell.
 *  Return: On success, 0 is returned to an input.
 */
int _myhistory(info_t *info)
{
	print_list(info->history);/* this will display the history list */
	return (0);
}

/**
 * unset_alias - this set alias to a string given.
 * @info: This is a parameter to pass the number of code in.
 * @str: This returns the string alias of them all.
 * Return: On sucess 0 is returned and 1 is returned if error.
 */
int unset_alias(info_t *info, char *str)
{
	char *pp;
	char cha;
	int results;

	pp = _strchr(str, '=');
	if (!pp)
		return (1);
	cha = *pp;
	*pp = 0;
	results = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pp = cha;
	return (results);
}

/**
 * set_alias - This also set an alias to a strings given.
 * @info: This is a struct parameter.
 * @str: This is the string alias passed to an agrs
 * Return: On success 0 is returned and 1 if error.
 */
int set_alias(info_t *info, char *str)
{
	char *pp;

	pp = _strchr(str, '=');
	if (!pp)
		return (1);
	if (!*++pp)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - This will print an alias to a string.
 * @node: This is anode passed on alias or an alias node.
 * Return: On success 0 is returned and 1 if error.
 */
int print_alias(list_t *node)
{
	char *pp = NULL;
	char *arr = NULL;

	if (node)
	{
		pp = _strchr(node->str, '=');
		for (arr = node->str; arr <= pp; arr++)
			_putchar(*arr);
		_putchar('\'');
		_puts(pp + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - this is a mimics to all the alias in a strings.
 * @info: This is a structure containing all the alias of the information.
 *  Return: This will return 0 on sucsess.
 */
int _myalias(info_t *info)
{
	int p = 0;
	char *pp = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		do {
			print_alias(node);
			node = node->next;
		} while (node);
		return (0);
	}
	for (p = 1; info->argv[p]; p++)
	{
		pp = _strchr(info->argv[p], '=');
		if (pp)
			set_alias(info, info->argv[p]);
		else
			print_alias(node_starts_with(info->alias, info->argv[p], '='));
	}

	return (0);
}

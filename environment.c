#include "shell.h"
#include<stdlib.h>

/**
 * _myenv - This prints to the console the current environment.
 * @info: This is a structure containing the potential argums.
 * Return: This returns 0 on sucess always.
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);/*this will give you the list*/
	return (0);
}

/**
 * _getenv - This will get the value passed to the environment.
 * @info: This is a structure containing arguments.
 * @name: This is an environment variables.
 * Return: This will return the value passed.
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *pp;

	do {
		pp = starts_with(node->str, name);
		if (pp && *pp)
			return (pp);
		node = node->next;
	} while (node);
	return (NULL);
}

/**
 * _mysetenv - This is an initializer to the new environment given.
 * @info: This s a structure which contains potential argumments
 *  Return: On success 0 is returned to the console.
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - This will remove the env or unset evn.
 * @info: Containing ptotenial agrments.
 *  Return: On success 0 is returned.
 */
int _myunsetenv(info_t *info)
{
	int pp;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (pp = 1; pp <= info->argc; pp++)
		_unsetenv(info, info->argv[pp]);
	return (0);
}

/**
 * populate_env_list - Gether the env lists.
 * @info: containing potential agruments.
 * Return: O sucsess 0 is returned
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t pp;

	for (pp = 0; environ[pp]; pp++)
		add_node_end(&node, environ[pp], 0);
	info->env = node;
	return (0);
}

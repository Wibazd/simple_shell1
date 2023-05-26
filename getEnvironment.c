#include "shell.h"

/**
 * get_environ - This always returns the copy and arrays in the env variables.
 * @info: This is the structure containing the vital information
 * about the program passed.
 * Return: On success, 0 is returned to the console.
 */
char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * _unsetenv - This removes the environment variables within the
 * given environment.
 * @info: This is a structure containing the potential arguments
 * in the program.
 *  Return: On delet 1 is returned and 0 if failed.
 * @varble: This returns the strings environment variables in the program.
 */
int _unsetenv(info_t *info, char *varble)
{
	list_t *node = info->env;
	size_t pp = 0;
	char *pre;

	if (!node || !varble)
		return (0);

	do {
		pre = starts_with(node->str, varble);
		if (pre && *pre == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), pp);
			pp = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		pp++;
	} while (node);
	return (info->env_changed);
}

/**
 * _setenv - This inits new env variables in the program.
 * @info: Contains the potential arguments to the program.
 * @var: This is a string variables to passed.
 * @value: This is a value to be checked in the program.
 *  Return: on success 0 is returned.
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *bufff = NULL;
	list_t *node;
	char *pre;

	if (!var || !value)
		return (0);

	bufff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!bufff)
		return (1);
	_strcpy(bufff, var);
	_strcat(bufff, "=");
	_strcat(bufff, value);
	node = info->env;
	do {
		pre = starts_with(node->str, var);
		if (pre && *pre == '=')
		{
			free(node->str);
			node->str = bufff;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	} while (node);
	add_node_end(&(info->env), bufff, 0);
	free(bufff);
	info->env_changed = 1;
	return (0);
}

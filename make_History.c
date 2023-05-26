#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: This is a parameter struct containing all the
 * vital informations about the shell and its usage.
 * Return: This will always returned to the console
 * allocated string containg history file in the system.
 */

char *get_history_file(info_t *info)
{
	char *buff;
	char *dirct;

	dirct = _getenv(info, "HOME=");
	if (!dirct)
		return (NULL);
	buff = malloc(sizeof(char) * (_strlen(dirct) + _strlen(HIST_FILE) + 2));
	if (!buff)
		return (NULL);
	buff[0] = 0;
	_strcpy(buff, dirct);
	_strcat(buff, "/");
	_strcat(buff, HIST_FILE);
	return (buff);
}

/**
 * write_history - This will create a file, or appends to an
 * and should be returned to the console an existing file.
 * @info: This is the parameter struct containing all the
 * vital informations about the shell.
 * Return: 1 is returned  on success, else -1
 * to be returned to the console.
 */
int write_history(info_t *info)
{
	ssize_t fil;
	char *fileofname = get_history_file(info);
	list_t *new_node = NULL;

	if (!fileofname)
		return (-1);

	fil = open(fileofname, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(fileofname);
	if (fil == -1)
		return (-1);
	for (new_node = info->history; new_node; new_node = new_node->next)
	{
		_putsfd(new_node->str, fil);
		_putfd('\n', fil);
	}
	_putfd(BUF_FLUSH, fil);
	close(fil);
	return (1);
}

/**
 * read_history - reads history from file
 * @info: This is the parameter struct containing all the
 * information.
 * Return: This will returned histcount on success
 * and 0 when fails.
 */
int read_history(info_t *info)
{
	int pp, lastt = 0;
	int countLine = 0;
	ssize_t fil, readlen;
	ssize_t ttsize = 0;
	struct stat st;
	char *buff = NULL;
	char *fileofname = get_history_file(info);

	if (!fileofname)
		return (0);
	fil = open(fileofname, O_RDONLY);
	free(fileofname);
	if (fil == -1)
		return (0);
	if (!fstat(fil, &st))
		ttsize = st.st_size;
	if (ttsize < 2)
		return (0);
	buff = malloc(sizeof(char) * (ttsize + 1));
	if (!buff)
		return (0);
	readlen = read(fil, buff, ttsize);
	buff[ttsize] = 0;
	if (readlen <= 0)
		return (free(buff), 0);
	close(fil);
	for (pp = 0; pp < ttsize; pp++)
		if (buff[pp] == '\n')
		{	buff[pp] = 0;
			build_history_list(info, buff + lastt, countLine++);
			lastt = pp + 1;
		}
	if (lastt != pp)
		build_history_list(info, buff + lastt, countLine++);
	free(buff);
	info->histcount = countLine;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}
/**
 * build_history_list - This an add entry to a history linked list
 * to be returned to the console.
 * @info: This is the structure containing potential arguments.
 * Used to maintain and  returned to console.
 * @buff: This is the buffer to be returned.
 * @linecount: This conuts the history linecount, histcount
 * present at the codes and above.
 * Return: Always 0 if succeced and -1 when not.
 */
int build_history_list(info_t *info, char *buff, int linecount)
{
	list_t *new_node = NULL;

	if (info->history)
		new_node = info->history;
	add_node_end(&new_node, buff, linecount);

	if (!info->history)
		info->history = new_node;
	return (0);
}

/**
 * renumber_history - This will renumber the history linked list
 * after all  changes ahve been implemented.
 * @info: This is a struct containing potential arguments.
 * Used to maintain the codes functioning well.
 * Return: This will always return the new histcount
 * in the codes.
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int pp = 0;

	do {
		node->num = pp++;
		node = node->next;
	}  while (node);
	return (info->histcount = pp);
}

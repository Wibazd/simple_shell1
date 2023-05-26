#include "shell.h"

/**
 * input_buf - This is a buffers chained commands which
 * returns chained command of a buffer.
 * @info: This is a struct parameter struct which contains
 * informtion.
 * @buff: This is an address of buffer with the given program.
 * @len: This is an address of len var which contains the len function.
 * Return: This will always return number of bytes read in a
 * program passsed.
 */
ssize_t input_buf(info_t *info, char **buff, size_t *len)
{
	ssize_t retu = 0;
	size_t Len_k = 0;

	if (!*len)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);
		retu = getline(buff, &Len_k, stdin);
		retu = _getline(info, buff, &Len_k);
		if (retu > 0)
		{
			if ((*buff)[retu - 1] == '\n')
			{
				(*buff)[retu - 1] = '\0';
				retu--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			{
				*len = retu;
				info->cmd_buf = buff;
			}
		}
	}
	return (retu);
}

/**
 * get_input - This will gets a line minus the newline and
 * returns that particular line.
 * @info: This is a parameter struct of the information to
 * passe.
 * Return: This will always return number of bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *bufff;
	static size_t pp;
	static size_t lo, len_y;
	ssize_t retu = 0;
	char **buff_pt = &(info->arg);
	char *pre;

	_putchar(BUF_FLUSH);
	retu = input_buf(info, &bufff, &len_y);
	if (retu == -1)
		return (-1);
	if (len_y)
	{
		lo = pp;
		pre = bufff + pp;

		check_chain(info, bufff, &lo, pp, len_y);
		do {
			if (is_chain(info, bufff, &lo))
				break;
			lo++;
		} while (lo < len_y);

		pp = lo + 1;
		if (pp >= len_y)
		{
			pp = len_y = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_pt = pre;
		return (_strlen(pre));
	}

	*buff_pt = bufff;
	return (retu);
}

/**
 * read_buf - This will read a buffer to the console.
 * @info: This is a parameter struct to be read.
 * @buff: This is a buffer passed in the program.
 * @sz: This is the size of the argument.
 * Return: This is return the spaecified number passed.
 */
ssize_t read_buf(info_t *info, char *buff, size_t *sz)
{
	ssize_t retu = 0;

	if (*sz)
		return (0);
	retu = read(info->readfd, buff, READ_BUF_SIZE);
	if (retu >= 0)
		*sz = retu;
	return (retu);
}

/**
 * _getline -This will  get the next line of input from STDIN in
 * the program or arguments passed.
 * @info: This is a parameter struct to the argument.
 * @ptr: This is an address of pointer to buffer, preallocated or
 * when present or not present NULL.
 * @lengthy: This is the size of preallocated pointer to a buffer
 * if not NULL or contains some information.
 * Return: This will return a specific number passed.
 */
int _getline(info_t *info, char **ptr, size_t *lengthy)
{
	static char bufff[READ_BUF_SIZE];
	static size_t pp, len_y;
	size_t kik;
	ssize_t retu = 0;
	ssize_t siz = 0;
	char *pre = NULL;
	char *nwpp = NULL, *cha;

	pre = *ptr;
	if (pre && lengthy)
		siz = *lengthy;
	if (pp == len_y)
		pp = len_y = 0;

	retu = read_buf(info, bufff, &len_y);
	if (retu == -1 || (retu == 0 && len_y == 0))
		return (-1);

	cha = _strchr(bufff + pp, '\n');
	kik = cha ? 1 + (unsigned int)(cha - bufff) : len_y;
	nwpp = _realloc(pre, siz, siz ? siz + kik : kik + 1);
	if (!nwpp)
		return (pre ? free(pre), -1 : -1);

	if (siz)
		_strncat(nwpp, bufff + pp, kik - pp);
	else
	{
		_strncpy(nwpp, bufff + pp, kik - pp + 1);

		siz += kik - pp;
		pp = kik;
		pre = nwpp;
	}
	if (lengthy)
		*lengthy = siz;
	*ptr = pre;
	return (siz);
}

/**
 * sigintHandler -This is a blocks to a ctrl-C
 * which is used during the shell process.
 * @sig_num: This is the signal number numner to be returned
 * to the console.
 * Return: This will return Null or void
 * to the console.
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:34:29 by ngragas           #+#    #+#             */
/*   Updated: 2020/12/02 20:35:15 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	gnl_fail(int fd, char **line, t_buf *buf)
{
	free(buf[fd].s);
	buf[fd].s = NULL;
	buf[fd].cur = NULL;
	*line = NULL;
	return (-1);
}

static int	gnl_buf_realloc(int fd, t_buf *buf)
{
	char	*newbuf;

	if (buf[fd].max + BUFFER_SIZE > buf[fd].cap)
	{
		buf[fd].cap *= 4;
		if (!(newbuf = malloc(buf[fd].cap)))
			return (-1);
		ft_memcpy(newbuf, buf[fd].cur, buf[fd].max);
		free(buf[fd].s);
		buf[fd].s = newbuf;
	}
	else
		ft_memcpy(buf[fd].s, buf[fd].cur, buf[fd].max);
	buf[fd].cur = buf[fd].s;
	return (1);
}

static int	gnl_fetch_fd(int fd, char **line, t_buf *buf, char *newline)
{
	ssize_t	bytes_read;

	while (1)
	{
		if (buf[fd].cur + buf[fd].max + BUFFER_SIZE - buf[fd].s > buf[fd].cap)
			if (gnl_buf_realloc(fd, buf) == -1)
				return (gnl_fail(fd, line, buf));
		if ((bytes_read = read(fd, buf[fd].cur + buf[fd].max, BUFFER_SIZE)) < 1)
		{
			*line = bytes_read ? NULL : ft_substr(buf[fd].cur, 0, buf[fd].max);
			free(buf[fd].s);
			buf[fd].s = NULL;
			buf[fd].cur = NULL;
			return (bytes_read);
		}
		if ((newline = ft_memchr(buf[fd].cur + buf[fd].max, '\n', bytes_read)))
		{
			*line = ft_substr(buf[fd].cur, 0, newline - buf[fd].cur);
			buf[fd].max += buf[fd].cur + bytes_read - newline - 1;
			buf[fd].cur = newline + 1;
			return (1);
		}
		buf[fd].max += bytes_read;
	}
}

int			get_next_line(int fd, char **line)
{
	static t_buf	buf[MAX_FDS];
	char			*newline;

	if (fd < 0)
	{
		*line = NULL;
		return (-1);
	}
	if (buf[fd].s && (newline = ft_memchr(buf[fd].cur, '\n', buf[fd].max)))
	{
		*line = ft_substr(buf[fd].cur, 0, newline - buf[fd].cur);
		buf[fd].max -= newline - buf[fd].cur + 1;
		buf[fd].cur = newline + 1;
		return (1);
	}
	if (!buf[fd].s)
	{
		buf[fd].cap = BIG_BUF > BUFFER_SIZE ? BIG_BUF : BUFFER_SIZE;
		buf[fd].s = malloc(buf[fd].cap);
		if (!buf[fd].s)
			return (gnl_fail(fd, line, buf));
		buf[fd].cur = buf[fd].s;
		buf[fd].max = 0;
	}
	return (gnl_fetch_fd(fd, line, buf, newline));
}

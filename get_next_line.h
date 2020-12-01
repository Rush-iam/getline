/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 16:55:41 by ngragas           #+#    #+#             */
/*   Updated: 2020/12/01 21:43:30 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FDS 260
# define BIG_BUF 524288

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct	s_buf
{
	char		*s;
	char		*cur;
	unsigned	max;
}				t_buf;

int				get_next_line(int fd, char **line);
int				fetch_fd(int fd, char **line, t_buf *buf, char *newline);
int				gnl_fail(char **line, t_buf *buf);

void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif

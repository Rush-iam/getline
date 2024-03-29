/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 20:34:37 by ngragas           #+#    #+#             */
/*   Updated: 2020/12/02 20:34:37 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

/*
**  MAX_FDS - max limit of open fd-s (Mac OS default soft limit is 256)
**  BIG_BUF - big buffer to hold many read BUFFER_SIZEs
**  BUFFER_SIZE - how many bytes to read from input in one call
*/

# define MAX_FDS 260
# define BIG_BUF 524288
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 65536
# endif

typedef struct	s_buf
{
	char		*s;
	char		*cur;
	unsigned	max;
	unsigned	cap;
}				t_buf;

int				get_next_line(int fd, char **line);

void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);

#endif

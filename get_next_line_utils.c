/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:21:45 by ngragas           #+#    #+#             */
/*   Updated: 2020/12/01 17:49:49 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n && *(char *)s != (char)c)
	{
		s++;
		n--;
	}
	return (n ? (void *)s : NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cur;

	if (!dst && !src)
		return (NULL);
	cur = dst;
	while (n--)
		*cur++ = *(char *)src++;
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	char		*cur;

	if (!*s || !len)
	{
		if (!(substr = malloc(1)))
			return (NULL);
		*substr = '\0';
		return (substr);
	}
	if (!(substr = malloc(++len)))
		return (NULL);
	cur = substr;
	s += start;
	while (--len)
		*cur++ = *s++;
	*cur = '\0';
	return (substr);
}

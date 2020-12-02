/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngragas <ngragas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:21:45 by ngragas           #+#    #+#             */
/*   Updated: 2020/12/02 14:20:24 by ngragas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	char	*cur;

	if (!(substr = malloc(++len)))
		return (NULL);
	cur = substr;
	s += start;
	while (--len)
		*cur++ = *s++;
	*cur = '\0';
	return (substr);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 7)
	{
		if (*(char *)s == (char)c)
			return ((void *)s);
		if (*(char *)(s + 1) == (char)c)
			return ((void *)(s + 1));
		if (*(char *)(s + 2) == (char)c)
			return ((void *)(s + 2));
		if (*(char *)(s + 3) == (char)c)
			return ((void *)(s + 3));
		if (*(char *)(s + 4) == (char)c)
			return ((void *)(s + 4));
		if (*(char *)(s + 5) == (char)c)
			return ((void *)(s + 5));
		if (*(char *)(s + 6) == (char)c)
			return ((void *)(s + 6));
		if (*(char *)(s + 7) == (char)c)
			return ((void *)(s + 7));
		s += 8;
		n -= 8;
	}
	while (n && *(char *)s != (unsigned char)c)
		s++ && n--;
	return (n ? (void *)s : NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*cur;

	cur = dst;
	while (n--)
		*cur++ = *(char *)src++;
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 10:40:36 by kawish        #+#    #+#                 */
/*   Updated: 2020/12/24 12:54:06 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char			*d;
	const char		*s;
	size_t			i;
	char			*d_last;
	const char		*s_last;

	d = dst;
	s = src;
	if (!dst && !src)
		return (0);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		i = 0;
		d_last = d + (len - 1);
		s_last = s + (len - 1);
		while (i < len)
		{
			*(d_last - i) = *(s_last - i);
			i++;
		}
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (*s++)
	{
		len++;
	}
	return (len);
}

char	*c_ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*res;
	size_t	i;

	s1_len = ft_strlen(s1) + 1;
	res = malloc(s1_len * sizeof(*res));
	if (!res)
		return (NULL);
	i = 0;
	if (!res && !s1)
		return (0);
	while (i < s1_len)
	{
		((char *)res)[i] = ((const char *)s1)[i];
		i++;
	}
	return (res);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned long	srclen;
	size_t			i;

	if (!src || !dst)
		return (0);
	srclen = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (srclen);
	if (srclen == 0)
	{
		dst[0] = '\0';
		return (srclen);
	}
	while ((src[i] != '\0') && (i < (dstsize - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	size_t	dst_len;
	size_t	dst_len_o;

	i = 0;
	dst_len = ft_strlen(dst);
	dst_len_o = ft_strlen(dst);
	if (dstsize > dst_len)
	{
		while (dst_len < dstsize - 1 && src[i])
		{
			dst[dst_len] = src[i];
			dst_len++;
			i++;
		}
		dst[dst_len] = '\0';
		return (dst_len_o + ft_strlen(src));
	}
	return (dstsize + ft_strlen(src));
}

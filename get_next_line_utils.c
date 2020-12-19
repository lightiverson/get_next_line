#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*a;

	if ((count == 0) || (size == 0))
	{
		count = 1;
		size = 1;
	}
	a = malloc(count * size);
	if (a)
		ft_bzero(a, count * size);
	return (a);
}

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
		{
			return (0);
		}
		i++;
	}
	return (((char *)&(s[i])));
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		((char *)dst)[i] = ((const char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	size_t	s1_len;
	char	*res;

	s1_len = ft_strlen(s1) + 1;
	res = malloc(s1_len * sizeof(*res));
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, s1_len);
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

char	*c_ft_strjoin(char const *s1, char const *s2)
{
	size_t	clen;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
	{
		free((char *)s1);
		return (ft_strdup(s2));
	}
	else if (!s2)
	{
		free((char *)s1);
		return (ft_strdup(s1));
	}
	clen = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(clen + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, clen + 1);
	ft_strlcat(ret, s2, clen + 1);
	free((char *)s1);
	return (ret);
}

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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*new_ptr;

	i = 0;
	new_ptr = b;
	while (i < len)
	{
		new_ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
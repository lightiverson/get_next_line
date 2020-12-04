#include "get_next_line.h"

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

static	int		ft_words_count(char const *s, char c)
{
	int i;
	int len;
	int k;

	i = 0;
	len = 0;
	k = 0;
	while (s[i])
	{
		while ((s[i] != c) && (s[i] != '\0'))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			k++;
			len = 0;
		}
		else
			i++;
	}
	return (k);
}

static	char	**ft_free_td_array(char **td_array, int index)
{
	int i;

	i = 0;
	while (i < index)
	{
		free(td_array[i]);
		i++;
	}
	free(td_array);
	return (NULL);
}

static	char	**ft_create_td_array(char const *s, char c)
{
	char	**td_array;
	int		words_count;

	words_count = ft_words_count(s, c);
	td_array = ft_calloc((words_count + 1), sizeof(*td_array));
	if (!td_array)
		return (ft_free_td_array(td_array, 0));
	return (td_array);
}

static	char	**ft_fill_td_array(char const *s, char c, char **td_array)
{
	int		i;
	int		len;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		len = 0;
		while ((s[i] != c) && (s[i] != '\0'))
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			td_array[j] = ft_substr(s, i - len, len);
			if (td_array[j] == NULL)
				return (ft_free_td_array(td_array, j));
			j++;
		}
		else
			i++;
	}
	return (td_array);
}

char			**ft_split(char const *s, char c)
{
	char	**td_array;

	if (!s)
		return (NULL);
	td_array = ft_create_td_array(s, c);
	if (!td_array)
		return (NULL);
	td_array = ft_fill_td_array(s, c, td_array);
	if (!td_array)
		return (NULL);
	return (td_array);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	end;
	int				i;

	if (!s)
		return (NULL);
	end = start + len;
	res = malloc(len + 1);
	i = 0;
	if (res == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		ft_bzero(res, 1);
		return (res);
	}
	while (start < end)
	{
		res[i] = s[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t s_len;

	if (!s)
		return ;
	s_len = ft_strlen(s);
	write(fd, s, s_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	clen;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	clen = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(clen + 1);
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s1, clen + 1);
	ft_strlcat(ret, s2, clen + 1);
	return (ret);
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 16:20:18 by kawish        #+#    #+#                 */
/*   Updated: 2020/12/25 10:04:50 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	void	*ft_memset(void *b, int c, size_t len)
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

static	char	*ft_strchr(const char *s, int c)
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

static	char	*c_ft_strjoin(char const *s1, char const *s2)
{
	size_t	clen;
	char	*ret;

	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
	{
		free((char *)s1);
		return (c_ft_strdup(s2));
	}
	else if (!s2)
	{
		free((char *)s1);
		return (c_ft_strdup(s1));
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

static	int		helper(int fd, char *buff, char **line)
{
	int		n;
	char	*ptr_a;

	n = 1;
	while (n)
	{
		if (*buff == '\0')
		{
			n = read(fd, buff, BUFFER_SIZE);
			if (n < 0)
				return (-1);
			buff[n] = '\0';
		}
		if ((ptr_a = ft_strchr(buff, '\n')))
		{
			*ptr_a = '\0';
			*line = c_ft_strjoin(*line, buff);
			ptr_a++;
			ft_memmove(buff, ptr_a, (ft_strlen(ptr_a) + 1));
			return (1);
		}
		*line = c_ft_strjoin(*line, buff);
		ft_memset(buff, '\0', ft_strlen(buff) + 1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE + 1];

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	*line = malloc(1 * sizeof(*(*line)));
	if (*line == NULL)
		return (-1);
	ft_memset(*line, '\0', 1 * sizeof(*(*line)));
	return (helper(fd, buff, line));
}

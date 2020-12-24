/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 16:20:18 by kawish        #+#    #+#                 */
/*   Updated: 2020/12/24 12:38:15 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	helper(int fd, char *buff, char **line)
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

int	get_next_line(int fd, char **line)
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

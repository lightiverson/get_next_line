/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 16:20:18 by kawish        #+#    #+#                 */
/*   Updated: 2020/12/19 16:46:10 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** je moet checken of buff leeg is
** als buff leeg is moet je readen
** nadat je geread hebt is buff niet meer leeg
** maar het kan ook dat er een volgende iteratie is waar buff nog niet leeg is
** dan hoef je niet te readen
** maar wel nog steeds voor newline checken
** dus of je nou read of niet, je moet sowieso voor newline checken.
*/

int	get_next_line(int fd, char **line)
{
	int			n;
	static char	buff[BUFFER_SIZE + 1];
	static char	*ptr_a;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	n = 1;
	*line = ft_calloc(1, sizeof(*(*line)));
	while (n)
	{
		if (*buff == '\0')
		{
			n = read(fd, buff, BUFFER_SIZE);
			buff[n] = '\0';
			if (n < 0)
				return (-1);
		}
		if ((ptr_a = ft_strchr(buff, '\n')))
		{
			*ptr_a = '\0';
			*line = c_ft_strjoin(*line, buff);
			ptr_a++;
			ft_memmove(buff, ptr_a, (ft_strlen(ptr_a) + 1));
			return (1);
		}
		else
			*line = c_ft_strjoin(*line, buff);
		ft_bzero(buff, sizeof(buff));
	}
	return (0);
}

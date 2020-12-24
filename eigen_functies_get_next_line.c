#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			n;
	static char	buff[BUFFER_SIZE + 1];
	static char	*ptr_a;

	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	n = 1;
	*line = malloc(1 * sizeof(*(*line)));
	if (*line == NULL)
		return (-1);
	ft_memset(*line, '\0', 1 * sizeof(*(*line)));
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
		else
			*line = c_ft_strjoin(*line, buff);
		ft_memset(buff, '\0', sizeof(buff));
	}
	return (0);
}

// int	get_next_line(int fd, char **line)
// {
// 	int			n;
// 	static char	buff[BUFFER_SIZE + 1];

// 	if (BUFFER_SIZE <= 0 || fd < 0 || line == NULL)
// 		return (-1);
// 	n = 1;
// 	*line = malloc(1 * sizeof(*(*line)));
// 	if (*line == NULL)
// 		return (-1);
// 	ft_memset(*line, '\0', 1 * sizeof(*(*line)));
// 	while (n)
// 	{
// 		if (*buff == '\0')
// 		{
// 			n = read(fd, buff, BUFFER_SIZE);
// 			if (n < 0)
// 				return (-1);
// 			buff[n] = '\0';
// 		}
// 		if (ft_strchr(buff, '\n'))
// 		{
// 			*(ft_strchr(buff, '\n')) = '\0';
// 			*line = c_ft_strjoin(*line, buff);
// 			ft_memmove(buff, (ft_strchr(buff, '\0') + 1), (ft_strlen((ft_strchr(buff, '\0') + 1)) + 1));
// 			return (1);
// 		}
// 		*line = c_ft_strjoin(*line, buff);
// 		ft_memset(buff, '\0', sizeof(buff));
// 	}
// 	return (0);
// }
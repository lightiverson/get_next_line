#include "get_next_line.h"

#define BUFFER_SIZE 3

int get_next_line(int fd, char **line)
{
	int		n;
	char	buf[BUFFER_SIZE];
	char	**tda;

	static 	char *temp;
	int 	index_newline;
	char 	*alles_voor_newline;

	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// ft_putstr_fd("iteratie", 1);
		// write(1, "\n", 1);
		if (temp != NULL)
		{
			// ft_putstr_fd("temp = TRUE", 1);
			// write(1, "\n", 1);
			*line = bzero(*line, strlen(*line));
			*line = ft_strjoin(*line, temp);
			temp = NULL;
		}
		
		if (!(strchr(buf, '\n')))
		{
			// ft_putstr_fd("Geen newline gevonden", 1);
			// write(1, "\n", 1);
			*line = ft_strjoin(*line, buf);
			// ft_putstr_fd("*line = ", 1);
			// ft_putstr_fd(*line, 1);
			// write(1, "\n", 1);	
		}
		
		if (strchr(buf, '\n'))
		{
			// ft_putstr_fd("Newline gevonden", 1);
			// write(1, "\n", 1);
			index_newline = (int)(strchr(buf, '\n') - buf);
			// ft_putstr_fd("index_newline = ", 1);
			// char c = index_newline + '0';
			// write(1, &c, 1);
			// write(1, "\n", 1);

			alles_voor_newline = ft_substr(buf, 0, index_newline);
			// ft_putstr_fd("alles_voor_newline = ", 1);
			// ft_putstr_fd(alles_voor_newline, 1);
			// write(1, "\n", 1);

			*line = ft_strjoin(*line, alles_voor_newline);
			// ft_putstr_fd("*line = ", 1);
			// ft_putstr_fd(*line, 1);
			// write(1, "\n", 1);

			temp = ft_substr(buf, (index_newline + 1), strlen(buf));
			// ft_putstr_fd("temp = ", 1);
			// ft_putstr_fd(temp, 1);
			// write(1, "\n", 1);
			
			return (1);
		}
	}
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("tester.txt", O_RDONLY, 0);
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);

		ft_putstr_fd("ret = ", 1);
		char c = ret + '0';
		write(1, &c, 1);
		write(1, "\n", 1);

		ft_putstr_fd("line = ", 1);
		ft_putstr_fd(line, 1);
		write(1, "\n", 1);

		write(1, "\n", 1);
		// free(line); // waarom?
	}
	close(fd);
	return (0);
}

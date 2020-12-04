#include "get_next_line.h"

#define BUFFER_SIZE 3

int get_next_line(int fd, char **line)
{
	int		n;
	char	buf[BUFFER_SIZE];
	char	**tda;
	char	*temp;
	int		flag;

	flag = 0;
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		tda = ft_split(buf, '\n');

		/*
		if(flag) // als in de vorige iteratie een newline is gevonden.
		{
			*line = bzero(*line, strlen(*line));
			*line = ft_strjoin(*line, temp);
			temp = bzero(temp, strlen(temp));
			flag = 0;
		}

		if (tda[1][0] == '\0') // als er geen newline is gevonden.
		{
			*line = ft_strjoin(*line, buf); // zet *line gelijk aan de hele buf.
		}
		else { // als er wel een newline is gevonden.
			*line = ft_strjoin(*line, tda[0]); // zet *line gelijk aan (buf tot newline).
			temp = ft_strjoin(temp, tda[1]); // zet temp gelijk aan (buf van na newline tot eind).
			flag = 1;
		}
		*/

		ft_putstr_fd("tda[0] = ", 1);
		ft_putstr_fd(tda[0], 1);
		write(1, "\n", 1);

		ft_putstr_fd("tda[1] = ", 1);
		ft_putstr_fd(tda[1], 1);
		write(1, "\n", 1);

		write(1, "\n", 1);

		*line = ft_strjoin(*line, buf);
	}
	return(0);
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
		printf("\nret = %d\nline = %s\n", ret, line);
		free(line); // waarom?
	}
	close(fd);
	return (0);
}

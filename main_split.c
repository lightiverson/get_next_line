#include "get_next_line.h"

#define BUFFER_SIZE 140

int get_next_line(int fd, char **line)
{
	int		n;
	char	buf[BUFFER_SIZE];
	char	**tda;
	static 	char *temp;
	static	int flag;
	int index_newline;

	flag = 0;
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		tda = ft_split(buf, '\n');

		ft_putstr_fd("tda[0] = ", 1);
		ft_putstr_fd(tda[0], 1);
		write(1, "\n", 1);
		ft_putstr_fd("tda[1] = ", 1);
		ft_putstr_fd(tda[1], 1);
		write(1, "\n", 1);
		ft_putstr_fd("tda[2] = ", 1);
		ft_putstr_fd(tda[2], 1);
		write(1, "\n", 1);
		write(1, "\n", 1);


		
		
		/*
		if (flag) // als in de vorige iteratie een newline is gevonden.
		{
			// ft_putstr_fd("flag TRUE", 1);
			// write(1, "\n", 1);
			flag = 0;
			*line = bzero(*line, strlen(*line));
			*line = ft_strjoin(*line, temp);
		}
		
		if ((strlen(tda[0]) < (BUFFER_SIZE + 1))) // als er wel een newline is gevonden.
		{
			// ft_putstr_fd("Newline gevonden!", 1);
			// write(1, "\n", 1);
			*line = ft_strjoin(*line, tda[0]); // zet *line gelijk aan (buf tot newline).
			temp = ft_strjoin(temp, tda[1]); // zet temp gelijk aan (buf van na newline tot eind).
			// ft_putstr_fd("temp = ", 1);
			// ft_putstr_fd(temp, 1);
			write(1, "\n", 1);
			// temp = ft_substr(tda[1], 0, strlen(tda[1])); // zet temp gelijk aan (buf van na newline tot eind).
			flag = 1;
		}
		else // als er geen newline is gevonden.
		{
			// ft_putstr_fd("geen newline gevonden", 1);
			// write(1, "\n", 1);
			*line = ft_strjoin(*line, tda[0]); // zet *line gelijk aan de hele buf.
		}
		*/
	
		/*
		if(flag) // als in de vorige iteratie een newline is gevonden.
		{
			// ft_putstr_fd("flag TRUE", 1);
			// write(1, "\n", 1);
			*line = bzero(*line, strlen(*line));
			*line = ft_strjoin(*line, temp);
			temp = bzero(temp, strlen(temp));
			flag = 0;
		}
		if (strlen(tda[0]) != BUFFER_SIZE) // als er geen newline is gevonden.
		{
			ft_putstr_fd("geen newline gevonden", 1);
			write(1, "\n", 1);
			*line = ft_strjoin(*line, buf); // zet *line gelijk aan de hele buf.
		}
		else { // als er wel een newline is gevonden.
			// ft_putstr_fd("newline gevonden", 1);
			// ft_putstr_fd(tda[0], 1);
			*line = ft_strjoin(*line, tda[0]); // zet *line gelijk aan (buf tot newline).
			temp = ft_strjoin(temp, tda[1]); // zet temp gelijk aan (buf van na newline tot eind).
			flag = 1;
		}
		*/

		/*
		ft_putstr_fd("tda[0] = ", 1);
		ft_putstr_fd(tda[0], 1);
		write(1, "\n", 1);

		ft_putstr_fd("tda[1] = ", 1);
		ft_putstr_fd(tda[1], 1);
		write(1, "\n", 1);

		write(1, "\n", 1);

		*line = ft_strjoin(*line, buf);
		*/
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
		// ft_putstr_fd("ret = ", 1);
		// char c = ret + '0';
		// write(1, &c, 1);
		// write(1, "\n", 1);
		// ft_putstr_fd("line = ", 1);
		// ft_putstr_fd(line, 1);
		// write(1, "\n", 1);
		// write(1, "\n", 1);
		// free(line); // waarom?
	}
	close(fd);
	return (0);
}

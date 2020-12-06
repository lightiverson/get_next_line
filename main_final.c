#include "get_next_line.h"

#define BUFFER_SIZE 27

// Denk aan dat er mogelijk edge cases gehandeld moeten worden
// Als buf[0] een newline is, of buf[n - 1] een newline is
// Want dan ?

int get_next_line(int fd, char **line)
{
	int				n;
	char			buf[BUFFER_SIZE];

	char			*ptr_nl;
	size_t			i_nl;
	char			*buf_voor_nl;

	char			*temp_ptr_nl;
	size_t			temp_i_nl;
	char			*temp_voor_nl;

	static 	char	*temp;

	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// Als temp niet leeg is
		if (temp != NULL)
		{
			// ft_putstr_fd("temp = TRUE", 1);
			// write(1, "\n", 1);

			// Als temp geen newline bevat
			// ft_putstr_fd("temp = ", 1);
			// ft_putstr_fd(temp, 1);
			// write(1, "\n", 1);
			if (!(strchr(temp, '\n')))
			{
				// ft_putstr_fd("temp bevat geen newline", 1);
				// write(1, "\n", 1);

				// Maak line leeg
				*line = bzero(*line, strlen(*line));

				// Zet line gelijk aan temp
				*line = ft_strjoin(*line, temp);

				// Zet temp op NULL
				temp = NULL;
			}
			// Als temp wel een newline bevat
			else
			{
				// Maak line leeg
				*line = bzero(*line, strlen(*line));

				// Zet line gelijk aan line + (temp < newline). Waarom bestaande line includen?
				temp_ptr_nl = strchr(temp, '\n');
				temp_i_nl = (size_t)(temp_ptr_nl - temp);

				temp_voor_nl = ft_substr(temp, 0, temp_i_nl);

				*line = ft_strjoin(*line, temp_voor_nl);

				// Zet temp gelijk aan (temp > newline)
				temp = ft_substr(temp, (temp_i_nl + 1), strlen(temp));

				return(1);
			}
		}
		
		// Als buf wel een newline bevat
		if (strchr(buf, '\n'))
		{
			// Zet line gelijk aan line + (buf < newline)
			ptr_nl = strchr(buf, '\n');
			i_nl = (size_t)(ptr_nl - buf);
			// printf("\ni_nl = %zu\n", i_nl);

			buf_voor_nl = ft_substr(buf, 0, i_nl);
			// ft_putstr_fd("buf_voor_nl = ", 1);
			// ft_putstr_fd(buf_voor_nl, 1);
			// write(1, "\n", 1);

			*line = ft_strjoin(*line, buf_voor_nl);

			// Zet temp gelijk aan (buf > newline)
			// ft_substr(source string, start index of substring, lengt of substring)
			temp = ft_substr(buf, (i_nl + 1), strlen(buf));
			// ft_putstr_fd("temp = ", 1);
			// ft_putstr_fd(temp, 1);
			// write(1, "\n", 1);

			return (1);
		}
		
		// Als buf geen newline bevat
		if (!(strchr(buf, '\n')))
		{
			// Zet line gelijk aan line + buf
			*line = ft_strjoin(*line, buf);
			// ft_putstr_fd("*line = ", 1);
			// ft_putstr_fd(*line, 1);
			// write(1, "\n", 1);
		}
		
	}

	// Als temp niet leeg is
	if (temp != NULL)
	{
		// ft_putstr_fd("temp = TRUE", 1);
		// write(1, "\n", 1);

		// Als temp geen newline bevat
		// ft_putstr_fd("temp = ", 1);
		// ft_putstr_fd(temp, 1);
		// write(1, "\n", 1);
		if (!(strchr(temp, '\n')))
		{
			// ft_putstr_fd("temp bevat geen newline", 1);
			// write(1, "\n", 1);

			// Maak line leeg
			*line = bzero(*line, strlen(*line));

			// Zet line gelijk aan temp
			*line = ft_strjoin(*line, temp);

			// Zet temp op NULL
			temp = NULL;
		}
		// Als temp wel een newline bevat
		else
		{
			// Maak line leeg
			*line = bzero(*line, strlen(*line));

			// Zet line gelijk aan line + (temp < newline). Waarom bestaande line includen?
			temp_ptr_nl = strchr(temp, '\n');
			temp_i_nl = (size_t)(temp_ptr_nl - temp);

			temp_voor_nl = ft_substr(temp, 0, temp_i_nl);

			*line = ft_strjoin(*line, temp_voor_nl);

			// Zet temp gelijk aan (temp > newline)
			temp = ft_substr(temp, (temp_i_nl + 1), strlen(temp));

			return(1);
		}
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

#include "get_next_line.h"

// Denk aan dat er mogelijk edge cases gehandeld moeten worden
// Als buf[0] een newline is, of buf[n - 1] een newline is
// Want dan ?

int get_next_line(int fd, char **line)
{
	int				n;
	char			buf[BUFFER_SIZE + 1];

	char			*ptr_nl;
	size_t			i_nl;
	char			*buf_voor_nl;

	char			*temp_ptr_nl;
	size_t			temp_i_nl;
	char			*temp_voor_nl;

	static 	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0 || line == NULL)
	{
		printf("One of fd, BUFFER_SIZE and line is wrong, return -1\n");
		return (-1);
	}
	
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';

		// Als temp niet leeg is
		if (temp != NULL)
		{
			// Als temp geen newline bevat
			if (!(strchr(temp, '\n')))
			{
				// Maak line leeg
				bzero(*line, strlen(*line));

				// Zet line gelijk aan temp
				*line = ft_strjoin(*line, temp);

				// Zet temp op NULL
				temp = NULL;
			}
			// Als temp wel een newline bevat
			else
			{
				// Maak line leeg
				bzero(*line, strlen(*line));

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

			buf_voor_nl = ft_substr(buf, 0, i_nl);

			*line = ft_strjoin(*line, buf_voor_nl);

			// Zet temp gelijk aan (buf > newline)
			// ft_substr(source string, start index of substring, lengt of substring)
			temp = ft_substr(buf, (i_nl + 1), strlen(buf));

			return (1);
		}
		
		// Als buf geen newline bevat
		if (!(strchr(buf, '\n')))
		{
			// Zet line gelijk aan line + buf
			*line = ft_strjoin(*line, buf);
		}
		
	}

	// Als temp niet leeg is
	if (temp != NULL)
	{
		// Als temp geen newline bevat
		if (!(strchr(temp, '\n')))
		{
			// Maak line leeg
			bzero(*line, strlen(*line));

			// Zet line gelijk aan temp
			*line = ft_strjoin(*line, temp);

			// Zet temp op NULL
			temp = NULL;
		}
		// Als temp wel een newline bevat
		else
		{
			// Maak line leeg
			bzero(*line, strlen(*line));

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

		// printf("\nret = %d\n", ret);
		printf("%s\n", line);
		// ft_putstr_fd("line = ", 1);
		// ft_putstr_fd(line, 1);
		// ft_putstr_fd("\n", 1);
		// free(line); // waarom?
	}
	close(fd);
	return (0);
}

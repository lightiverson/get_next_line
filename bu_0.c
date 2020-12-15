#include "get_next_line.h"

int get_next_line(int fd, char **line)
{
	//printf("\n>>> Running get_next_line()\n");
	static int n;
	static char buff[BUFFER_SIZE + 1];
	static char *ptr_a;

	n = 1; // Moet op 1 staan om de while loop te laten lopen.
	*line = calloc(1, sizeof(*(*line))); // Calloc *line zodat later met strjoin, argument s1 gefree'ed kan worden.

	while (n) // Zolang er nog data te lezen is, dus n is meer dan 0.
	{
		//printf(">>> While - n is TRUE\n");
		//printf("n = %d\n", n);
		if (*buff == '\0') // Buff is leeg.
		{
			//printf(">>> If - buff is leeg\n");
			n = read(fd, buff, BUFFER_SIZE);
			//printf("Read()\n");
			buff[n] = '\0';
			//printf("Buff = |%s|\n", buff);
			if (n < 0)
				return (-1);
		}
		// je moet checken of buff leeg is
		// als buff leeg is moet je readen
		// nadat je geread hebt is buff niet meer leeg
		// maar het kan ook dat er een volgende iteratie is waar buff nog niet leeg is
		// dan hoef je niet te readen
		// maar wel nog steeds voor newline checken
		// dus of je nou read of niet, je moet sowieso voor newline checken.
		if ((ptr_a = strchr(buff, '\n')))
		{
			//printf(">>> If - newline in buff.\n");
			*ptr_a = '\0';
			//printf("Buff = |%s|\n", buff);

			*line = c_ft_strjoin(*line, buff);
			//printf("*line = |%s|\n", *line);

			ptr_a++;
			memmove(buff, ptr_a, (strlen(ptr_a) + 1));
			//printf("Buff = |%s|\n", buff);

			//printf("return (1)\n\n");
			return (1);
		}
		else
		{
			//printf(">>> Geen newline in buff.\n");
			*line = c_ft_strjoin(*line, buff);
			//printf("*line = |%s|\n", *line);

		}
		bzero(buff, sizeof(buff));
		//printf("bzero()\n");
	}
	//printf("return (0)\n\n");
	return (0);
}

int	main(void)
{
	char	*line;
	int		fd;
	int		ret;

	fd = open("test", O_RDONLY);
	ret = 1;
	line = NULL;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		//printf("\nret = %d\n", ret);
		printf("line = |%s|\n", line);
		free(line); // waarom?
	}
	close(fd);
	return (0);
}

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int     main(void)
{
	char	*line;
	int		ret;
	int		fd;
	int i = 0;
	fd = open("tester.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	// fd = 0;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%d: line: %s-\n\n", ret, line);
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

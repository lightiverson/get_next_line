#include "get_next_line.h"

#define BUFFER_SIZE 3

/*
** read() returns:
**
** On success, the number of bytes read is returned (zero indicates end
** of file), and the file position is advanced by this number.  It is
** not an error if this number is smaller than the number of bytes
** requested; this may happen for example because fewer bytes are
** actually available right now (maybe because we were close to end-of-
** file, or because we are reading from a pipe, or from a terminal), or
** because read() was interrupted by a signal.  See also NOTES.
*/

int main(void)
{
	int fd;
	char buf[BUFFER_SIZE]; // buf is elke keer BUFFER_SIZE aantal characters van fd.
	int n;
	char *s;

	fd = open("tester.txt", O_RDONLY, 0);

	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		if (strchr(buf, '\n'))
		{
			char *c = strchr(buf, '\n');
			int index = (int)(c - buf);

			char *last_block_before_nl = ft_substr(buf, 0, index + 1);
			s = ft_strjoin(s, last_block_before_nl);
			ft_putstr_fd(s, 1);
			return(0);
		}
		
		// als er een newline is gevonden
		// dan moet je s concaten met buf[tot newline]
		// dus er moet een nieuwe array zijn vanaf buf[0] tot en met buf[index newline]
			// hoe krijg je de index terug van char in string? Door strchr - buf te doen, en int van te maken.
			// hoe krijg je een substring terug van index tot index? ft_substr(buf, 0, index + 1).
			// hoe kan ik dit testen? bij die return in de if statement moet s 1 regel zijn.

		// ft_putstr_fd(buf, 1);
		s = ft_strjoin(s, buf);
	}
	ft_putstr_fd(s, 1);
	return (0);
}

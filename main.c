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
			return (0);
		}
		// write(1, "\nIteratie\n", 11);
		// write(1, buf, n);
		// write(1, "\n\n", 2);
		// strlcat
		// if buf contains newline?
		// alles tot newline moet in string, en alles na newline moet in static var
		
		// s = malloc(strlen(buf) * sizeof(*s));
		s = ft_strdup(buf);
		printf("\ns = %s\n", s);
	}
	return (0);
}

/*
Wat als buf[BUFFER_SIZE] kleiner is dan buf[t/m newline]?
	Vul char* s met characters van buf[BUFFER_SIZE]
	Maar je moet doorgaan tot je newline tegenkomt?

	while(tot je newline tegenkomt)

	

Wat als buf[BUFFER_SIZE] groter is dan buf[t/m newline]?
*/
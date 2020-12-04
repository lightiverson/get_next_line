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
	char *ans;
	char *temp;
	int flag;
	
	fd = open("tester.txt", O_RDONLY, 0);
	flag = 0;
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		// ft_putstr_fd(buf, 1);
		// write(1, "\n", 1);
		if (flag)
		{
			ft_putstr_fd("ft_putstr_fd() = ", 1);
			ft_putstr_fd(ans, 1);
			write(1, "\n", 1);
			// ft_putstr_fd("temp vol", 1);
			// write(1, "\n", 1);
			ans = bzero(ans, strlen(ans));
			ans = ft_strjoin(ans, temp);
			temp = bzero(temp, strlen(temp));
			flag = 0;
		}

		if (strchr(buf, '\n'))
		{
			int index_newline = (int)(strchr(buf, '\n') - buf);
			// printf("\nindex_newline = %d\n", index_newline);

			char *alles_voor_newline = ft_substr(buf, 0, index_newline);
			// ft_putstr_fd(alles_voor_newline, 1); // = 3?
			// write(1, "\n", 1);

			ans = ft_strjoin(ans, alles_voor_newline);

			temp = ft_substr(buf, (index_newline + 1), strlen(buf));
			// ft_putstr_fd(temp, 1); // = di, = Di
			// write(1, "\n", 1);
			flag = 1;
		}
		else
		{
			ans = ft_strjoin(ans, buf);
		}
	}
	ft_putstr_fd("ft_putstr_fd() = ", 1);
	ft_putstr_fd(ans, 1);
	return (0);
}

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

void	*ft_calloc(size_t count, size_t size);
char	*ft_strchr(const char *s, int c);
char	*c_ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);
int		get_next_line(int fd, char **line);

#endif
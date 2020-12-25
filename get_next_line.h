/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kawish <kawish@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/24 13:17:14 by kawish        #+#    #+#                 */
/*   Updated: 2020/12/25 10:12:54 by kawish        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

void			*ft_memmove(void *dst, const void *src, size_t len);
size_t			ft_strlen(const char *s);
char			*c_ft_strdup(const char *s1);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
int				get_next_line(int fd, char **line);

#endif

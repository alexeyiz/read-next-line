/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 13:07:58 by ichariss          #+#    #+#             */
/*   Updated: 2020/12/10 15:36:58 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <string.h>
# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int ch);
char	*ft_strjoin(char const *s1, char const *s2);
char	*clear(size_t i);
int		get_next_line(int fd, char **line);
int		pechatka(char **pech, char **line, int fd);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s);
void	ft_bzero(void *s, size_t n);
#endif

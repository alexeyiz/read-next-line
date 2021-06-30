/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 16:15:00 by ichariss          #+#    #+#             */
/*   Updated: 2020/12/10 15:34:41 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		vivod(int size, char **a, int fd, char **line)
{
	if (size < 0)
		return (-1);
	if (size == 0 && a[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (pechatka(a, line, fd));
}

int		get_next_line(int fd, char **line)
{
	static char	*a[255];
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	int			size;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = '\0';
		if (a[fd] == NULL)
			a[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(a[fd], buff);
			free(a[fd]);
			a[fd] = tmp;
		}
		if (ft_strchr(a[fd], '\n'))
			break ;
	}
	return (vivod(size, a, fd, line));
}

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	if (!(copy = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*new;

	i = 0;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new = (char*)malloc(sizeof(char) *
					ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[++j])
	{
		new[i++] = s2[j];
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strchr(const char *str, int ch)
{
	int		i;
	char	a;

	i = 0;
	a = ch;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			return ((char*)&str[i]);
		i++;
	}
	if ((char)ch == str[i])
		return ((char *)&str[i]);
	return (0);
}

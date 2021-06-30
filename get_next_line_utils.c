/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichariss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:31:45 by ichariss          #+#    #+#             */
/*   Updated: 2020/12/10 15:36:29 by ichariss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		pechatka(char **pech, char **line, int fd)
{
	char	*tmp;
	int		i;

	i = 0;
	while (pech[fd][i] && pech[fd][i] != '\n')
		i++;
	if (pech[fd][i] == '\n')
	{
		*line = ft_substr(pech[fd], 0, i);
		tmp = ft_strdup(pech[fd] + i + 1);
		free(pech[fd]);
		pech[fd] = tmp;
		return (1);
	}
	else
	{
		*line = ft_strdup(pech[fd]);
		free(pech[fd]);
		pech[fd] = NULL;
		return (0);
	}
}

void	ft_bzero(void *s, size_t n)
{
	char *p;

	p = s;
	while (n > 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (len <= start)
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	i = 0;
	if ((new = (char*)malloc(len * sizeof(char) + 1)) == NULL || s == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

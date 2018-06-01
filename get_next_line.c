/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhong <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:14:49 by fhong             #+#    #+#             */
/*   Updated: 2018/05/31 20:19:24 by fhong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>

char	*my_strsearch(char *str, char c)
{
	int 	i;
	char	*tmp;

	i = 0;
	while (str[i])
		if (str[i++] == c)
			break;
	if (i == (int)ft_strlen(str) && str[i - 1] != '\n')
		return (0);
	tmp = ft_strnew(i - 1);
	tmp = ft_strncpy(tmp, str, i - 1);
	return (tmp);
}

int		get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	int			ret;
	char		*tmp;

	if ((fd < 0 || line == NULL))
		return (-1);
	if (!save)
		save = ft_strnew(1);
	*line = ft_strnew(1);
	while (!ft_strchr(save, '\n'))
	{
		buf = ft_strnew(BUFF_SIZE);
		if(!(ret = read(fd, buf, BUFF_SIZE)))
			return (0);
		save = ft_strjoin(save, buf);
		free(buf);
	}
	tmp = *line;
	*line = ft_strdup(my_strsearch(save, '\n'));
	save = ft_strdup((ft_strchr(save, '\n')) + 1);
	free(tmp);
	return (1);
}

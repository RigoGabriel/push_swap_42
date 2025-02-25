/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 14:27:34 by grigo             #+#    #+#             */
/*   Updated: 2021/03/10 17:01:21 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_return(char **str, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr(*str, 0, i);
	if ((*str)[i] == '\n')
		tmp = ft_strdup(&(*str)[i + 1]);
	else
		tmp = NULL;
	free(*str);
	*str = tmp;
	if (!*str)
		return (0);
	return (1);
}

char	*ft_read(int fd, char *buff, char *str)
{
	char	*tmp;
	int		res;

	while ((res = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[res] = '\0';
		if (!str || !*str)
		{
			tmp = ft_strdup(buff);
			free(str);
			str = tmp;
		}
		else
		{
			tmp = ft_strjoin(str, buff);
			free(str);
			str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (str);
}

int		get_next_line(int fd, char **line)
{
	static char		*str;
	char			*buff;

	if (!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	if (fd < 0 || !line || read(fd, buff, 0) < 0 || BUFFER_SIZE < 1)
	{
		free(buff);
		return (-1);
	}
	str = ft_read(fd, buff, str);
	free(buff);
	if (!str)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_return(&str, line));
}

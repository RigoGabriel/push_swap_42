/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grigo <grigo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:08:55 by grigo             #+#    #+#             */
/*   Updated: 2021/03/08 14:10:50 by grigo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pile.h"

int		ft_nb_cmd(char **av, int i, int j, int len)
{
	while (av[i])
	{
		while (av[i][j])
		{
			if (av[i][j] == ' ')
			{
				while (av[i][j + 1] == ' ')
					j++;
				if (av[i][j + 1] != '\0')
					len++;
			}
			j++;
		}
		len++;
		i++;
	}
	return (len);
}

char	**get_cmd(char **av, int i, int j, int j_cmd)
{
	char	**cmd;
	int		index_cmd;
	int		len;

	index_cmd = 0;
	len = ft_nb_cmd(av, 1, 0, 0);
	cmd = malloc(sizeof(char *) * (len + 1));
	while (av[i])
	{
		cmd[index_cmd] = malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		j = 0;
		j_cmd = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
			{
				cmd[index_cmd][j_cmd] = av[i][j];
				j_cmd++;
			}
			else
			{
				while (av[i][j + 1] == ' ')
					j++;
				if (av[i][j + 1] != '\0')
				{
					cmd[index_cmd][j_cmd] = '\0';
					j_cmd = 0;
					index_cmd++;
					cmd[index_cmd] =
						malloc(sizeof(char) * (ft_strlen(&av[i][j]) + 1));
				}
			}
			j++;
		}
		cmd[index_cmd][j_cmd] = '\0';
		index_cmd++;
		i++;
	}
	cmd[index_cmd] = NULL;
	return (cmd);
}

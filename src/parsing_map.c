/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:05:23 by nnemeth           #+#    #+#             */
/*   Updated: 2022/12/21 14:16:13 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_charinstr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_map(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (ft_charinstr(str, '1') == 1)
	{
		while (str[i] != '\0')
		{
			if (str[i] != ' ' && str[i] != '0' && str[i] != '1' \
				&& str[i] != 'N' && str[i] != 'E' \
				&& str[i] != 'W' && str[i] != '\n' && str[i] != '\t')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

int	ft_copy_map(char *str, t_recup *recup)
{
	static int	i = 0;
	int			j;

	j = 0;
	(recup->minimap[i] = malloc(sizeof(char) * recup->sizeline + 1));
	if (!(recup->minimap[i]))
		return (0);
	while (str[j] != '\0')
	{
		if (str[j] == ' ')
			recup->minimap[i][j] = '1';
		else
			recup->minimap[i][j] = str[j];
		j++;
	}
	while (j <= (recup->sizeline - 1))
	{
		recup->minimap[i][j] = '1';
		j++;
	}
	recup->minimap[i][j] = '\0';
	i++;
	return (0);
}

int	ft_set(char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (count);
}

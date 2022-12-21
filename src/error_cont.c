/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cont.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:04:36 by nnemeth           #+#    #+#             */
/*   Updated: 2022/12/21 15:14:22 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_error2(t_recup *recup, char *str)
{
	int	i;

	i = -1;
	recup->indicateur3 = 1;
	if (!(recup->indicateurx))
		write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	ft_errors_more(recup);
	if (recup->erreur == 1)
		exit(1);
	if (recup->minimap)
	{
		while (++i < (recup->nblines))
		{
			free(recup->minimap[i]);
			recup->minimap[i] = NULL;
		}
	}
	if (recup->minimap)
		free(recup->minimap);
	recup->minimap = NULL;
	if (recup->map)
		free(recup->map);
	ft_exit(recup);
}

void	ft_errors_more(t_recup *recup)
{
	if (recup->no)
		free(recup->no);
	if (recup->so)
		free(recup->so);
	if (recup->we)
		free(recup->we);
	if (recup->ea)
		free(recup->ea);
	if (recup->sp)
		free(recup->sp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 14:04:53 by nnemeth           #+#    #+#             */
/*   Updated: 2022/12/21 14:29:12 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	find_player(t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	while (i < recup->nblines)
	{
		j = 0;
		while (recup->minimap[i][j])
		{
			if (recup->minimap[i][j] == 'N' || recup->minimap[i][j] == 'S'
				|| recup->minimap[i][j] == 'E' || recup->minimap[i][j] == 'W')
			{
				if (recup->depart != 0)
					ft_error2(recup, "Error\nOnly one player is allowed\n");
				recup->depart = recup->minimap[i][j];
				recup->dx = i;
				recup->dy = j;
				break ;
			}
			j++;
		}
		i++;
	}
	if (recup->depart == 0)
		ft_error2(recup, "Error\n You must have at least 1 player\n");
}

void	put_area(t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	while (i < recup->nblines)
	{
		j = 0;
		while ((size_t)j < ft_strlen(recup->minimap[i]))
		{
			ft_mini_print(recup, i, j, recup->minimap[i][j]);
			j++;
		}
		i++;
	}
}

int	ft_mini_print(t_recup *recup, int i, int j, int nb)
{
	recup->data.miniheight = j;
	recup->data.miniwidth = i;
	if ((nb == '\t' || nb == '\n' || nb == '\v'
			|| nb == '\f' || nb == '\r' || nb == ' '))
		draw_map(recup, RED);
	else if (nb == '1')
		draw_map(recup, RED);
	else if (nb == '0')
		draw_map(recup, BLUE);
	else if (nb == 'S' || nb == 'N' || nb == 'S' || nb == 'W')
		draw_map(recup, YELL);
	return (0);
}

int	draw_map(t_recup *recup, int color)
{
	int	i;
	int	j;	

	i = recup->data.miniheight * 5;
	while (i < (recup->data.miniheight + 1) * 5)
	{
		j = recup->data.miniwidth * 5;
		while (j < (recup->data.miniwidth + 1) * 5)
		{
			if (color == RED)
			{
				mlx_pixel_put(recup->data.mlx_ptr, recup->data.mlx_win, i,
					j, color);
			}
			else
				mlx_pixel_put(recup->data.mlx_ptr, recup->data.mlx_win, i,
					j, color);
			j++;
		}
		i++;
	}
	return (0);
}

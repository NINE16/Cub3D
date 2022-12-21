/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:41 by nsar              #+#    #+#             */
/*   Updated: 2022/12/21 15:12:59 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_verify_errors(t_recup *recup)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (++i < (recup->nblines))
	{
		if (recup->minimap[i][0] != '1')
			ft_error2(recup, "Error\nNo walls\n");
	}
	i = -1;
	while (++i < (recup->nblines))
	{
		len = ft_strlen(recup->minimap[i]);
		if (recup->minimap[i][len - 1] != '1')
			ft_error2(recup, "Error\nNo walls\n");
	}
	if (check_wall(recup->minimap[0]) == 1)
		ft_error2(recup, "Error\nNo walls\n");
	if (check_wall(recup->minimap[recup->nblines - 1]) == 1)
		ft_error2(recup, "Error\nNo walls\n");
}

void	ft_error(t_recup *recup, char *str)
{
	int	i;

	i = -1;
	recup->indicateur3 = 1;
	if (!(recup->indicateurx))
		write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (recup->erreur == 1)
		exit(1);
	if (recup->no)
		free(recup->no);
	ft_error_cont(recup);
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
	ft_exit(recup);
}

void	ft_error_cont(t_recup *recup)
{
	int	i;

	i = -1;
	if (recup->so)
		free(recup->so);
	if (recup->ea)
		free(recup->ea);
	if (recup->we)
		free(recup->we);
	if (recup->sp)
		free(recup->sp);
	if (recup->map)
	{
		while (++i < recup->nblines)
		{
			if (recup->map[i] != NULL)
			{
				free(recup->map[i]);
				recup->map[i] = NULL;
			}
		}
	}
	if (recup->map)
		free(recup->map);
}

int	ft_exit(t_recup *recup)
{
	if (recup->indicateur3 == 0)
	{
		recup->indicateurx = 1;
		ft_error(recup, "Escaped\n");
	}
	if (recup->data.img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->data.img);
	if (recup->texture[0].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[0].img);
	if (recup->texture[1].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[1].img);
	if (recup->texture[2].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[2].img);
	if (recup->texture[3].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[3].img);
	if (recup->data.mlx_win)
		mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
	free(recup);
	exit(0);
}

int	ft_close(t_recup *recup)
{
	if (recup->indicateur3 == 0)
	{
		recup->indicateurx = 1;
		ft_error(recup, "Escaped\n");
	}
	return (0);
}

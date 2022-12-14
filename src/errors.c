/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 10:38:41 by nsar              #+#    #+#             */
/*   Updated: 2022/12/14 15:13:34 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_verify_errors(t_recup *recup)
{
	int	i;
	int	len;

	if (recup->depart == 'x')
		ft_error(recup, "Pas de joueur\n");
	// if (recup->indicateur2 != 6)
	// 	ft_error(recup, "Mauvaises donnees F ou C\n");

	i = -1;
	len = 0;
	while (++i < (recup->nblines))
	{
		if (recup->minimap[i][0] != '1')
			ft_error(recup, "No walls");
	}
	i = -1;
	while (++i < (recup->nblines))
	{
		len = ft_strlen(recup->minimap[i]);
		if (recup->minimap[i][len - 1] != '1')
			ft_error(recup, "No walls");
		// replace_empty(recup, len, recup->minimap[i]);
	}
	if (check_wall(recup->minimap[0]) == 1)
		ft_error(recup, "No walls");
	if (check_wall(recup->minimap[recup->nblines - 1]) == 1)
		ft_error(recup, "No walls");
}

void	ft_error(t_recup *recup, char *str)
{
	int i;

	i = -1;
	
	write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (recup->erreur == 1)
		exit(1);
/////////////////free textures
	// if (recup->no)
	// 	free(recup->no);
	// if (recup->so)
	// 	free(recup->so);
	// if (recup->we)
	// 	free(recup->we);
	// if (recup->ea)
	// 	free(recup->ea);
	// if (recup->sp)
	// 	free(recup->sp);

/////////////////free la map
	if (recup->minimap)
	{
		while (++i < recup->nblines)
			free(recup->minimap[i]);
	}
	if (recup->minimap)
		free(recup->minimap);

/////////////////free sorder, sdist, sxy
	// if (recup->s.order)
	// 	free(recup->s.order);
	// if (recup->s.dist)
	// 	free(recup->s.dist);
	// if (recup->sxy)//etait en comm je sais pas pourquoi
	// 	free(recup->sxy);//etait en comm je sais pas pourquoi

//////////////////free zbuffer
	// if (recup->s.zbuffer)//etait en comm je sais pas pourquoi
	// 	free(recup->s.zbuffer);//etait en comm je sais pas pourquoi


/*	while (i != 0)
	{
		system("leaks Cub3D");
	}*/
	ft_exit(recup);
}

int		ft_exit(t_recup *recup)
{
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
	if (recup->texture[4].img)
		mlx_destroy_image(recup->data.mlx_ptr, recup->texture[4].img);
	if (recup->data.mlx_win)
		mlx_destroy_window(recup->data.mlx_ptr, recup->data.mlx_win);
	exit(0);
}

int ft_close(t_recup *recup)
{
	(void)recup;
	exit(0);
}
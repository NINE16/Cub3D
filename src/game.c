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
					ft_error(recup, "Only one player is allowed");
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
		ft_error(recup, "You must have at least 1 player");
}

// void	init_minimap(t_recup *recup)
// {
// 	// recup->data.mlx_ptr = mlx_init();
// 	// ft_get_texture_1(recup);
// 	// recup->data.mlx_win = mlx_new_window(recup->data.mlx_ptr,
// 			// 1920, 1080, "Cub3D");
// 	recup->data.img2 = mlx_new_image(recup->data.mlx_ptr,
// 			(recup->data.width * 4), (recup->data.height * 4));
// 	recup->data.addr2 = (int *)mlx_get_data_addr(recup->data.img2,
// 			&recup->data.bits_per_pixel2, &recup->data.line_length2,
// 			&recup->data.endian2);
// 	recup->data.miniheight = 15 * 7;
// 	recup->data.miniwidth = 30 * 7;
// }

void	put_area(t_recup *recup)
{
	int	i;
	int	j;

	i = 0;
	// init_minimap(recup);
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
	// mlx_put_image_to_window(recup->data.mlx_ptr,
	// 	recup->data.mlx_win, recup->data.img, 50, 50);
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

// void	my_mlx_pixel_put(t_recup *recup, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = recup->data.addr + (y * recup->data.line_length
// 			+ x * (recup->data.bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

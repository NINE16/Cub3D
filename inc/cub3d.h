/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nnemeth <nnemeth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:30 by nsar              #+#    #+#             */
/*   Updated: 2022/12/21 15:21:31 by nnemeth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../mlx/mlx.h"
# include "../Libft/libft/libft.h"

# define ROTATE_LEFT		123
# define ROTATE_RIGHT		124
# define FORWARD_W_Z		13
# define BACK_S_S			1
# define RIGHT_D_D			2
# define LEFT_A_Q			0
# define KEY_EXIT			17

# define RED 0x00FF0000
# define BLUE 0x005F9EA0 
# define GRN  0x0000FF00 
# define YELL 0x00DFFF00

typedef struct s_sprxy
{
	double		x;
	double		y;
}					t_sprxy;

typedef struct s_sprite
{
	int			*order;
	double		*dist;
	double		*zbuffer;
}					t_sprite;

typedef struct s_texture
{
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}					t_texture;

typedef struct s_ray
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		movespeed;
	double		rotspeed;
	int			x;
	int			texture;
}					t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			bits_per_pixel2;
	int			line_length2;
	int			endian2;
	int			miniheight;
	int			miniwidth;
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
	int			minimapechelle;
	int			width;
	int			height;
	void		*img2;
	int			*addr2;
}					t_data;

typedef struct s_recup
{
	int			rx;
	int			ry;
	int			i;
	int			f;
	int			c;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	char		**textures;
	int			nblines;
	int			sizeline;
	char		**map;
	char		**minimap;
	int			elements;
	char		depart;
	int			dx;
	int			dy;
	int			indicateur;
	int			indicateur3;
	int			indicateur2;
	int			indicateurx;
	int			erreur;
	t_data		texture[5];
	t_data		data;
	t_ray		ray;
	t_texture	t;
	t_sprite	s;
	t_sprxy		*sxy;
}					t_recup;

//--------------PARSING----------------//
//parsing.c
int			ft_cub(char *str, t_recup *recup);
void		ft_parsing(char *fichier, t_recup *recup);
int			ft_parsing_map(char *fichier, t_recup *recup);
void		ft_imprime_map(t_recup *recup);
//parsing_utils.c
int			ft_strlen2(char *str);
int			ft_charinstr(char *str, char c);
int			ft_murs_util(char *str);
int			ft_depart(char c, t_recup *recup, int i, int j);
//parsing_color_resolution_texture.c
void		ft_color_resolution(char **str, t_recup *recup);
int			ft_atoi2(const char *str, t_recup *recup);
int			ft_atoi3(const char *str, t_recup *recup);
void		ft_texture(char *str, t_recup *recup);
int			ft_path_texture(char *str, char **texture, t_recup *recup, int j);
//parsing_map.c
void		ft_initialisation(t_recup *recup);
int			ft_murs(t_recup *recup);
int			ft_is_map(char *str);
void		ft_map(char *str, t_recup *recup);
void		free_value(t_recup *recup);

//--------------RAYCASTING----------------//
//raycasting.c
int			ft_raycasting(t_recup *recup);
int			ft_mlx(t_recup *recup);
//keysdraw.c
int			ft_key_press(int keycode, t_recup *recup);
int			ft_key_release(int keycode, t_recup *recup);
int			ft_color_column(t_recup *recup);
void		ft_draw_texture(t_recup *recup, int x, int y);
//raycasting_init.c
void		ft_initialisation2(t_recup *recup);
void		ft_initialisation3(t_recup *recup);
void		ft_init_texture(t_recup *recup);
//raycasting_utils.c
void		ft_stepsidedist(t_recup *recup);
void		ft_incrementray(t_recup *recup);
void		ft_drawstartend(t_recup *recup);
void		ft_swap(t_recup *recup);
//raycasting_move.c
void		ft_forward_back(t_recup *recup);
void		ft_left_right(t_recup *recup);
void		ft_rotate_right_left(t_recup *recup);
void		ft_rotate_left(t_recup *recup, double oldDirX);

//errors.c
void		ft_error(t_recup *recup, char *str);
int			ft_exit(t_recup *recup);
void		ft_verify_errors(t_recup *recup);
int			ft_close(t_recup *recup);
//init.c
void		ft_init_2(t_recup *recup);
void		ft_init_dir(t_recup *recup);
void		ft_init_more3(t_recup *recup);

void		ft_hitpoints(t_recup *recup);

char		*ft_subbuff(char *buff, int start, int len);

char		*get_next_line(int fd);
char		*get_line(char *save);
char		*read_line(int fd, char *save);
char		*next_line(char *save);
char		*mapcheck(t_recup *recup);
void		check_map(t_recup *recup, char *ficher);
void		ft_print_map(t_recup *recup);
int			ft_copy_map(char *str, t_recup *recup);
void		find_player(t_recup *recup);
void		init_minimap(t_recup *recup);
void		my_mlx_pixel_put(t_recup *recup, int x, int y, int color);
void		put_area(t_recup *recup);
int			get_color(char *minimap, char c);
t_data		*init_data(t_data *data);
void		ft_create_minimap(t_recup *recup);
int			draw_map(t_recup *recup, int color);
int			ft_mini_print(t_recup *recup, int i, int j, int nb);
void		check_elements(t_recup *recup);
int			ft_charinstr(char *str, char c);
void		check_minimap(t_recup *recup);
int			ft_isspace(unsigned char c);
int			check_wall(char *str);
void		ft_get_texture_1(t_recup *recup);
void		ft_get_texture(t_recup *recup);
void		free_map(t_recup *recup);
void		free_minimap(t_recup *recup);
void		replace_empty(t_recup *recup, int len, char *curr_line);
int			find_beg(char *str, int j);
void		ft_error2(t_recup *recup, char *str);
t_recup		*ft_struct_init2(t_recup *recup);
void		ft_error_cont(t_recup *recup);
void		ft_errors_more(t_recup *recup);

#endif

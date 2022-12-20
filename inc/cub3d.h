/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nemethnikol <nemethnikol@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:27:30 by nsar              #+#    #+#             */
/*   Updated: 2022/12/19 16:46:09 by nemethnikol      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

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

# ifdef Darwin
#  define SYS 	1
# endif

# ifdef Linux
#  define SYS	2
# endif

# define RED 0x00FF0000
# define BLUE 0x005F9EA0 
# define GRN  0x0000FF00 
# define YELL 0x00DFFF00

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 30
# endif

typedef struct	s_sprxy
{
 	double		x; //position x du sprite
	double		y; //position y du sprite
}					t_sprxy;

typedef struct	s_sprite
{
	int			*order;
	double		*dist;
	double		*zbuffer;
}					t_sprite;

typedef struct  s_texture
{
	int			texdir; //direction NO, S, EA, WE de la texture
	double		wallx; // valeur où le mur a été touché : coordonnée y si side == 0, coordonnée x si side == 1
	int			texx; // coordonnée x de la texture
	int			texy; // coordonée y de la texture
	double		step; // indique de combien augmenter les coordonnées de la texture pour chaque pixel
	double		texpos; // coordonnée de départ
}					t_texture;

typedef struct	s_ray
{
	double		posx;
	double		posy;
	double		dirx; //vecteur de direction
	double		diry; //vecteur de direction
	double		planx; //vecteur du plan
	double		plany; //vecteur du plan
	double		raydirx; //calcul de direction x du rayon
	double		raydiry; //calcul de direction y du rayon
	double		camerax; //point x sur la plan camera : Gauche ecran = -1, milieu = 0, droite = 1
	int			mapx; // coordonée x du carré dans lequel est pos
	int			mapy; // coordonnée y du carré dans lequel est pos
	double		sidedistx; //distance que le rayon parcours jusqu'au premier point d'intersection vertical
	double		sidedisty; //distance que le rayon parcours jusqu'au premier point d'intersection horizontal
	double		deltadistx; //distance que rayon parcours entre chaque point d'intersection vertical
	double		deltadisty; //distance que le rayon parcours entre chaque point d'intersection horizontal
	int			stepx; // -1 si doit sauter un carre dans direction x negative, 1 dans la direction x positive
	int			stepy; // -1 si doit sauter un carre dans la direction y negative, 1 dans la direction y positive
	int			hit; // 1 si un mur a ete touche, 0 sinon
	int			side; // 0 si c'est un cote x qui est touche (vertical), 1 si un cote y (horizontal)
	double		perpwalldist; // distance du rayon
	int			lineheight; //hauteur de la ligne a dessiner
	int			drawstart; //position de debut ou il faut dessiner
	int			drawend; //position de fin ou il faut dessiner
	double		movespeed;
	double		rotspeed;
	int			x;
	int			texture;
}					t_ray;

typedef struct		s_data
{
//mlx, keys
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
	int			width; // recup->texture.width : nombre de pixels de largeur de la texture
	int 		height;// recup->texture.height : nombre de pixels dans la longueur de la texture
	void		*img2;
	int			*addr2;
}					t_data;

typedef struct		s_recup
{
//parsing :
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
	char 		**textures;
	int			nblines;//nb line dans toutes la map
	int			sizeline;
	char		**map;//prend map a deux dimensions met dans char ** , allouer dans ft_parsing_map
	char		**minimap;
	int			elements;
	char		depart; //position depart : N S E W
	int			dx; //x de position depart
	int			dy; //y position depart
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
void    	ft_texture(char *str, t_recup *recup);
int			ft_path_texture(char *str, char **texture, t_recup *recup, int j);
//parsing_map.c
void		ft_initialisation(t_recup *recup);
int			ft_murs(t_recup *recup);
int			ft_is_map(char *str);
void		ft_map(char *str, t_recup *recup);
void	free_value(t_recup *recup);


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
void ft_init_2(t_recup *recup);
void ft_init_dir(t_recup *recup);
void ft_init_more3(t_recup *recup);


//--------------BONUS----------------//
//hitpoints.c
void		ft_hitpoints(t_recup *recup);

char		*ft_subbuff(char *buff, int start, int len);
// char		*ft_strjoin(char *s1, char *s2);
// char		*ft_substr(char const *s, unsigned int start, size_t len);
// int			ft_strlen(char *str);

char		*get_next_line(int fd);
char		*get_line(char *save);
char		*read_line(int fd, char *save);
char		*next_line(char *save);
// char		**ft_split(char *s, char c);
char		*mapcheck(t_recup *recup);
void		check_map(t_recup *recup, char *ficher);
void		ft_print_map(t_recup *recup);
int			ft_copy_map(char **map, t_recup *recup);
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
void 		ft_get_texture_1(t_recup *recup);
void		ft_get_texture(t_recup *recup);
void		free_map(t_recup *recup);
void		free_minimap(t_recup *recup);
void		replace_empty(t_recup *recup, int len, char *curr_line);
int			find_beg(char *str, int j);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbeck <jbeck@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:47:53 by joschka           #+#    #+#             */
/*   Updated: 2024/12/13 18:05:08 by jbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define ERR_USAGE "usage: ./cub3d <path/to/map.cub>"
# define ERR_DIR "is a directory"
# define ERR_CUB "file without .cub extension"
# define ERR_XPM "file is not a .xpm file"
# define ERR_ELEMENT "unallowed element in .cub file"
# define ERR_LAST "map is not last element in .cub file"
# define ERR_CHAR "unallowed character in map detected"
# define ERR_LABORD "or map is not sourrounded by walls (1)"
# define ERR_TEXT "texture element has too many arguments"
# define ERR_TEX "please provide path to texture"
# define ERR_TE "element has too few arguments"
# define ERR_COLOR "invalid color code"
# define ERR_MAP "no valid map in .cub file found"
# define ERR_WALL "map is not surrounded by walls"
# define ERR_PLAYCOUNT "there has to be exactly one player"
# define ERR_TEXTURE "loading textures failed"

# define WIDTH 768
# define HEIGHT 640
# define BLOCK 64
# define PI 3.14159265359

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

typedef struct s_player
{
	float		x;
	float		y;
	float		angle;

	float		speed;
	float		angle_speed;

	int			key_up;
	int			key_down;
	int			key_left;
	int			key_right;

	int			left_rotate;
	int			right_rotate;
}				t_player;

typedef struct s_angle
{
	float		cos;
	float		sin;
}				t_angle;

typedef struct s_img
{
	void		*img_ptr;
	char		*img_pixels_ptr;
	int			bits_per_pixel;
	int			endian;
	int			line_len;
}				t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_player	player;
	int			wall_collision;
}				t_game;

typedef struct s_map
{
	int			width;
	int			height;
	char		**map_tab;
	int			not_surrounded;
	int			player_count;
}				t_map;

typedef struct s_tex_img
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}				t_tex_img;

typedef struct s_textures
{
	char		**path_n;
	char		**path_s;
	char		**path_w;
	char		**path_e;
	t_tex_img	*tex_n;
	t_tex_img	*tex_s;
	t_tex_img	*tex_w;
	t_tex_img	*tex_e;
	t_tex_img	**tex;
	int			*floor;
	int			*ceiling;
}				t_textures;

typedef struct s_ray
{
	float		distance;
	int			direction;
	float		wall_x;
	float		step_x;
	float		step_y;
	float		delta_x;
	float		delta_y;
	float		side_dist_x;
	float		side_dist_y;
	float		hit_x;
	float		hit_y;
	int			side;
}				t_ray;

typedef struct s_line
{
	int			draw_start;
	int			draw_end;
	int			y_start;
	int			y_end;
	t_tex_img	*tex;
	int			tex_x;
}				t_line;

typedef struct s_scenery
{
	int			fd;
	int			lcount;
	char		*s_path;
	char		**scene;
}				t_scenery;

typedef struct s_data
{
	t_scenery	scenery;
	t_textures	textures;
	t_map		map;
	t_game		game;
}				t_data;

void			init(t_data *data);
void			squeaky_clean(t_data *data);
void			clean_exit(t_data *data, int code);
void			cleanup_textures(t_data *data);
int				parsing(char *path, t_data *data);
int				print_error(char *src, char *str, int errcode);
int				skip_space(char *str);
void			free_array(char **arr);
int				get_scene(t_scenery *scenery);
void			cut_newline(char **arr);
int				check_elements(char **scene);
int				map_last(char **scene);
int				get_textures(t_data *data);
int				load_all_textures(t_data *data);
int				get_colors(t_data *data);
int				get_map(t_data *data);
int				find_mapstart(char **arr);
int				check_map(t_map *map);
int				is_player(char c);
void			game(t_data *data);
void			draw_map(t_data *data);
void			draw_square(int x, int y, int size, t_game *game);
void			my_pixel_put(t_img *img, int x, int y, int color);
void			clear_image(t_img *img);
int				ft_key_release(int key, t_data *data);
int				ft_key_press(int key, t_data *data);
int				esc_hook(t_data *data);
void			get_player_pos(t_data *data);
void			move_player(t_player *player, t_data *data);
int				collision(t_data *data, int x, int y);
int				get_rgb(int *rgb);
int				collision(t_data *data, int x, int y);
void			raycasting(int x, int y, t_data *data);
t_tex_img		*load_texture(void *mlx, char *path);
void			draw_minimap(t_data *data);
int				check_xpm_extension(char *path);
int				check_xpm_file(char *path);
int				check_array(char **arr);
void			get_player_angle(char c, t_player *player);
void			get_player_pos(t_data *data);
void			draw_player_dot(t_data *data, float px, float py);
void			draw_direction_line(t_data *data, float px, float py);
void			init_textures(t_textures *textures);
void			init_map(t_map *map);
void			perform_dda(t_data *data, t_ray *ray, float x, float y);
void			prepare_dda(t_ray *ray, float x, float y);
int				get_direction(float step, int side);

#endif

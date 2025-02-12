/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 23:17:29 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/12 18:58:48 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "structures.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MOVESPEED 0.05
# define ROTSPEED 0.05

# define SHOOT_DISTANCE 5
# define SHOOT_PRECISION 0.3

# define GUN_IDLE_PATH "./assets/base/gun_idle.xpm"
# define GUN_FIRE_PATH "./assets/base/gun_fire.xpm"
# define FIRE_SOUND_PATH "./assets/base/33.wav"

# define ENEMY_IDLE_PATH "./assets/base/guard.xpm"
# define ENEMY_DEAD_PATH "./assets/base/dead.xpm"

# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

int			check_args(int argc, char **argv);
char		**check_map(char *map_path);
int			check_file(char *arg);
char		*remove_spaces(char *line);
void		ft_free_array(char **array);
int			check_color(char *color);
int			is_file_empty(char *map_path);
int			check_initial_conditions(int argc, char **argv);
int			check_map_validity(char **map, char *map_path);
int			check_assets_validity(t_map_info *map_info);
int			check_map_and_colors(char **map, t_map_info *map_info,
				char *map_path);
size_t		ft_array_len(char **array);
int			check_map_content(char **map, t_map_info *map_info, char *map_path);
void		free_all(char **map, t_map_info *map_info);
char		**parse_map(char *map_path);
size_t		get_map_size(char *map_path);
char		**allocate_map_array(char *map_path);
int			*find_player(char **map);
char		*remove_n(char *line);
int			validate_map(char **map);
t_map_info	map_to_struct(char **map, char *map_path);
char		*ft_strpad(char *str, int len, char pad);
int			skip_non_map_lines(int fd, char **line);
int			process_map_lines(int fd, char **map, char *line);
void		pad_map_lines(char **map, int max_len);
int			init_parse_data(t_parse_data *data, char *map_path);
void		cleanup_parse_data(t_parse_data *data);
void		free_map(char **map);
int			is_rgb(char *line);
int			skip_non_map_lines(int fd, char **line);
int			process_map_lines(int fd, char **map, char *line);
char		*remove_map_spaces(char *line);
char		**ft_arraydup(char **array);
t_map_info	*parse_assets(char *map_path, t_map_info *map_info);
size_t		ft_array_len(char **map);
t_map_info	*set_cardinals_path(char *line, t_map_info *map_info);
t_map_info	*parse_color(char *line, t_map_info *map_info);
int			file_exists(char *path);
char		*ft_strstr(char *str, char *to_find);
char		**copy_map(char **map);
int			check_map_player(char **map, t_map_info *map_info);
int			is_map_last(char *map_path, char **map);
void		free_int_array(int **array, int size);
t_game		*init_game(t_map_info map_info);
void		render_game(t_game *game);
void		raycasting(t_raycast *raycast, t_game *game);
void		init_raycast(t_raycast *raycast);
void		init_screen_buffer(t_game *game);
void		*ft_calloc(size_t count, size_t size);
void		render_sprites(t_game *game, double *z_buffer);
t_texture	init_xpm_texture(t_game *game, char *filename);
void		shoot_weapon(t_game *game);
void		play_sound(const char *path);
t_player    init_player(t_game *game);
void		draw_texture_on_screen(t_game *game, t_texture tex, int scale, int draw_x, int draw_y);
void 		move_forward(t_player *player, char **map);
void    	move_backward(t_player *player, char **map);
void    	move_right(t_player *player, char **map);
void    	move_left(t_player *player, char **map);
void 		rotate_right(t_player *player);
void 		rotate_left(t_player *player);
void		move_player(t_game *game);
void		init_enemies(t_game *game);
size_t		get_enemy_index(t_game *game, double x, double y);
void		move_enemy(t_game *game, int enemy_index);

#endif

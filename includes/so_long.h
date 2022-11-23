/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leoferre <leoferre@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:26:35 by leoferre          #+#    #+#             */
/*   Updated: 2022/10/25 20:22:44 by leoferre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"
# include <fcntl.h>

# define KEY_ESCAPE (0xff1b)
# define PIXEL 32
# define KEY_UP (0x77)
# define KEY_DOWN (0x73)
# define KEY_RIGHT (0x64)
# define KEY_LEFT (0x61)

typedef struct s_map
{
	int		player;
	int		collectible;
	int		exit_map;
	int		width;
	int		height;
	char	**map;
}	t_map;

typedef struct s_path
{
	int		collectible;
	int		exit_map;
	char	**aux;
}	t_path;

typedef struct s_images
{
	int		*floor;
	int		*soldier_right;
	int		*soldier_left;
	void	*c4;
	void	*bombsite;
	void	*wall;
}	t_images;

typedef struct s_player
{
	int	p_x;
	int	p_y;
}	t_player;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_images	images;
	int			moves;
	t_player	player;
	char		direction;
}	t_game;

enum e_status
{
	WRONG_NBR_CHARS,
	WRONG_CHARS,
	WRONG_EXT,
	WRONG_SHAPE,
	WRONG_PATH,
	WRONG_ARGS,
	WRONG_WALLS,
	WRONG_MAP,
	WRONG_FILE,
	WRONG_GRAPHIC
};

void	map_check(char *argv, t_game *game);
void	ext_check(char *argv);
void	shape_check(char **map);
void	map_free(char **map);
void	walls_check(char **map);
void	chars_check(char **map, t_game *game);
void	path_check(char *argv, t_game *game);
char	*map_read(char *argv);
void	so_long(t_game *game);
void	game_free(t_game *game);
int		render_game(t_game *game);
int		keys_game(int key, t_game *game);
int		x_game(t_game *game);
void	move_game(int key, t_game *game);
void	sides_game(t_game *game, char direction);
int		warning_printer(int status);

#endif
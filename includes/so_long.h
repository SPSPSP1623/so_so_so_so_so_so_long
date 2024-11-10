#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include <unistd.h>

# define SIZE 64

# define TRUE 1
# define FALSE 0

# define WIN_W 600
# define WIN_H 600

# define GAME_NAME "so_long"

# define IMG_W 64
# define IMG_H 64

# define WALL '1'
# define TILE '0'
# define START 'P'
# define COLLECT 'C'
# define EXIT 'E'

# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_LEFT 65361
# define ARROW_RIGHT 65363
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

# define WALL_XPM "textures/wall.xpm"
# define TILE_XPM "textures/tiles.xpm"
# define COLLECT_XPM "textures/collectible.xpm"
# define EXIT_XPM "textures/exit.xpm"
# define UP_XPM "textures/p_back.xpm"
# define DOWN_XPM "textures/p_face.xpm"
# define LEFT_XPM "textures/p_left.xpm"
# define RIGHT_XPM "textures/p_right.xpm"

typedef struct s_text
{
	int		h;
	int		w;
	void	*img;
}			t_text;

typedef struct s_co
{
	int	x;
	int	y;
}			t_co;

typedef struct s_data
{
	int			start;
	int			collectible;
	int			collected;
	int			c_attainable;
	int			e_attainable;
	int			exit;
	char		*map_path;
	t_co		pl_p;
	t_co		e_p;
	t_text		twall;
	t_text		ttile;
	t_text		tcol;
	t_text		texit;
	t_text		tp_u;
	t_text		tp_d;
	t_text		tp_l;
	t_text		tp_r;
}			t_data;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	void	*addy;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}			t_mlx;

typedef struct s_tile
{
	char	type;
	int		seen;
}			t_tile;

typedef struct s_map
{
	int		h;
	int		w;
	int		len;
	int		fd;
	t_tile	**t;
	int		x_ax;
	int		y_ax;
}			t_map;

typedef struct s_core
{
	t_data		*data;
	t_map		*map;
	t_mlx		*mlx;
}			t_core;

/* INIT.C */
void	init_structs(t_core *core, t_data *data, t_map *map, t_mlx *mlx);
void	init_so_long(t_core *core, char *path);
void	init_map(t_data *data, t_map *map, t_core *core);
void	ft_screen_size(t_core *core);
void	ft_get_textures(t_core *core, t_data *data, t_mlx *mlx);

/* ERRORS.C */
void	w_error(char *error);
void	w_error_exit(char *error);
void	get_error(t_core *core, char *error);
void	check_argcv(int argc, char *map_name);
int		ft_map_name_checker(char *map_name);

/* PARSING.C */
void	ft_parser(t_data *data, t_map *map, t_core *core);

/* UTILS_PARSING1.C */
int		ft_map_line_length(char *str);
void	ft_wall_checker(t_core *core, t_map *map);
void	ft_data_check(t_data *data, t_map *map, char type);
void	ft_checking_checker(t_core *core, t_data *data);

/* UTILS_PARSING2.C */
void	ft_init_check(t_core *core, int y, int x);

/* DRAW.C */
void	ft_draw(t_data *data, t_map *map, t_mlx *mlx);

/* MOVE.C */
int		ft_key_hook(int key, t_core *core);

/* END.C */
int		ft_close_window(t_core *core);
void	ft_fail_before_mlx(t_core *core, char *error);

/* LIBFT.C */
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

#endif

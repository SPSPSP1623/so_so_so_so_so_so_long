#include "so_long.h"

void	init_structs(t_core *core, t_data *data, t_map *map, t_mlx *mlx)
{
	core->data = data;
	core->map = map;
	core->mlx = mlx;
}

void	init_so_long(t_core *core, char *path)
{
	core->data->start = 0;
	core->data->collectible = 0;
	core->data->collected = 0;
	core->data->exit = 0;
	core->data->map_path = path;
	core->map->h = 0;
	core->map->w = 0;
	core->map->len = 1;
	core->data->twall.img = NULL;
	core->data->ttile.img = NULL;
	core->data->tcol.img = NULL;
	core->data->texit.img = NULL;
	core->data->tp_u.img = NULL;
	core->data->tp_d.img = NULL;
	core->data->tp_l.img = NULL;
	core->data->tp_r.img = NULL;
}

void	init_map(t_data *data, t_map *map, t_core *core)
{
	map->fd = open(data->map_path, O_RDONLY);
	map->t = malloc(map->h * sizeof(t_tile *));
	if (!map->t)
		get_error(core, "Error: map->t malloc went wrong.\n");
	map->x_ax = 0;
	map->y_ax = 0;
}

void	ft_get_textures_two(t_core *core, t_data *data, t_mlx *mlx)
{
	core->data->tp_u.img = mlx_xpm_file_to_image(mlx->ptr, UP_XPM, \
		&data->tp_u.w, &data->tp_u.h);
	if (!(core->data->tp_u.img))
		ft_close_window(core);
	core->data->tp_d.img = mlx_xpm_file_to_image(mlx->ptr, DOWN_XPM, \
		&data->tp_d.w, &data->tp_d.h);
	if (!(core->data->tp_d.img))
		ft_close_window(core);
	core->data->tp_l.img = mlx_xpm_file_to_image(mlx->ptr, LEFT_XPM, \
		&data->tp_l.w, &data->tp_l.h);
	if (!(core->data->tp_l.img))
		ft_close_window(core);
	core->data->tp_r.img = mlx_xpm_file_to_image(mlx->ptr, RIGHT_XPM, \
		&data->tp_r.w, &data->tp_r.h);
	if (!(core->data->tp_r.img))
		ft_close_window(core);
}

void	ft_get_textures(t_core *core, t_data *data, t_mlx *mlx)
{
	core->data->twall.img = mlx_xpm_file_to_image(mlx->ptr, WALL_XPM, \
		&data->twall.w, &data->twall.h);
	if (!core->data->twall.img)
		ft_close_window(core);
	core->data->ttile.img = mlx_xpm_file_to_image(mlx->ptr, TILE_XPM, \
		&data->ttile.w, &data->ttile.h);
	if (!core->data->ttile.img)
		ft_close_window(core);
	core->data->tcol.img = mlx_xpm_file_to_image(mlx->ptr, COLLECT_XPM, \
		&data->tcol.w, &data->tcol.h);
	if (!(core->data->tcol.img))
		ft_close_window(core);
	core->data->texit.img = mlx_xpm_file_to_image(mlx->ptr, EXIT_XPM, \
		&data->texit.w, &data->texit.h);
	if (!(core->data->texit.img))
		ft_close_window(core);
	ft_get_textures_two(core, data, mlx);
}

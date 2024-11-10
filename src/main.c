#include "so_long.h"

void	ft_screen_size(t_core *core)
{
	int	pc_w;
	int	pc_h;

	pc_w = 0;
	pc_h = 0;
	mlx_get_screen_size(core->mlx->ptr, &pc_w, &pc_h);
	if (core->map->w * IMG_W > pc_w)
		get_error(core, "Error: Map width too big.\n");
	if (core->map->h * IMG_H > pc_h)
		get_error(core, "Error: Map height too big.\n");
}

void	ft_mlx(t_core *core, t_map *map, t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		ft_fail_before_mlx(core, "Error: mlx_init failed.\n");
	mlx->win = mlx_new_window(mlx->ptr, map->w * SIZE, map->h * SIZE, \
		"so_long");
	if (!mlx->win)
		get_error(core, "Error: problem with the window creation.\n");
}

int	main(int argc, char *argv[])
{
	t_data		data;
	t_map		map;
	t_mlx		mlx;
	t_core		core;

	check_argcv(argc, argv[1]);
	init_structs(&core, &data, &map, &mlx);
	init_so_long(&core, argv[1]);
	ft_parser(&data, &map, &core);
	ft_mlx(&core, &map, &mlx);
	ft_screen_size(&core);
	ft_get_textures(&core, &data, &mlx);
	ft_draw(&data, &map, &mlx);
	mlx_hook(mlx.win, 17, 1L << 0, ft_close_window, &core);
	mlx_hook(mlx.win, 2, 1L << 0, ft_key_hook, &core);
	mlx_loop(mlx.ptr);
}

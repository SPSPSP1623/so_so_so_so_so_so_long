#include "so_long.h"

void	ft_dir_player(t_core *core, t_data *data, int key)
{
	if (key == W)
		mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
			core->data->tp_u.img, data->pl_p.x * SIZE, data->pl_p.y * SIZE);
	if (key == S)
		mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
			core->data->tp_d.img, data->pl_p.x * SIZE, data->pl_p.y * SIZE);
	if (key == A)
		mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
			core->data->tp_l.img, data->pl_p.x * SIZE, data->pl_p.y * SIZE);
	if (key == D)
		mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
			core->data->tp_r.img, data->pl_p.x * SIZE, data->pl_p.y * SIZE);
}

void	ft_check_move(t_core *core, t_data *data)
{
	if (core->map->t[data->pl_p.y][data->pl_p.x].type == COLLECT \
		&& core->map->t[data->pl_p.y][data->pl_p.x].seen == 1)
	{
		core->data->collected++;
		core->map->t[data->pl_p.y][data->pl_p.x].seen--;
	}
	if (core->map->t[data->pl_p.y][data->pl_p.x].type == EXIT)
	{
		if (core->data->collected == core->data->collectible)
		{
			ft_close_window(core);
			exit(EXIT_SUCCESS);
		}
		else
			mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
				core->data->texit.img, data->pl_p.x * SIZE, \
					data->pl_p.y * SIZE);
	}
}

void	ft_print_moves(t_data *data, int mooved_y, int mooved_x)
{
	static int	moves = 0;

	if (mooved_y != data->pl_p.y || mooved_x != data->pl_p.x)
	{
		moves++;
		if (moves == 1)
			ft_putstr_fd("Move: ", 1);
		else
			ft_putstr_fd("Moves: ", 1);
		ft_putnbr_fd(moves, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ft_move_player(t_core *core, t_data *data, int key)
{
	int			mooved_y;
	int			mooved_x;

	mooved_y = data->pl_p.y;
	mooved_x = data->pl_p.x;
	if (core->map->t[data->pl_p.y][data->pl_p.x].type == EXIT)
		mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
			core->data->texit.img, data->pl_p.x * SIZE, data->pl_p.y * SIZE);
	else
		mlx_put_image_to_window(core->mlx->ptr, core->mlx->win, \
			core->data->ttile.img, data->pl_p.x * SIZE, data->pl_p.y * SIZE);
	if (key == W && core->map->t[data->pl_p.y - 1][data->pl_p.x].type != WALL)
		data->pl_p.y -= 1;
	if (key == S && core->map->t[data->pl_p.y + 1][data->pl_p.x].type != WALL)
		data->pl_p.y += 1;
	if (key == A && core->map->t[data->pl_p.y][data->pl_p.x - 1].type != WALL)
		data->pl_p.x -= 1;
	if (key == D && core->map->t[data->pl_p.y][data->pl_p.x + 1].type != WALL)
		data->pl_p.x += 1;
	ft_check_move(core, data);
	ft_dir_player(core, data, key);
	ft_print_moves(data, mooved_y, mooved_x);
}

int	ft_key_hook(int key, t_core *core)
{
	t_data	*data;

	data = core->data;
	if (key == W || key == ARROW_UP)
		ft_move_player(core, data, W);
	if (key == S || key == ARROW_DOWN)
		ft_move_player(core, data, S);
	if (key == A || key == ARROW_LEFT)
		ft_move_player(core, data, A);
	if (key == D || key == ARROW_RIGHT)
		ft_move_player(core, data, D);
	if (key == ESC)
	{
		ft_close_window(core);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

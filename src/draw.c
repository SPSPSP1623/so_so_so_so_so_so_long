#include "so_long.h"

void	ft_put_components(t_data *data, t_mlx *mlx, char comp, t_co *co)
{
	if (comp == WALL)
		mlx_put_image_to_window(mlx->ptr, mlx->win, \
			data->twall.img, co->x, co->y);
	if (comp == TILE)
		mlx_put_image_to_window(mlx->ptr, mlx->win, \
			data->ttile.img, co->x, co->y);
	if (comp == START)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, \
			data->tp_d.img, co->x, co->y);
		data->pl_p.x = co->x / SIZE;
		data->pl_p.y = co->y / SIZE;
	}
	if (comp == COLLECT)
		mlx_put_image_to_window(mlx->ptr, mlx->win, \
			data->tcol.img, co->x, co->y);
	if (comp == EXIT)
	{
		mlx_put_image_to_window(mlx->ptr, mlx->win, \
			data->texit.img, co->x, co->y);
		data->e_p.x = co->x / SIZE;
		data->e_p.y = co->y / SIZE;
	}
}

void	ft_map(t_data *data, t_map *map, t_mlx *mlx)
{
	t_co	co;

	co.y = 0;
	while (co.y < map->h * SIZE)
	{
		co.x = 0;
		while (co.x < map->w * SIZE)
		{
			if (map->t[co.y / SIZE][co.x / SIZE].type == WALL)
				ft_put_components(data, mlx, WALL, &co);
			if (map->t[co.y / SIZE][co.x / SIZE].type == TILE)
				ft_put_components(data, mlx, TILE, &co);
			if (map->t[co.y / SIZE][co.x / SIZE].type == START)
				ft_put_components(data, mlx, START, &co);
			if (map->t[co.y / SIZE][co.x / SIZE].type == COLLECT)
				ft_put_components(data, mlx, COLLECT, &co);
			if (map->t[co.y / SIZE][co.x / SIZE].type == EXIT)
				ft_put_components(data, mlx, EXIT, &co);
			co.x += SIZE;
		}
		co.y += SIZE;
	}
}
/*
void	ft_background(t_map *map, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->h)
	{
		x = 0;
		while (x < map->w)
		{
			mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, x, y);
			x += IMG_W;
		}
		y += IMG_H;
	}
}
*/

void	ft_draw(t_data *data, t_map *map, t_mlx *mlx)
{
	//ft_background(map, mlx);
	ft_map(data, map, mlx);
}

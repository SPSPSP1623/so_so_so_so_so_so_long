#include "so_long.h"

void	ft_char_check(t_core *core, int y, int x)
{
	if (core->map->t[y][x].type != WALL && core->map->t[y][x].type != TILE && \
		core->map->t[y][x].type != START && core->map->t[y][x].type != COLLECT \
		&& core->map->t[y][x].type != EXIT)
		ft_fail_before_mlx(core, "Error: wrong character in .ber map.\n");
}

void	ft_flood_check(t_core *core, int y, int x)
{
	if (core->map->t[y][x].type == WALL || core->map->t[y][x].seen == 1)
		return ;
	ft_char_check(core, y, x);
	core->map->t[y][x].seen = 1;
	if (core->map->t[y][x].type == 'C')
		core->data->c_attainable++;
	if (core->map->t[y][x].type == 'E')
		core->data->e_attainable++;
	ft_flood_check(core, y - 1, x);
	ft_flood_check(core, y, x - 1);
	ft_flood_check(core, y + 1, x);
	ft_flood_check(core, y, x + 1);
}

void	ft_init_check(t_core *core, int y, int x)
{
	core->data->c_attainable = 0;
	core->data->e_attainable = 0;
	ft_flood_check(core, y, x);
	if (core->data->c_attainable - core->data->collectible != 0)
		ft_fail_before_mlx(core, "Error: collectible unattainable.\n");
	if (core->data->e_attainable - core->data->exit != 0)
		ft_fail_before_mlx(core, "Error: exit not accessible.\n");
}

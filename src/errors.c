#include "so_long.h"

void	w_error(char *error)
{
	ft_putstr_fd(error, 2);
}

void	w_error_exit(char *error)
{
	w_error(error);
	exit(EXIT_FAILURE);
}

void	get_error(t_core *core, char *error)
{
	w_error(error);
	ft_close_window(core);
}

void	check_argcv(int argc, char *map_name)
{
	if (argc == 1)
	{
		w_error("No map\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc > 2)
	{
		w_error("Too many arguments.\n");
		exit(EXIT_SUCCESS);
	}
	else if (argc == 2 && !ft_map_name_checker(map_name))
	{
		w_error("The map is not a .ber file.\n");
		exit(EXIT_SUCCESS);
	}
}

int	ft_map_name_checker(char *m)
{
	int	i;

	i = 0;
	while (m[i])
		i++;
	i--;
	if (m[i - 3] == '.' && m[i - 2] == 'b' && m[i - 1] == 'e' && m[i] == 'r')
		return (TRUE);
	else
		return (FALSE);
}

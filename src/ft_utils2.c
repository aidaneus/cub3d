#include "../includes/cub3d.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_sym(char *str)
{
	ft_isspace(&str);
	if (str && *str != '0'
		&& *str != '1'
		&& *str != '2')
		return (1);
	return (0);
}

int	map_check(int c)
{
	if (check_pl(c) || c == '0' || c == '2')
		return (1);
	return (0);
}

int	check_if(t_all all)
{
	if (all.parse.res_w == -1
		|| all.parse.res_h == -1
		|| all.parse.floor_color == -1
		|| all.parse.ceilling_color == -1
		|| all.parse.no_tex_path == NULL
		|| all.parse.we_tex_path == NULL
		|| all.parse.so_tex_path == NULL
		|| all.parse.ea_tex_path == NULL
		|| all.parse.sp_tex_path == NULL)
		return (0);
	return (1);
}

int	ft_comma(char **str)
{
	if (**str == ',')
	{
		*str += 1;
		return (1);
	}
	return (0);
}

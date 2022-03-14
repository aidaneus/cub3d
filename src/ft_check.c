#include "../includes/cub3d.h"

int	check_resolution(char **str, t_all *all)
{
	int	res;

	res = 0;
	ft_isspace(str);
	if (!(ft_isdigit(**str)))
		ft_exit_error("Resolution format", all);
	while (ft_isdigit(**str))
	{
		res = 10 * res + (**str - 48);
		*str += 1;
		if (res > all->parse.width && res > all->parse.height)
		{
			while (ft_isdigit(**str))
				*str += 1;
			break ;
		}
	}
	return (res);
}

int	check_colors(char **str, t_all all)
{
	int	res;

	res = 0;
	ft_isspace(str);
	if (!(ft_isdigit(**str)))
		ft_exit_error("Not valid color format", &all);
	while (ft_isdigit(**str))
	{
		res = 10 * res + (**str - 48);
		if (res > 255)
			ft_exit_error("Not valid color format", &all);
		*str += 1;
	}
	return (res);
}

static void	check_parse_path3(char **str, t_all *all)
{
	if (all->parse.texture == 5)
	{
		if (all->parse.sp_tex_path != NULL)
			ft_exit_error("Double info inclusion", all);
		all->parse.sp_tex_path = check_size(str, *all);
		if (!all->parse.sp_tex_path)
			ft_exit_error("Double info inclusion", all);
	}
}

static void	check_parse_path2(char **str, t_all *all)
{
	if (all->parse.texture == 3)
	{
		if (all->parse.so_tex_path != NULL)
			ft_exit_error("Double info inclusion", all);
		all->parse.so_tex_path = check_size(str, *all);
		if (!(all->parse.so_tex_path))
			ft_exit_error("Double info inclusion", all);
	}
	if (all->parse.texture == 4)
	{
		if (all->parse.ea_tex_path != NULL)
			ft_exit_error("Double info inclusion", all);
		all->parse.ea_tex_path = check_size(str, *all);
		if (!(all->parse.ea_tex_path))
			ft_exit_error("Double info inclusion", all);
	}
	check_parse_path3(str, all);
}

void	check_parse_path(char **str, t_all *all)
{
	ft_isspace(str);
	if (all->parse.texture == 1)
	{
		if (all->parse.no_tex_path != NULL)
			ft_exit_error("Double info inclusion", all);
		all->parse.no_tex_path = check_size(str, *all);
		if (!(all->parse.no_tex_path))
			ft_exit_error("Double info inclusion", all);
	}
	if (all->parse.texture == 2)
	{
		if (all->parse.we_tex_path != NULL)
			ft_exit_error("Double info inclusion", all);
		all->parse.we_tex_path = check_size(str, *all);
		if (!(all->parse.we_tex_path))
			ft_exit_error("Double info inclusion", all);
	}
	check_parse_path2(str, all);
}

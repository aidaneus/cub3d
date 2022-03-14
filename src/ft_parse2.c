#include "../includes/cub3d.h"

static int	check_texture(char **str, t_all *all)
{
	size_t	len;

	len = ft_strlen(*str);
	if (ft_strnstr(*str, "NO", len))
		all->parse.texture = 1;
	else if (ft_strnstr(*str, "WE", len))
		all->parse.texture = 2;
	else if (ft_strnstr(*str, "SO", len))
		all->parse.texture = 3;
	else if (ft_strnstr(*str, "EA", len))
		all->parse.texture = 4;
	else if (ft_strnstr(*str, "S ", len))
		all->parse.texture = 5;
	else
		return (0);
	if (all->parse.texture == 5)
		*str += 2;
	else if (all->parse.texture > 0)
		*str += 3;
	return (1);
}

static int	check_color(char **str, t_all *all)
{
	size_t	len;

	len = ft_strlen(*str);
	if (ft_strnstr(*str, "F", len))
		all->parse.texture = 1;
	else if (ft_strnstr(*str, "C", len))
		all->parse.texture = 2;
	else
		return (0);
	*str += 2;
	return (1);
}

void	ft_color2(t_all *all, int res)
{
	if (all->parse.texture == 1)
	{
		if (all->parse.floor_color != -1)
			ft_exit_error("Double info inclusion", all);
		all->parse.floor_color = res;
		if (all->parse.floor_color < 0)
			ft_exit_error("Double info inclusion", all);
	}
	if (all->parse.texture == 2)
	{
		if (all->parse.ceilling_color != -1)
			ft_exit_error("Double info inclusion", all);
		all->parse.ceilling_color = res;
		if (all->parse.ceilling_color < 0)
			ft_exit_error("Double info inclusion", all);
	}
}

static void	ft_color(char **str, t_all *all)
{
	int	color;
	int	res;

	color = check_colors(str, *all);
	res = color * 65536;
	ft_isspace(str);
	if (!(ft_comma(str)))
		ft_exit_error("Invalid color format", all);
	color = check_colors(str, *all);
	res = res + color * 256;
	ft_isspace(str);
	if (!(ft_comma(str)))
		ft_exit_error("Invalid color format", all);
	color = check_colors(str, *all);
	res = res + color;
	ft_color2(all, res);
}

void	parse_str(char *str, t_all *all, int *count)
{
	int	len;

	ft_isspace(&str);
	len = ft_strlen(str);
	if (check_texture(&(str), all))
		check_parse_path(&(str), all);
	else if (check_color(&(str), all))
		ft_color(&(str), all);
	else if (ft_strnstr(str, "R", len))
		make_res(&(str), all);
	ft_isspace(&str);
	if (*str == '\0')
		*count += 1;
	else
		ft_exit_error("Invalid configuration format", all);
}

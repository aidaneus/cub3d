#include "../includes/cub3d.h"

static int	space_or_end(int c)
{
	if (c == ' ' || c == '\0')
		return (1);
	return (0);
}

static void	check_out(int i, int j, t_all *all)
{
	if (map_check((all->parse.file)[i][j + 1]))
		ft_exit_error("Map not closed", all);
	if ((all->parse.file)[i + 1] &&
			ft_strlen((all->parse.file)[i + 1]) >= j &&
			map_check((all->parse.file)[i + 1][j]))
		ft_exit_error("Map not closed", all);
}

static void	check_in(int i, int j, t_all *all)
{
	if (i == 0 || j == ft_strlen((all->parse.file)[i])
				|| j == 0 || !(all->parse.file)[i + 1])
		ft_exit_error("Map not closed", all);
	if (ft_strlen((all->parse.file)[i - 1]) < (j + 1))
		ft_exit_error("Map not closed", all);
	if (space_or_end((all->parse.file)[i][j + 1]))
		ft_exit_error("Map not closed", all);
	if (ft_strlen((all->parse.file)[i + 1]) < (j + 1)
			|| space_or_end((all->parse.file)[i + 1][j]))
		ft_exit_error("Map not closed", all);
	if ((all->parse.file)[i][j] == '2')
		all->parse.sprite_count += 1;
	if (check_pl((all->parse.file)[i][j]))
	{
		if (all->parse.pl_dir)
			ft_exit_error("More then one player", all);
		all->parse.pl_dir = (all->parse.file)[i][j];
	}
}

static void	checker(char **map, t_all *all, int i, int j)
{
	if (map_check(map[i][j]))
		check_in(i, j, all);
	else if (map[i][j] == ' ')
		check_out(i, j, all);
	else if (map[i][j] != '1')
		ft_exit_error("Map symbol", all);
}

int	check_valid_map(char **map, t_all *all)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		if (map[i][j] == '\0')
			ft_exit_error("Map with empty line", all);
		while (map[i][j])
		{
			checker(map, all, i, j);
			j++;
		}
		i++;
	}
	if (all->parse.pl_dir == '\0')
		ft_exit_error("No player on map", all);
	return (1);
}

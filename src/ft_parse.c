#include "../includes/cub3d.h"

static void	check_sprites(t_all *all, int count,
		int x, int y)
{
	all->parse.sprites[count] = (t_sprite *)
		malloc(sizeof(t_sprite));
	if (!(all->parse.sprites[count]))
		ft_exit_error("Malloc error", all);
	all->parse.sprites[count]->x = (double)x + 0.5;
	all->parse.sprites[count]->y = (double)y + 0.5;
}

static void	init_sprites(t_all *all)
{
	int	y;
	int	x;
	int	count;

	y = 0;
	count = 0;
	all->parse.sprites = (t_sprite **)malloc(sizeof(t_sprite *)
			* (all->parse.sprite_count + 1));
	if (!all->parse.sprites)
		ft_exit_error("Malloc error", all);
	while (all->parse.file[y])
	{
		x = 0;
		while (all->parse.file[y][x])
		{
			if (all->parse.file[y][x] == '2')
				check_sprites(all, count++, x, y);
			x++;
		}
		y++;
	}
	all->parse.sprites[count] = NULL;
}

int	make_res(char **str, t_all *all)
{
	if (all->parse.res_w != -1 || all->parse.res_h != -1)
		ft_exit_error("Double info inclusion", all);
	*str = *str + 2;
	mlx_get_screen_size(&all->parse.width, &all->parse.height);
	all->parse.res_w = check_resolution(str, all);
	all->parse.res_h = check_resolution(str, all);
	if (all->parse.res_w <= 0)
		ft_exit_error("Invalid resolution", all);
	if (all->parse.res_h <= 0)
		ft_exit_error("Invalid resolution", all);
	if (all->parse.res_w > all->parse.width)
		all->parse.res_w = all->parse.width;
	if (all->parse.res_h > all->parse.height)
		all->parse.res_h = all->parse.height;
	return (0);
}

static char	**map_size(char **file, int map_pos, t_all *all)
{
	char	**map;
	int		filesize;
	int		count;

	filesize = 0;
	count = 0;
	while (file[filesize])
		filesize++;
	map = (char **)malloc(sizeof(char *) * (filesize - map_pos + 1));
	if (!(map))
		ft_exit_error("Malloc error1", all);
	while (file[map_pos])
	{
		map[count] = ft_strdup(file[map_pos]);
		if (!map[count])
		{
			free_file(map);
			ft_exit_error("Malloc error2", all);
		}
		map_pos++;
		count++;
	}
	map[count] = NULL;
	free_file(file);
	return (map);
}

void	ft_parse(t_all *all)
{
	int	count;

	count = 0;
	if ((all->parse.file)[count][0] == '\0')
		ft_exit_error("First line is empty", all);
	while (check_sym((all->parse.file)[count]))
		parse_str((all->parse.file)[count], all, &count);
	if (!check_if(*all))
		ft_exit_error("Not enough map information", all);
	all->parse.file = map_size(all->parse.file, count, all);
	check_valid_map(all->parse.file, all);
	init_sprites(all);
}

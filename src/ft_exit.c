#include "../includes/cub3d.h"
#include <sys/types.h>
#include <signal.h>

void	free_file(char **file)
{
	size_t	i;

	i = 0;
	if (file)
	{
		while (file[i])
		{
			free(file[i]);
			file[i++] = NULL;
		}
		free(file);
		file = NULL;
	}
}

static void	free_sprites(t_all *all)
{
	size_t	i;

	i = 0;
	if (all->parse.sprites)
	{
		while (all->parse.sprites[i])
		{
			free(all->parse.sprites[i]);
			all->parse.sprites[i++] = NULL;
		}
		free(all->parse.sprites);
		all->parse.sprites = NULL;
	}
}

void	free_parse(t_all *all)
{
	if (all->parse.no_tex_path)
		free(all->parse.no_tex_path);
	if (all->parse.we_tex_path)
		free(all->parse.we_tex_path);
	if (all->parse.so_tex_path)
		free(all->parse.so_tex_path);
	if (all->parse.ea_tex_path)
		free(all->parse.ea_tex_path);
	if (all->parse.sp_tex_path)
		free(all->parse.sp_tex_path);
	free_file(all->parse.file);
	free_sprites(all);
}

int	ft_exit_error(char *error, t_all *all)
{
	if (all->mlx.win)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	write(2, "Error\n", 6);
	write(2, error, ft_strlen(error));
	write(2, "\n", 1);
	free_parse(all);
	exit(1);
	return (1);
}

int	ft_exit(t_all *all)
{
	if (all->mlx.win)
		mlx_destroy_window(all->mlx.mlx, all->mlx.win);
	free_parse(all);
	exit(0);
	return (0);
}

#include "../includes/cub3d.h"
#include <sys/types.h>
int	p_key(int keycode, t_all *all)
{
	if (keycode == ESC_KEY)
		ft_exit(all);
	if (keycode == A)
		all->keys.a = 1;
	if (keycode == W)
		all->keys.w = 1;
	if (keycode == S)
		all->keys.s = 1;
	if (keycode == D)
		all->keys.d = 1;
	if (keycode == RIGHT)
		all->keys.r = 1;
	if (keycode == LEFT)
		all->keys.l = 1;
	return (0);
}

int	r_key(int keycode, t_all *all)
{
	if (keycode == A)
		all->keys.a = 0;
	if (keycode == W)
		all->keys.w = 0;
	if (keycode == S)
		all->keys.s = 0;
	if (keycode == D)
		all->keys.d = 0;
	if (keycode == RIGHT)
		all->keys.r = 0;
	if (keycode == LEFT)
		all->keys.l = 0;
	return (0);
}

void	preparing_cub(t_all *all, char *path)
{
	check_file(path, all);
	ft_parse(all);
	init_player(all);
	all->mlx.win = NULL;
	all->mlx.mlx = mlx_init();
	all->mlx.win = mlx_new_window(all->mlx.mlx,
			all->parse.res_w, all->parse.res_h, "cub3D");
	if (!(all->mlx.mlx))
		ft_exit_error("Can't start MLX", all);
	if (!(all->mlx.win))
		ft_exit_error("MLX can't open window", all);
}

void	check_args(int argc, char **argv, t_all *all)
{
	create_parse(all);
	if (argc == 1)
		ft_exit_error("Invalid first argument", all);
	if (argc >= 2)
	{
		if (!open(argv[1], O_RDONLY) || (search_sym(argv[1], ".cub\0") != 4))
			ft_exit_error("Invalid second argument", all);
	}
	if (argc > 3)
		ft_exit_error("Too many arguments", all);
	preparing_cub(all, argv[1]);
	if (argc == 3)
	{
		if (ft_memcmp(argv[2], "--save\0", 7) == 0)
			ft_bmp(all);
		else
			ft_exit_error("Invalid third argument", all);
	}
}

int	main(int argc, char **argv)
{
	t_all	all;

	check_args(argc, argv, &all);
	init_textures(&all);
	mlx_do_key_autorepeatoff(all.mlx.mlx);
	mlx_hook(all.mlx.win, 17, 0, ft_exit, &all);
	mlx_hook(all.mlx.win, 2, 0, p_key, &all);
	mlx_hook(all.mlx.win, 3, 0, r_key, &all);
	mlx_loop_hook(all.mlx.mlx, raycasting, &all);
	mlx_loop(all.mlx.mlx);
	return (0);
}

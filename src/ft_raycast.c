#include "../includes/cub3d.h"

int	check_pl(int c)
{
	if (c == 'N' || c == 'E'
		|| c == 'W' || c == 'S')
		return (1);
	return (0);
}

void	take_direction(t_all *all)
{
	if (all->parse.pl_dir == 'N')
	{
		all->render.player_dir.x = 0;
		all->render.player_dir.y = -1;
	}
	if (all->parse.pl_dir == 'S')
	{
		all->render.player_dir.x = 0;
		all->render.player_dir.y = 1;
	}
	if (all->parse.pl_dir == 'W')
	{
		all->render.player_dir.x = -1;
		all->render.player_dir.y = 0;
	}
	if (all->parse.pl_dir == 'E')
	{
		all->render.player_dir.x = 1;
		all->render.player_dir.y = 0;
	}
	all->render.plane.x = (cos(-1.5708) * all->render.player_dir.x
			- sin(-1.5708) * all->render.player_dir.y) * all->render.zoom;
	all->render.plane.y = (sin(-1.5708) * all->render.player_dir.x
			+ cos(-1.5708) * all->render.player_dir.y) * all->render.zoom;
}

void	init_player(t_all *all)
{
	char	**map;
	int		x;
	int		y;

	map = all->parse.file;
	all->render.zoom = ZOOM;
	y = 0;
	while ((all->parse.file)[y])
	{
		x = 0;
		while ((all->parse.file)[y][x])
		{
			if (check_pl((all->parse.file)[y][x]))
			{
				all->render.player_pos.x = (double)x + 0.5;
				all->render.player_pos.y = (double)y + 0.5;
			}
			x++;
		}
		y++;
	}
	take_direction(all);
}

void	move_player(t_all *all)
{
	if (all->keys.w == 0 && all->keys.a == 0 && all->keys.s == 0
		&& all->keys.d == 0 && all->keys.r == 0 && all->keys.l == 0)
		return ;
	move_ws(all);
	move_ad(all);
	move_right(all);
	move_left(all);
}

int	raycasting(t_all *all)
{
	int		x;
	double	dist_buff[4096];

	move_player(all);
	ft_floor_and_ceiling(0, 0, all);
	ft_floor_and_ceiling(0, all->parse.res_h / 2, all);
	x = 0;
	while (x < all->parse.res_w)
	{
		render_rays(all, x);
		ft_texture(all, x);
		dist_buff[x] = all->render.wall_to_plane;
		x++;
	}
	ft_sprites(all, dist_buff);
	if (all->mlx.win)
		mlx_put_image_to_window(all->mlx.mlx, all->mlx.win, all->mlx.img, 0, 0);
	return (0);
}

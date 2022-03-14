#include "../includes/cub3d.h"

int	no_wall(t_all *all, double dir, int param)
{
	if (param == 'x')
	{
		if (all->parse.file[(int)all->render.player_pos.y][(int)
			(all->render.player_pos.x + dir * SPEED - 0.1 * (dir < 0) + 0.1
				* (dir > 0))] == '0' || all->parse.file[(int)
					all->render.player_pos.y][(int)(all->render.player_pos.x
					+ dir * SPEED - 0.1 * (dir < 0) + 0.1 * (dir > 0))] == '2'
				|| check_pl(all->parse.file[(int)all->render.player_pos.y][(int)
				(all->render.player_pos.x + dir * SPEED - 0.1 * (dir < 0) + 0.1
				* (dir > 0))]))
			return (1);
	}
	if (param == 'y')
		if (all->parse.file[(int)(all->render.player_pos.y + dir * SPEED
				- 0.1 * (dir < 0) + 0.1 * (dir > 0))]
				[(int)all->render.player_pos.x] == '0'
				|| all->parse.file[(int)(all->render.player_pos.y + dir * SPEED
					- 0.1 * (dir < 0) + 0.1 * (dir > 0))]
				[(int)all->render.player_pos.x] == '2' ||
				check_pl(all->parse.file[(int)(all->render.player_pos.y +
						dir * SPEED - 0.1 * (dir < 0) + 0.1 * (dir > 0))]
				[(int)all->render.player_pos.x]))
			return (1);
	return (0);
}

void	move_ws(t_all *all)
{
	if (all->keys.w == 1 && all->keys.s != 1)
	{
		if (no_wall(all, all->render.player_dir.x, 'x'))
			all->render.player_pos.x += all->render.player_dir.x * SPEED;
		if (no_wall(all, all->render.player_dir.y, 'y'))
			all->render.player_pos.y += all->render.player_dir.y * SPEED;
	}
	if (all->keys.s == 1 && all->keys.w != 1)
	{
		if (no_wall(all, -all->render.player_dir.x, 'x'))
			all->render.player_pos.x -= all->render.player_dir.x * SPEED;
		if (no_wall(all, -all->render.player_dir.y, 'y'))
			all->render.player_pos.y -= all->render.player_dir.y * SPEED;
	}
}

void	move_ad(t_all *all)
{
	if (all->keys.a == 1 && all->keys.d != 1)
	{
		if (no_wall(all, all->render.plane.x, 'x'))
			all->render.player_pos.x += all->render.plane.x * SPEED;
		if (no_wall(all, all->render.plane.y, 'y'))
			all->render.player_pos.y += all->render.plane.y * SPEED;
	}
	if (all->keys.d == 1 && all->keys.a != 1)
	{
		if (no_wall(all, -all->render.plane.x, 'x'))
			all->render.player_pos.x -= all->render.plane.x * SPEED;
		if (no_wall(all, -all->render.plane.y, 'y'))
			all->render.player_pos.y -= all->render.plane.y * SPEED;
	}
}

void	move_right(t_all *all)
{
	double		old_dir_x;

	if (all->keys.r == 1 && all->keys.l != 1)
	{
		old_dir_x = all->render.player_dir.x;
		all->render.player_dir.x = all->render.player_dir.x * cos(SIDESPEED)
			- all->render.player_dir.y * sin(SIDESPEED);
		all->render.player_dir.y = old_dir_x * sin(SIDESPEED)
			+ all->render.player_dir.y * cos(SIDESPEED);
		all->render.plane.x = (cos(-1.5708) * all->render.player_dir.x
				- sin(-1.5708) * all->render.player_dir.y) * all->render.zoom;
		all->render.plane.y = (sin(-1.5708) * all->render.player_dir.x
				+ cos(-1.5708) * all->render.player_dir.y) * all->render.zoom;
	}
}

void	move_left(t_all *all)
{
	double		old_dir_x;

	if (all->keys.l == 1 && all->keys.r != 1)
	{
		old_dir_x = all->render.player_dir.x;
		all->render.player_dir.x = all->render.player_dir.x * cos(-SIDESPEED)
			- all->render.player_dir.y * sin(-SIDESPEED);
		all->render.player_dir.y = old_dir_x * sin(-SIDESPEED)
			+ all->render.player_dir.y * cos(-SIDESPEED);
		all->render.plane.x = (cos(-1.5708) * all->render.player_dir.x
				- sin(-1.5708) * all->render.player_dir.y) * all->render.zoom;
		all->render.plane.y = (sin(-1.5708) * all->render.player_dir.x
				+ cos(-1.5708) * all->render.player_dir.y) * all->render.zoom;
	}
}

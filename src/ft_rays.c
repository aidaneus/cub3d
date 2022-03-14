#include "../includes/cub3d.h"

static void	calc_line(t_all *all)
{
	all->render.line_height = (int)(all->parse.res_h
			/ all->render.wall_to_plane);
	all->render.draw_start = (all->parse.res_h
			- all->render.line_height) / 2;
	if (all->render.draw_start < 0)
		all->render.draw_start = 0;
	all->render.draw_end = (all->render.line_height
			+ all->parse.res_h) / 2;
	if (all->render.draw_end >= all->parse.res_h)
		all->render.draw_end = all->parse.res_h - 1;
}

static void	on_map(t_all *all)
{
	if (all->render.side == 0)
		all->render.wall_to_plane = (all->render.map.x
				- all->render.player_pos.x
				+ (1 - all->render.step.x) / 2) / all->render.ang.x;
	else
	{
		all->render.wall_to_plane = (all->render.map.y
				- all->render.player_pos.y
				+ (1 - all->render.step.y) / 2) / all->render.ang.y;
	}
	if (all->render.wall_to_plane == 0)
		all->render.wall_to_plane += 0.05;
}

static void	find_wall(t_all *all)
{
	if (all->parse.file[all->render.map.y][all->render.map.x] == '1')
		all->render.hit = 1;
	while (all->render.hit == 0)
	{
		if (all->render.side_dist.x < all->render.side_dist.y)
		{
			all->render.side_dist.x += all->render.delta_dist.x;
			all->render.map.x += all->render.step.x;
			all->render.side = 0;
		}
		else
		{
			all->render.side_dist.y += all->render.delta_dist.y;
			all->render.map.y += all->render.step.y;
			all->render.side = 1;
		}
		if (all->parse.file[all->render.map.y][all->render.map.x] == '1')
			all->render.hit = 1;
	}
}

static void	init_side_dist(t_all *all)
{
	if (all->render.ang.x < 0)
	{
		all->render.step.x = -1;
		all->render.side_dist.x = (all->render.player_pos.x
				- all->render.map.x) * all->render.delta_dist.x;
	}
	else
	{
		all->render.step.x = 1;
		all->render.side_dist.x = (all->render.map.x
				+ 1.0 - all->render.player_pos.x) * all->render.delta_dist.x;
	}
	if (all->render.ang.y < 0)
	{
		all->render.step.y = -1;
		all->render.side_dist.y = (all->render.player_pos.y
				- all->render.map.y) * all->render.delta_dist.y;
	}
	else
	{
		all->render.step.y = 1;
		all->render.side_dist.y = (all->render.map.y
				+ 1.0 - all->render.player_pos.y) * all->render.delta_dist.y;
	}
}

void	render_rays(t_all *all, int x)
{
	all->render.camera_x = 2 * (all->parse.res_w - x)
		/ (double)(all->parse.res_w) - 1;
	all->render.ang.x = all->render.player_dir.x
		+ all->render.plane.x * all->render.camera_x;
	all->render.ang.y = all->render.player_dir.y
		+ all->render.plane.y * all->render.camera_x;
	all->render.map.x = (int)all->render.player_pos.x;
	all->render.map.y = (int)all->render.player_pos.y;
	all->render.delta_dist.x = fabs(1 / all->render.ang.x);
	all->render.delta_dist.y = fabs(1 / all->render.ang.y);
	init_side_dist(all);
	all->render.hit = 0;
	find_wall(all);
	on_map(all);
	calc_line(all);
}

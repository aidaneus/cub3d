#include "../includes/cub3d.h"

static void	calc_draw_sprite2(t_all *all)
{
	all->render.draw_s.x = -all->render.sprite_width
		/ 2 + all->render.sprite_screen;
	if (all->render.draw_s.x < 0)
		all->render.draw_s.x = 0;
	all->render.draw_e.x = all->render.sprite_width
		/ 2 + all->render.sprite_screen;
	if (all->render.draw_e.x >= all->parse.res_w)
		all->render.draw_e.x = all->parse.res_w - 1;
}

static void	calc_draw_sprite(t_all *all)
{
	all->render.sprite_height = abs((int)(all->parse.res_h
				/ all->render.trans.y));
	all->render.sprite_width = abs((int)(all->parse.res_h
				/ all->render.trans.y));
	all->render.draw_s.y = (-all->render.sprite_height
			/ 2 + all->parse.res_h / 2);
	if (all->render.draw_s.y < 0)
		all->render.draw_s.y = 0;
	all->render.draw_e.y = (all->render.sprite_height
			/ 2 + all->parse.res_h / 2);
	if (all->render.draw_e.y >= all->parse.res_h)
		all->render.draw_e.y = all->parse.res_h - 1;
	calc_draw_sprite2(all);
}

static void	draw_sprite2(t_all *all, int y)
{
	all->render.tex_y = (int)((y - (all->parse.res_h
					- all->render.sprite_height) / 2)
			* all->textures.sp.height
			/ all->render.sprite_height);
	all->render.color = ((int *)all->textures.sp.addr)
	[all->textures.sp.height * all->render.tex_y
		+ all->render.tex_x];
}

static void	draw_sprite(t_all *all, double *dist_buff)
{
	int			x;
	int			y;

	x = all->render.draw_s.x;
	while (x < all->render.draw_e.x)
	{
		all->render.tex_x = (int)((x - (all->render.sprite_screen
						- all->render.sprite_width / 2))
				* all->textures.sp.width / all->render.sprite_width);
		if (all->render.trans.y > 0 && all->render.trans.y
			< dist_buff[x] && x > 0 && x < all->parse.res_w)
		{
			y = all->render.draw_s.y;
			while (y < all->render.draw_e.y)
			{
				draw_sprite2(all, y);
				if ((all->render.color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(&all->mlx, x, y, all->render.color);
				y++;
			}
		}
		x++;
	}
}

void	render_sprites(t_all *all, int count, double *dist_buff)
{
	double		invDet;

	invDet = 1.0 / (-all->render.plane.x * all->render.player_dir.y
			+ all->render.player_dir.x * all->render.plane.y);
	all->render.trans.x = invDet * (all->render.player_dir.y
			* all->parse.sprites[count]->width - all->render.player_dir.x
			* all->parse.sprites[count]->height);
	all->render.trans.y = invDet * (all->render.plane.y
			* all->parse.sprites[count]->width - all->render.plane.x
			* all->parse.sprites[count]->height);
	all->render.sprite_screen = (int)((all->parse.res_w / 2)
			* (1 + all->render.trans.x / all->render.trans.y));
	calc_draw_sprite(all);
	draw_sprite(all, dist_buff);
}

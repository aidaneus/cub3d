#include "../includes/cub3d.h"

static void	import_text(char *path, t_texture *textures, t_all *all)
{
	textures->img = mlx_xpm_file_to_image(all->mlx.mlx,
			path, &textures->width, &textures->height);
	if (textures->img == NULL)
		ft_exit_error("Can't open texture", all);
	textures->addr = mlx_get_data_addr(textures->img, &textures->pix,
			&textures->length, &textures->endian);
}

void	init_textures(t_all *all)
{
	all->mlx.img = mlx_new_image(all->mlx.mlx,
			all->parse.res_w, all->parse.res_h);
	all->mlx.addr = mlx_get_data_addr(all->mlx.img, &all->mlx.pix,
			&all->mlx.lenght, &all->mlx.endian);
	import_text(all->parse.no_tex_path, &all->textures.no, all);
	import_text(all->parse.ea_tex_path, &all->textures.ea, all);
	import_text(all->parse.we_tex_path, &all->textures.we, all);
	import_text(all->parse.so_tex_path, &all->textures.so, all);
	import_text(all->parse.sp_tex_path, &all->textures.sp, all);
}

static t_texture	*choose_texture(t_all *all)
{
	if (all->render.side == 1)
	{
		if (all->render.ang.y < 0)
			return (&all->textures.no);
		else
			return (&all->textures.so);
	}
	else
	{
		if (all->render.ang.x < 0)
			return (&all->textures.we);
		else
			return (&all->textures.ea);
	}
}

static void	render_texture(t_all *all, t_texture *drawn)
{
	if (all->render.side == 0)
		all->render.wall_x = all->render.player_pos.y
			+ all->render.wall_to_plane * all->render.ang.y;
	else
		all->render.wall_x = all->render.player_pos.x
			+ all->render.wall_to_plane * all->render.ang.x;
	all->render.wall_x -= floor(all->render.wall_x);
	all->render.tex_x = (int)(all->render.wall_x * (double)(drawn->width));
	if (all->render.side == 1 && all->render.ang.y > 0)
		all->render.tex_x = drawn->width - all->render.tex_x - 1;
	if (all->render.side == 0 && all->render.ang.x < 0)
		all->render.tex_x = drawn->width - all->render.tex_x - 1;
	all->render.draw_step = 1.0 * drawn->height / all->render.line_height;
	all->render.tex_pos = (all->render.draw_start - all->parse.res_h / 2
			+ all->render.line_height / 2) * all->render.draw_step;
}

void	ft_texture(t_all *all, int x)
{
	int				y;
	t_texture		*drawn;
	int				color;
	int				tex_y;

	drawn = choose_texture(all);
	render_texture(all, drawn);
	y = all->render.draw_start;
	while (y < all->render.draw_end)
	{
		if (all->render.tex_pos > ((double)drawn->height - 1))
			all->render.tex_pos = (double)drawn->height - 1;
		if (all->render.tex_pos < 0)
			all->render.tex_pos = 0;
		tex_y = (int)all->render.tex_pos;
		all->render.tex_pos += all->render.draw_step;
		color = ((int *)drawn->addr)[drawn->width * tex_y + all->render.tex_x];
		my_mlx_pixel_put(&all->mlx, x, y, color);
		y++;
	}
}

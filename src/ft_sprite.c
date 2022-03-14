#include "../includes/cub3d.h"

static void	sprite_distance(t_all *all)
{
	int				count;

	count = 0;
	while (all->parse.sprites[count])
	{
		all->parse.sprites[count]->width = -all->render.player_pos.x
			+ all->parse.sprites[count]->x;
		all->parse.sprites[count]->height = -all->render.player_pos.y
			+ all->parse.sprites[count]->y;
		all->parse.sprites[count]->dist = (-all->render.player_pos.x
				+ all->parse.sprites[count]->x)
			* (-all->render.player_pos.x + all->parse.sprites[count]->x)
			+ (-all->render.player_pos.y + all->parse.sprites[count]->y)
			* (-all->render.player_pos.y
				+ all->parse.sprites[count]->y);
		count++;
	}
}

static void	sort_sprites(t_all *all)
{
	int			i;
	int			j;
	t_sprite	*save;

	i = 0;
	while (i < all->parse.sprite_count - 1)
	{
		j = i + 1;
		while (j < all->parse.sprite_count)
		{
			if (all->parse.sprites[i]->dist < all->parse.sprites[j]->dist)
			{
				save = all->parse.sprites[i];
				all->parse.sprites[i] = all->parse.sprites[j];
				all->parse.sprites[j] = save;
			}
			j++;
		}
		i++;
	}
}

void	ft_sprites(t_all *all, double *dist_buff)
{
	int			count;

	count = 0;
	sort_sprites(all);
	sprite_distance(all);
	while (all->parse.sprites[count])
	{
		render_sprites(all, count, dist_buff);
		count++;
	}
}

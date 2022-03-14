#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->lenght + x * (mlx->pix / 8));
	*(unsigned int *)dst = color;
}

void	ft_floor_and_ceiling(int x, int y, t_all *all)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		color;

	i = x;
	width = all->parse.res_w;
	height = all->parse.res_h / 2;
	if (y == 0)
		color = all->parse.ceilling_color;
	else
		color = all->parse.floor_color;
	while (i < x + width)
	{
		j = y;
		while (j < y + height)
		{
			my_mlx_pixel_put(&all->mlx, i, j, color);
			j++;
		}
		i++;
	}
}

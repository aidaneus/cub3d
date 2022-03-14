#include "../includes/cub3d.h"

static void	*ft_calloc(size_t count, size_t size)
{
	char			*a;
	unsigned int	b;
	unsigned int	c;

	c = 0;
	b = count * size;
	a = malloc(b);
	if (!(a))
		return (NULL);
	while (b--)
	{
		a[c] = 0;
		c++;
	}
	return (a);
}

static void	img_to_bmp(t_all *all, int fd)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->parse.res_h)
	{
		x = 0;
		while (x < all->parse.res_w)
		{
			all->render.color = *(int *)(all->mlx.addr
					+ (y * all->mlx.lenght
						+ x * (all->mlx.pix / 8)));
			write(fd, &all->render.color, 4);
			x++;
		}
		y++;
	}
}

static char	*make_bmp(t_all *all, int fd)
{
	char	*bmp;

	bmp = (char *)ft_calloc(sizeof(char), 54);
	if (!(bmp))
	{
		close(fd);
		ft_exit_error("Malloc error", all);
	}
	bmp[0] = 'B';
	bmp[1] = 'M';
	*((int *)(bmp + 2)) = all->parse.res_h * all->parse.res_w * 4 + 54;
	*((int *)(bmp + 10)) = 54;
	*((int *)(bmp + 14)) = 40;
	*((int *)(bmp + 18)) = all->parse.res_w;
	*((int *)(bmp + 22)) = -all->parse.res_h;
	*(bmp + 26) = 1;
	*(bmp + 28) = 32;
	return (bmp);
}

void	ft_bmp(t_all *all)
{
	int			fd;
	char		*bmp;

	fd = open("screen.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	init_textures(all);
	raycasting(all);
	if (fd == -1)
	{
		close(fd);
		ft_exit_error("Can't create bmp file", all);
	}
	bmp = (char *)make_bmp(all, fd);
	write(fd, bmp, 54);
	free(bmp);
	img_to_bmp(all, fd);
	close(fd);
	ft_exit(all);
}

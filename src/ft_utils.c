#include "../includes/cub3d.h"

char	*check_size(char **s1, t_all all)
{
	char	*str;
	int		i;
	int		len;

	len = 0;
	i = 0;
	while ((*s1)[i] && (*s1)[i] != ' ')
	{
		i++;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		ft_exit_error("Malloc error", &all);
	str[len] = '\0';
	i = 0;
	while (len-- > 0)
	{
		str[i] = **s1;
		*s1 += 1;
		i++;
	}
	return (str);
}

void	create_parse(t_all *all)
{
	all->parse.texture = -1;
	all->parse.res_w = -1;
	all->parse.res_h = -1;
	all->parse.floor_color = -1;
	all->parse.ceilling_color = -1;
	all->parse.pl_dir = '\0';
	all->parse.sprite_count = 0;
	all->parse.file = NULL;
	all->parse.sprites = NULL;
	all->parse.no_tex_path = NULL;
	all->parse.we_tex_path = NULL;
	all->parse.so_tex_path = NULL;
	all->parse.ea_tex_path = NULL;
	all->parse.sp_tex_path = NULL;
	all->keys.a = 0;
	all->keys.w = 0;
	all->keys.s = 0;
	all->keys.d = 0;
	all->keys.r = 0;
	all->keys.l = 0;
}

int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)buf1;
	b = (unsigned char *)buf2;
	if (buf1 == buf2 || count == 0)
		return (0);
	while (count--)
	{
		if (*a != *b)
			return (*a - *b);
		a++;
		b++;
	}
	return (0);
}

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	unsigned int	b;
	size_t			a;

	a = 0;
	if (!*n)
		return ((char *)h);
	while (h[a] != '\0' && a < l)
	{
		if (h[a] == n[0])
		{
			b = 1;
			while (n[b] != '\0' && h[a + b] == n[b] && (size_t)(a + b) < l)
				b++;
			if (n[b] == '\0')
				return ((char *)&h[a]);
		}
		else
			break ;
		a++;
	}
	return (0);
}

void	ft_isspace(char **str)
{
	if (str && *str)
	{
		while (**str == ' ')
			*str += 1;
	}
}

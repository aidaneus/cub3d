#include "../includes/cub3d.h"

char	**convert(t_list **begin, int size, t_all *all)
{
	int		count;
	t_list	*tmp;
	char	**file;

	count = 0;
	file = (char **)malloc(sizeof(char *) * (size + 1));
	if (!(file))
	{
		ft_lstclear(begin, free);
		ft_exit_error("Malloc error3", all);
	}
	tmp = *begin;
	while (tmp)
	{
		file[count] = ft_strdup(tmp->content);
		if (!(file[count]))
			ft_exit_error("Malloc error4", all);
		tmp = tmp->next;
		count++;
	}
	file[count] = NULL;
	return (file);
}

int	search_sym(char *argv, char *c)
{
	size_t	a;
	size_t	b;
	size_t	d;
	int		r;

	a = ft_strlen(argv);
	b = 0;
	d = 0;
	r = 0;
	while (argv[b] && b < a)
	{
		if (argv[b] == c[d])
		{
			r++;
			d++;
		}
		b++;
	}
	return (r);
}

static void	check_file2(t_list *param, t_list *tmp, int fd, t_all *all)
{
	ft_lstadd_back(&param, tmp);
	close(fd);
	all->parse.file = convert(&param, ft_lstsize(param), all);
	ft_lstclear(&param, free);
}

void	check_file(char *map, t_all *all)
{
	int		fd;
	char	*line;
	t_list	*tmp;
	t_list	*param;
	int		output;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		ft_exit_error("Can't open map", all);
	output = get_next_line(fd, &line);
	while (output > 0)
	{
		tmp = ft_lstnew(line);
		if (!(tmp))
			ft_exit_error("Malloc failed", all);
		ft_lstadd_back(&param, tmp);
		output = get_next_line(fd, &line);
	}
	if (output == -1)
		ft_exit_error("GNL failed", all);
	tmp = ft_lstnew(line);
	if (!(tmp))
		ft_exit_error("Malloc failed", all);
	check_file2(param, tmp, fd, all);
}

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "../opengl/mlx.h"

# define ESC_KEY 53
# define LEFT 123
# define RIGHT 124
# define A 0
# define S 1
# define D 2
# define W 13
# define SPEED 0.1
# define SIDESPEED 0.05
# define ZOOM 0.6

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*addr;
	int				pix;
	int				lenght;
	int				endian;
}					t_mlx;
typedef struct s_double_ray
{
	double			x;
	double			y;
}					t_double_ray;
typedef struct s_sprite
{
	double			x;
	double			y;
	double			width;
	double			height;
	double			dist;
}					t_sprite;
typedef struct s_parse
{
	int				texture;
	int				width;
	int				height;
	int				res_w;
	int				res_h;
	int				floor_color;
	int				ceilling_color;
	int				ceilling_color_res;
	char			*no_tex_path;
	char			*we_tex_path;
	char			*so_tex_path;
	char			*ea_tex_path;
	char			*sp_tex_path;
	char			**file;
	char			pl_dir;
	int				sprite_count;
	t_sprite		**sprites;
	char			**sprites_dist;
}					t_parse;
typedef struct s_int_dot
{
	int				x;
	int				y;
}					t_x_y;
typedef struct s_render
{
	t_double_ray	ang;
	t_double_ray	plane;
	double			camera_x;
	t_double_ray	delta_dist;
	t_double_ray	side_dist;
	double			wall_to_plane;
	int				line_height;
	t_x_y			map;
	t_x_y			step;
	double			zoom;
	t_double_ray	player_dir;
	t_double_ray	player_pos;
	int				hit;
	int				side;
	int				draw_start;
	int				draw_end;
	double			wall_x;
	double			draw_step;
	double			tex_pos;
	t_double_ray	trans;
	t_x_y			draw_s;
	t_x_y			draw_e;
	int				sprite_height;
	int				sprite_width;
	int				sprite_screen;
	int				tex_x;
	int				tex_y;
	int				color;
}					t_render;
typedef struct s_texture
{
	void			*img;
	void			*addr;
	int				width;
	int				height;
	int				pix;
	int				length;
	int				endian;
}					t_texture;
typedef struct s_textures
{
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		sp;
}					t_textures;
typedef struct s_key_status
{
	char			w;
	char			s;
	char			a;
	char			d;
	char			l;
	char			r;
}					t_key_status;
typedef struct s_music
{
	int				pid;
}	t_music;
typedef struct s_all
{
	t_parse			parse;
	t_mlx			mlx;
	t_render		render;
	t_textures		textures;
	t_key_status	keys;
	t_sprite		sprite;
	t_texture		texture;
	t_music			music;
}					t_all;
void	ft_parse(t_all *all);
void	create_parse(t_all *all);
void	parse_str(char *str,
			t_all *all, int *ptr_count);
int		make_res(char **str, t_all *all);
char	*check_size(char **s1, t_all all);
int		check_resolution(char **str, t_all *all);
int		check_colors(char **str, t_all all);
void	check_args(int argc, char **argv, t_all *all);
void	check_file(char *map, t_all *all);
int		check_sym(char *file_str);
int		check_valid_map(char **map, t_all *all);
int		check_pl(int c);
int		check_if(t_all all);
int		ft_comma(char **str);
void	free_parse(t_all *all);
void	free_file(char **file);
void	ft_bmp(t_all *all);
int		search_sym(char *argv, char *c);
void	preparing_cub(t_all *all, char *path);
void	ft_init(t_all *all);
void	check_parse_path(char **str, t_all *all);
void	init_textures(t_all *all);
int		ft_exit_error(char *error, t_all *all);
int		ft_exit(t_all *all);
int		p_key(int keycode, t_all *all);
int		r_key(int keycode, t_all *all);
void	move_player(t_all *all);
int		no_wall(t_all *all, double dir, int axis);
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
void	ft_floor_and_ceiling(int x, int y, t_all *all);
int		raycasting(t_all *all);
void	init_keys(t_key_status *keys);
void	move_left(t_all *all);
void	move_right(t_all *all);
void	move_ad(t_all *all);
void	move_ws(t_all *all);
void	init_player(t_all *all);
int		map_check(int c);
void	ft_isspace(char **str);
void	take_direction(t_all *all);
void	render_rays(t_all *all, int x);
void	ft_texture(t_all *all, int x);
void	ft_sprites(t_all *all, double *dist_buff);
char	**convert(t_list **begin, int size, t_all *all);
void	ft_lstadd_back(t_list **lst, t_list *new);
int		ft_isdigit(int c);
int		ft_memcmp(const void *buf1, const void *buf2, size_t count);
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstnew(void *content);
char	*ft_strnstr(const char *h, const char *n, size_t l);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	render_sprites(t_all *all, int count, double *dist_buff);

#endif
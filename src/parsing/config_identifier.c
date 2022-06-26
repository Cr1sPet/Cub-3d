#include "parsing.h"
#include "get_next_line.h"

void	init_texture(char *path, t_parse *parse, t_texture **texture1)
{
	t_texture	*texture;

	texture = (t_texture *) malloc(sizeof(t_texture));
	if (NULL == texture)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	texture->img = mlx_xpm_file_to_image(parse->cub->lib_mlx->mlx, path,
			&texture->width, &texture->height);
	if (NULL == texture->img)
		exit_with_error_parse("ERROR\nTexture file reading has failed", parse);

	texture->data_addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel,
						&texture->line_length, &texture->endian);

	if (NULL == texture->data_addr)
		exit_with_error_parse("ERROR\nMLX get data addr failed", parse);

	ft_putendl_fd("Success : init ", 1);

	*texture1 = texture;
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}


void	init_color(char *rgb, t_parse *parse, int	*color)
{
	int		*colors;
	char	**splitted;

	splitted = ft_split(rgb, ',');
	if (NULL == splitted)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	colors = (int *)malloc(sizeof(int) * 3);
	if (NULL == colors)
	{
		str_2d_clean(splitted, len_2d_str(splitted));
		exit_with_error_parse(MALLOC_FAILURE, parse);
	}
	colors[0] = parse_int(splitted[0]);
	colors[1] = parse_int(splitted[1]);
	colors[2] = parse_int(splitted[2]);

	if (-1 == colors[0] || -1 == colors[1] || -1 == colors[2])
	{
		free(colors);
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	}
	*color = create_rgb(colors[0], colors[1], colors[2]);
	str_2d_clean(splitted, len_2d_str(splitted));
	free(colors);
}


int	check_i(int i, t_parse *parse)
{
	if (0 == i)
		parse->config_count++;
	if (i == 1)
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	i = 1;
	return  (0);
}

void	init_no(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init NO", 1);
	init_texture(path, parse, &parse->cub->config->no_texture);
}

void	init_so(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;

	ft_putendl_fd("init SO", 1);
	init_texture(path, parse, &parse->cub->config->so_texture);
}

void	init_we(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;

	ft_putendl_fd("init WE", 1);
	init_texture(path, parse, &parse->cub->config->we_texture);

}

void	init_ea(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init EA", 1);
	init_texture(path, parse, &parse->cub->config->ea_texture);
}

void	init_f(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init F", 1);
	init_color(path, parse, &parse->cub->config->f);

}

void	init_c(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init C", 1);
	init_color(path, parse, &parse->cub->config->c);
}
void	set_config_funcs(t_parse *parse)
{
	parse->config_init[0] = init_no;
	parse->config_init[1] = init_so;
	parse->config_init[2] = init_we;
	parse->config_init[3] = init_ea;
	parse->config_init[4] = init_f;
	parse->config_init[5] = init_c;
}

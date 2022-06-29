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
	texture->data_addr = mlx_get_data_addr(texture->img, \
		&texture->bits_per_pixel, \
		&texture->line_length, &texture->endian);
	if (NULL == texture->data_addr)
		exit_with_error_parse("ERROR\nMLX get data addr failed", parse);
	ft_putendl_fd("Success : init ", 1);
	*texture1 = texture;
}

int	check_i(int i, t_parse *parse)
{
	if (0 == i)
		parse->config_count++;
	if (i == 1)
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	i = 1;
	return (0);
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
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init SO", 1);
	init_texture(path, parse, &parse->cub->config->so_texture);
}

void	init_we(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init WE", 1);
	init_texture(path, parse, &parse->cub->config->we_texture);
}

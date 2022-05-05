#include "parsing.h"
#include "get_next_line.h"

void	init_texture(char *path, t_parse *parse, char *texture)
{

	// fd = open(path, O_RDONLY);
	// if (-1 == fd)
	// 	exit_with_error_parse(strerror(), parse);
	// parse->map->config->no = get_next_line(fd, parse);
	// close (fd);
	ft_putendl_fd("Success : init ", 1);
	ft_putendl_fd(texture, 1);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
}

void	init_no (char *path, t_parse *parse)
{
	ft_putendl_fd("hhiohh", 2);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
	// init_texture(path, parse, parse->map->config->no);
}

void	init_so (char *path, t_parse *parse)
{
	init_texture(path, parse, parse->map->config->so);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
}

void	init_we (char *path, t_parse *parse)
{
	init_texture(path, parse, parse->map->config->we);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
}

void	init_ea (char *path, t_parse *parse)
{
	init_texture(path, parse, parse->map->config->ea);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
}

void	init_f (char *path, t_parse *parse)
{
	ft_putendl_fd("init F", 1);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
}

void	init_c (char *path, t_parse *parse)
{
	ft_putendl_fd("init C", 1);
	ft_putendl_fd(path, 1);
	ft_putendl_fd(parse->input_data->content, 1);
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

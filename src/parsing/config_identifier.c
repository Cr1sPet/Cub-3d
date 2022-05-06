#include "parsing.h"
#include "get_next_line.h"

void	init_texture(char *path, t_parse *parse, char **texture)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (-1 == fd)
		exit_with_error_parse("ERROR WITH FILE", parse);
	*texture = get_next_line(fd, parse);
	close (fd);
	ft_putendl_fd("Success : init ", 1);
}

void	init_color(char *path, t_parse *parse, char	**color)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (-1 == fd)
		exit_with_error_parse("ERROR WITH FILE", parse);
	*color = get_next_line(fd, parse);
	close (fd);
	ft_putendl_fd("Success : init ", 1);
}
int	check_i(int i, t_parse *parse)
{
	if (0 == i)
		parse->config_count++;
	if (i == 1)
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	i = 1;
}

void	init_no(char *path, t_parse *parse)
{
	static int	i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init NO", 1);
	init_texture(path, parse, &parse->cub->config->no);
}

void	init_so(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;

	ft_putendl_fd("init SO", 1);
	init_texture(path, parse, &parse->cub->config->so);
}

void	init_we(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;

	ft_putendl_fd("init WE", 1);
	init_texture(path, parse, &parse->cub->config->we);

}

void	init_ea(char *path, t_parse *parse)
{
	static int i = 0;

	check_i(i, parse);
	i = 1;
	ft_putendl_fd("init EA", 1);
	init_texture(path, parse, &parse->cub->config->ea);
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

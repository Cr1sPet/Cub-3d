#include "parsing.h"

int	check_config(char **config, struct s_parse *parse)
{
	int	i;

	i = 0;
	while (parse->config_names[i])
	{
		ft_putendl_fd(config[1], 1);
		if (!ft_strcmp(parse->config_names[i], config[0]))
		{
			(*parse->config_init[i])(config[1], parse);
			// init_no(config[1], parse);
			// init_texture(config[1], parse, parse->map->config->no);
			return (1);
		}
		i++;
	}
	return (0);
}

// void	valid_config_str(char **config, t_parse *parse)
// {
// 	int	fd;


// }

int	ends_with(char *input, char *postfix)
{
	int		ok;
	char	*end;

	if (ft_strlen(input) - ft_strlen(postfix) < 1)
		return (0);
	end = ft_substr(input, ft_strlen(input) - 4, ft_strlen(input));
	if (NULL == end)
	{
		ft_putendl_fd(MALLOC_FAILURE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ok = 1;
	if (ft_strcmp(end, postfix))
		ok = 0;
	free(end);
	return (ok);
}

void	valid_filename(int argc, char **argv)
{
	if (2 != argc)
	{
		ft_putendl_fd(NUMBER_ARGS_FAILURE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (!ends_with(argv[1], FILE_TYPE))
	{
		ft_putendl_fd(FILE_FORMAT_FAILURE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd("SUCCESS : File format ok", 1);
}

// void	valid_
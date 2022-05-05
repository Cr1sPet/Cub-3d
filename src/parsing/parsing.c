#include "parsing.h"
#include "get_next_line.h"


char	**make_map(char *arg)
{
	// char	  **map = ft_calloc(ft_lstsize(list) + 1, sizeof(char *));
	// int		  i = -1;

	// while (list)
	// {
	// 	map[++i] = list->content;
	// 	list= list->next;
	// }
	// i = -1;
	// while (map[++i])
	// 	ft_putendl_fd(map[i], 1);
	// return (map);
}

t_list	*read_info(char	*file_name, t_parse *parse)
{
	int		fd;
	t_list	*list;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (-1 == fd)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	line = NULL;
	list = NULL;
	line = get_next_line(fd, parse);
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
		line = get_next_line(fd, parse);
	}
	ft_lstadd_back(&list, NULL);
	close(fd);
	parse->fd_opened = 0;
	return (list);
}

void	parse_config(t_parse *parse)
{
	while (parse->input_data)
	{
		if (parse->input_data->content != "")
		{
			parse->trimmed_str = ft_strtrim(parse->input_data->content, " ");
			if (!parse->trimmed_str)
				exit_with_error_parse(MALLOC_FAILURE, parse);
			parse->splitted_str = ft_split(parse->trimmed_str, ' ');
			if (!parse->splitted_str)
				exit_with_error_parse(MALLOC_FAILURE, parse);
			if (2 != len_2d_str(parse->splitted_str))
				exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
			str_2d_clean(parse->splitted_str, len_2d_str(parse->splitted_str));
			ft_putendl_fd(parse->splitted_str[0], 1);
			parse->splitted_str = NULL;
			free(parse->splitted_str);
			parse->splitted_str = NULL;
		}
		parse->input_data = parse->input_data->next;
	}
}

void	init_parse(t_parse *parse)
{
	parse->fd_opened = 0;
	parse->input_data = NULL;
	parse->trimmed_str = NULL;
	parse->map = NULL;
}

char	**parsing(int argc, char **argv, t_map_info *map)
{
	t_parse	parse;

	init_parse(&parse);
	valid_filename(argc, argv);
	parse.input_data = read_info(argv[1], &parse);
	ft_putendl_fd(parse.input_data->content, STDOUT_FILENO);
	parse_config(&parse);
	clean_list(parse.input_data);
	return (NULL);
}

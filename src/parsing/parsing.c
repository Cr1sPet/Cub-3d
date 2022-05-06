#include "parsing.h"
#include "get_next_line.h"


// char	**make_map(char *arg)
// {
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
// }

t_list	*read_info(char	*file_name, t_parse *parse)
{
	t_list	*list;
	char	*line;

	parse->fd = open(file_name, O_RDONLY);
	if (-1 == parse->fd)
	{
		perror("Error");
		exit_with_error_parse("FILE ERROR", parse);
	}
	parse->fd_opened = 1;
	line = NULL;
	list = NULL;
	line = get_next_line(parse->fd, parse);
	while (line)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
		line = get_next_line(parse->fd, parse);
	}
	ft_lstadd_back(&list, NULL);
	close(parse->fd);
	parse->fd_opened = 0;
	return (list);
}


int	parse_config(t_parse *parse)
{
	while (parse->curent_data && 10 != parse->status)
	{
		parse->trimmed_str = ft_strtrim(parse->curent_data->content, " \n");
		if (parse->trimmed_str && parse->trimmed_str[0])
		{
			if (!parse->trimmed_str)
				exit_with_error_parse(MALLOC_FAILURE, parse);
			parse->splitted_str = ft_split(parse->trimmed_str, ' ');
			if (!parse->splitted_str)
				exit_with_error_parse(MALLOC_FAILURE, parse);
			if (2 != len_2d_str(parse->splitted_str))
				exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
			check_config(parse->splitted_str, parse);
			str_2d_clean(parse->splitted_str, len_2d_str(parse->splitted_str));
			parse->splitted_str = NULL;
		}
		free(parse->trimmed_str);
		parse->trimmed_str = NULL;
		parse->curent_data = parse->curent_data->next;
	}
	return (parse->status);
}

t_cub	*parsing(int argc, char **argv)
{
	t_parse		*parse;
	t_cub		*cub;
	int			ret;

	valid_filename(argc, argv);
	parse = init_parse();
	parse->input_data = read_info(argv[1], parse);
	parse->curent_data = parse->input_data;
	ret = parse_config(parse);
	if (0 == ret && parse->config_count < 6)
		exit_with_error_parse(CONFIG_INFO_FAILURE, parse);
	if (10 == ret)
		ft_putendl_fd("SUCCESS : parse confingure - OK", 1);
	// parse_map(parse);
	clean_list(parse->input_data);
	str_2d_clean(parse->config_names, len_2d_str(parse->config_names));
	cub = parse->cub;
	free(parse);
	return (cub);
}

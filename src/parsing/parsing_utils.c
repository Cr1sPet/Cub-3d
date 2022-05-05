#include "parsing.h"

int ft_strcmp( const char *str1, const char *str2 )
{
	  while( (*str1) && ( *str1 == *str2 ) )
	  {
		  str1++;
		  str2++;
	  }
	  if( *(unsigned char*)str1 > *(unsigned char*)str2 )
		  return 1;
	 else if( *(unsigned char*)str1 < *(unsigned char*)str2 )
		 return -1;
	 else
		 return 0;
}

t_parse	*init_parse(void)
{
	t_parse	*parse;

	parse = (t_parse *)malloc(sizeof(t_parse));
	parse->map = (t_map_info *)malloc(sizeof(t_map_info));
	parse->map->config = (t_config *)malloc(sizeof(t_config));
	parse->config_count = 0;
	parse->status = 2;
	parse->fd_opened = 0;
	parse->input_data = NULL;
	parse->trimmed_str = NULL;
	parse->splitted_str = NULL;
	parse->config_names =  ft_split("NO SO WE EA F C", ' ');
	set_config_funcs(parse);
	return(parse);
}


void	clean_list(t_list *list)
{
	t_list	*temp_list;

	while (list)
	{
		temp_list = list->next;
		free(list->content);
		free (list);
		list = temp_list;
	}
}

void	exit_with_error_parse(char *error, t_parse *parse)
{
	if (parse->fd_opened)
	{
		close(parse->fd);
	}
	if (parse->trimmed_str)
	{
		free(parse->trimmed_str);
	}
	if (parse->splitted_str)
	{
		str_2d_clean(parse->splitted_str, len_2d_str(parse->splitted_str));
	}
	clean_list(parse->input_data);
	str_2d_clean(parse->config_names, len_2d_str(parse->config_names));
	free(parse->map->config);
	free(parse->map);
	free(parse);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

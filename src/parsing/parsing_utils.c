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
	parse->cub = init_cub(parse);
	parse->cub->config = (t_config *)malloc(sizeof(t_config));
	init_config(parse->cub->config);
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

void	clean_parse_inner(t_parse *parse)
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
}

void	exit_with_error_parse(char *error, t_parse *parse)
{
	clean_parse_inner(parse);
	clean_cub(parse->cub);
	free(parse);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	init_config(t_config *conf)
{
	conf->width = 200;
	conf->height = 200;
	conf->no_img = NULL;
	conf->so_img = NULL;
	conf->we_img = NULL;
	conf->ea_img = NULL;
	conf->f = 0;
	conf->c = 0;
}

t_mlx	*lib_mlx_init(t_parse *parse)
{
	t_mlx	*lib_mlx;

	lib_mlx = (t_mlx *)malloc(sizeof(t_mlx));
	// if (NULL == lib_mlx)
	// 	exit_with_error_parse(MALLOC_FAILURE, parse);
	lib_mlx->mlx = mlx_init();
	if (NULL == lib_mlx->mlx)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	return (lib_mlx);
}

t_cub	*init_cub(t_parse *parse)
{
	t_cub	*cub;

	cub	= (t_cub *)malloc(sizeof(t_cub));
	if (NULL == cub)
	{
		ft_putendl_fd(MALLOC_FAILURE, STDERR_FILENO);
		exit(1);
	}
	cub->map = NULL;
	cub->pers = (t_pers_pos *) malloc(sizeof(t_pers_pos));
	cub->lib_mlx = lib_mlx_init(parse);
	cub->config = NULL;
	cub->pers->side = 0;
	return (cub);
}

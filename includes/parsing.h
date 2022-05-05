#ifndef PARSING_H
# define PARSING_H

# include "./cub3d.h"

# define FILE_TYPE ".cub"
# define CONFIG_INFO_FAILURE "Error\nInvalid configuration info."
# define FILE_FORMAT_FAILURE "Error\nInvalid file format. Expected : *.cub."
# define NUMBER_ARGS_FAILURE "Error\nInvalid number of arguments! Excpected : 2."

typedef struct s_parse
{
	int			fd_opened;
	int         fd;
	t_list      *input_data;
	t_list		*curent_data;
	t_map_info  *map;
	char		*trimmed_str;
	char		**splitted_str;
	void		(*config_init[6])(char *, struct s_parse *);
	char		**config_names;
}               t_parse;


void	init_no (char *path, t_parse *parse);
void	init_so (char *path, t_parse *parse);
void	init_we (char *path, t_parse *parse);
void	init_ea (char *path, t_parse *parse);
void	init_f (char *path, t_parse *parse);
void	init_c (char *path, t_parse *parse);

char	**make_map(char *arg);
int		ft_strcmp( const char *str1, const char *str2 );
void	valid_filename(int argc, char **argv);
void	clean_list(t_list *list);
void	exit_with_error_parse(char *error, t_parse *parse);
t_parse	*init_parse(void);
void	valid_config_str(char *str, t_parse *parse);
int		check_config(char **config, t_parse *parse);
void	set_config_funcs(t_parse *parse);
void	init_texture(char *path, t_parse *parse, char *texture);

#endif
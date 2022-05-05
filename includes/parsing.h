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
	t_map_info  *map;
	char		*trimmed_str;
	char		**splitted_str;
}               t_parse;


char	**make_map(char *arg);
int		ft_strcmp( const char *str1, const char *str2 );
void	valid_filename(int argc, char **argv);
void	clean_list(t_list *list);
void	exit_with_error_parse(char *error, t_parse *parse);

#endif
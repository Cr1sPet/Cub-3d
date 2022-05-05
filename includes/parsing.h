#ifndef PARSING_H
# define PARSING_H

# include "./cub3d.h"

# define FILE_TYPE ".cub"
# define FILE_FORMAT_FAILURE "Error\nInvalid file format. Expected : *.cub"
# define NUMBER_ARGS_FAILURE "Error\nInvalid number of arguments! Excpected : 2"

char	**make_map(char *arg);
int		ft_strcmp( const char *str1, const char *str2 );
void	validation(int argc, char **argv);

#endif
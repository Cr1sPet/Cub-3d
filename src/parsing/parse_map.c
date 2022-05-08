#include "parsing.h"

int	list_contains(t_list *list, int i)
{
	int	temp = 0;
	while (list)
	{
		temp = *((int *)list->content);
		if ( temp == i)
			return (1);
		list = list->next;
	}
	return (0);
}

void	print(t_list *list)
{
	while (list)
	{
		int	temp = *((int *) (list->content));
		ft_putnbr_fd(temp, 1);
		ft_putendl_fd("", 1);
		list = list->next;
	}
}

int	*ft_nmbdup(int a)
{
	int	*ret;

	ret = (int *)malloc(sizeof(int));
	*ret = a;
	return (ret);
}

int	check_top_to_bottom(char **map, t_parse *parse)
{
	int		i;
	int		j;
	t_list	*filler;

	i = -1;
	filler = NULL;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if ('0' == map[i][j])
			{
				if (!list_contains(filler, j))
					exit_with_error_parse(MAP_FAILURE, parse);
			}
			else if ('1' == map[i][j])
			{
				if (!list_contains(filler, j))
					ft_lstadd_front (&filler, ft_lstnew((void *) ft_nmbdup(j)));
			}
		}
	}
	clean_list(filler);
	return (0);
}

int	check__bottom_to_top(char **map, t_parse *parse)
{
	int		i;
	int		j;
	t_list	*filler;

	i = len_2d_str(map);
	filler = NULL;
	while (--i >= 0)
	{
		j = -1;
		while (map[i][++j])
		{
			if ('0' == map[i][j])
			{
				if (!list_contains(filler, j))
					exit_with_error_parse(MAP_FAILURE, parse);
			}
			else if ('1' == map[i][j])
			{
				if (!list_contains(filler, j))
					ft_lstadd_front (&filler, ft_lstnew((void *) ft_nmbdup(j)));
			}
		}
	}
	clean_list(filler);
	return (0);
}

typedef struct s_map_data
{
	char	**map;
	int		left_border;
	int		right_border;
	t_list	*filler;

}				t_map_data;

int	ft_isallone(const char *str)
{
	while (*str)
	{
		if ('1' != *str && ' ' != *str)
			return (0);
		str++;
	}
	return (1);
}

int	check_borders(char *str, t_parse *parse)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] != '1')
	{
		if ('0' == str[i])
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	if (i == (int) ft_strlen(str))
		exit_with_error_parse(MAP_FAILURE, parse);
	i = (int) ft_strlen(str);
	while (--i >= 0 && str[i] != '1')
	{
		if ('0' == str[i])
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	if (i == -1)
		exit_with_error_parse(MAP_FAILURE, parse);
	return (0);
}

int	parse_map(t_parse *parse)
{
	int			i;
	char		**map;

	i = -1;
	parse->cub->map = list_to2darr(parse->curent_data, parse);
	map = parse->cub->map;
	firstly_parse(map, parse);
	while (map[++i])
		check_borders(map[i], parse);
	check_top_to_bottom(map, parse);
	check__bottom_to_top(map, parse);
	ft_putendl_fd("MAP OK", 1);
	return (1);
}

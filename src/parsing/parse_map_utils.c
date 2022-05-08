#include "parsing.h"

static void	init_perse(char ch, int i, int j, t_parse *parse)
{
	static int	flag = 0;

	if (1 == flag)
		exit_with_error_parse(NUMBER_CHAR_FAILURE, parse);
	flag = 1;
	if ('N' == ch)
		parse->cub->pers->side = 'N';
	else if ('W' == ch)
		parse->cub->pers->side = 'W';
	else if ('E' == ch)
		parse->cub->pers->side = 'E';
	else if ('S' == ch)
		parse->cub->pers->side = 'S';
	parse->cub->pers->x = i;
	parse->cub->pers->x = j;
}

int	is_pers(char ch)
{
	if ('N' == ch || 'W' == ch || 'E' == ch || 'S' == ch)
		return (1);
	return (0);
}

int	check_space_sym(char **map, int i, int j)
{
	if (i != 0 && (map[i - 1][j] == '0'
		|| is_pers(map[i - 1][j])))
		return (0);
	if (i != len_2d_str(map) - 1 && (map[i + 1][j] == '0'
		|| is_pers(map[i + 1][j])))
		return (0);
	if (j != 0 && (map[i][j + 1] == '0'
		|| is_pers(map[i][j + 1])))
		return (0);
	if (j != ft_strlen(map[i]) - 1 && (map[i][j - 1] == '0'
		|| is_pers(map[i][j - 1])))
		return (0);
	return (1);
}

static void	proc_symbol(char **map, int i, int j, t_parse *parse)
{
	char	ch;

	ch = map[i][j];
	if (' ' == ch)
	{
		if (0 == check_space_sym(map, i, j))
			exit_with_error_parse(MAP_FAILURE, parse);
	}
	else if (is_pers(ch))
	{
		init_perse(ch, i, j, parse);
		map[i][j] = '0';
	}
	else if ('1' != ch && '0' != ch)
		exit_with_error_parse(ALLOWED_SYMB_FAILURE, parse);
}

void	firstly_parse(char **map, t_parse *parse)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			proc_symbol(map, i, j, parse);
		}
	}
	if (0 == parse->cub->pers->side)
		exit_with_error_parse(NUMBER_CHAR_FAILURE, parse);
}

char	**list_to2darr(t_list *list, t_parse *parse)
{
	int		size;
	char	**arr;
	int		i;

	i = 0;
	while (list && ((char *) list->content)[0] == '\n')
		list = list->next;
	if (NULL == list)
		exit_with_error_parse(MAP_FAILURE, parse);
	size = ft_lstsize(list);
	arr = (char **)malloc(sizeof(char*) * (size + 1));
	if (NULL == arr)
		exit_with_error_parse(MALLOC_FAILURE, parse);
	while (i < size)
	{
		arr[i] = ft_strtrim(list->content, "\n");
		if (NULL == arr[i])
			exit_with_error_parse(MALLOC_FAILURE, parse);
		i++;
		list = list->next;
	}
	arr[i] = NULL;
	return (arr);
}

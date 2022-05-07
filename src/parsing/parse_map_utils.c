#include "parsing.h"

static void	init_perse(char *ch, int i, int j, t_parse *parse)
{
	static int	flag = 0;

	if (1 == flag)
		exit_with_error_parse(MAP_FAILURE, parse);
	flag = 1;
	if ('N' == *ch)
		parse->cub->pers->side = 'N';
	else if ('W' == *ch)
		parse->cub->pers->side = 'W';
	else if ('E' == *ch)
		parse->cub->pers->side = 'E';
	else if ('S' == *ch)
		parse->cub->pers->side = 'S';
	*ch = '0';
	parse->cub->pers->x = i;
	parse->cub->pers->x = j;
}


static void	proc_symbol(char *ch, int i, int j, t_parse *parse)
{
	if (' ' == *ch)
		*ch = '1';
	else if ('N' == *ch || 'W' == *ch || 'E' == *ch || 'S' == *ch)
		init_perse(ch, i, j, parse);
	else if ('1' != *ch && '0' != *ch)
		exit_with_error_parse(MAP_FAILURE, parse);
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
			proc_symbol(&map[i][j], i, j, parse);
		}
	}
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

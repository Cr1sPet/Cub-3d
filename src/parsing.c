#include "cub3d.h"


char	**make_map(char *arg)
{
    int      fd = open(arg, O_RDONLY);
	char	  *line = NULL;
	t_list	*tmp = NULL;

	while (line = get_next_line(fd))
		ft_lstadd_back(&tmp, ft_lstnew(line));
	ft_lstadd_back(&tmp, ft_lstnew(line));

	char	  **map = ft_calloc(ft_lstsize(tmp) + 1, sizeof(char *));
	int		  i = -1;

	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	return (map);
}

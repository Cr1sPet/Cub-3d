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
		
	}
	clean_list(parse->input_data);
	ft_putendl_fd(error, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

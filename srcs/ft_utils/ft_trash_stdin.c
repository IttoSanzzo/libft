#include "libft.h"

void	ft_trash_stdin(int dsecs)
{
	char	c;

	c = 4;
	while (c != '\0')
		c = ft_getchar_unb(dsecs);
}

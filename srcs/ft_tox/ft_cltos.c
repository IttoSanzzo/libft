#include "libft.h"

char	*ft_cltos(t_clist *lst)
{
	t_clist	*temp;
	char	*str;
	char	*ret;

	if (!lst)
		return (NULL);
	str = (char *)ft_calloc(ft_clstlen(lst) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ret = str;
	temp = lst;
	while (temp)
	{
		*str++ = temp->val;
		temp = temp->next;
	}
	return (ret);
}

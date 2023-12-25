/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_ttos.c                                          :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/09/18 16:40:57 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/25 13:46:56 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	ft_f_len(char **tab, int sep_len)
{
	int	f_len;
	int	i;

	f_len = 0;
	i = -1;
	while (tab[++i])
	{
		f_len += ft_strlen(tab[i]);
		f_len += sep_len;
	}
	return (f_len - sep_len);
}

char	*ft_ttos(char **tab, char *sep)
{
	int		f_len;
	int		i;
	char	*str;
	char	*ptr;

	f_len = ft_f_len(tab, ft_strlen(sep));
	str = (char *)ft_calloc((f_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	ptr = str;
	i = -1;
	while (tab[++i])
	{
		ft_strcpy(ptr, tab[i]);
		ptr += ft_strlen(tab[i]);
		if (tab[i + 1])
		{
			ft_strcpy(ptr, sep);
			ptr += ft_strlen(sep);
		}
	}
	return (str);
}

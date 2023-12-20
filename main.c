/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/20 14:36:47 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/20 16:59:47 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft/includes/libft.h"

int	main(int ac, char **av, char **ep)
{
	char	**tab;
	char	*str;

	str = ft_strdup("");
	do
	{
		ft_printf("\n\n");
		free(str);
		str = ft_readline("\033[38;5;141mLinha..: \033[0m");
		if (ft_open_quotes(str, '"'))
			ft_printc(C_RED, "Quotes Abertas.\n");
		else
			ft_printc(C_GREEN, "Quotes Fechadas.\n");
		ft_printf("\n");
		tab = ft_split(str, ' ');
		ft_puttab(tab, "ft_split Av..: ");
		ft_freetab(tab);
		tab = ft_splitq(str, '"');
		ft_printf("\n");
//		ft_puttab(tab, "ft_splitq Av..: ");
//		ft_freetab(tab);
	} while(str && ft_strncmp(str, "exit", 5));
	free(str);
	return (0);
}

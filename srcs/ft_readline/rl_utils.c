/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_utils.c                                         :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:35:22 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 18:04:08 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_come_back(t_readline *rl)
{
	int	i;

	i = rl->len;
	while (i-- > rl->pos)
		ft_putchar('\b');
}

void	rl_addchar(t_readline *rl)
{
	rl->str = ft_stradd_n(rl->str, rl->ch, rl->pos);
	rl->len++;
	ft_putstr((char *)(rl->str + rl->pos));
	rl->pos += 2;
	rl_go_left(rl);
}

void	rl_cleard(t_readline *rl)
{
	ft_ansi_fclear();
	if (rl->prompt)
		ft_putstr(rl->prompt);
	ft_putstr(rl->str);
	rl_come_back(rl);
}

char	*rl_getprompt(char *prompt)
{
	static char	*save;

	if (prompt)
		save = prompt;
	return (save);
}

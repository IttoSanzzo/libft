/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_go.c                                            :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 16:41:51 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 16:42:40 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_go_right(t_readline *rl)
{
	if (rl->hpos == rl->hlen)
		ft_putchar((rl->str[rl->pos]));
	else
		ft_putchar((rl->his[rl->hpos][rl->pos]));
	rl->pos++;
}

void	rl_go_left(t_readline *rl)
{
	int	i;

	ft_putstr("\033[u");
	i = -1;
	rl->pos--;
	if (rl->hpos == rl->hlen)
		while (++i < rl->pos)
			ft_putchar((char)(rl->str[i]));
	else
		while (++i < rl->pos)
			ft_putchar((char)(rl->his[rl->hpos][i]));
}

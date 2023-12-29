/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_moviments.c                                     :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:18:32 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 16:42:53 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_do_home(t_readline *rl)
{
	if (rl->pos > 0)
	{
		ft_putstr("\033[u");
		rl->pos = 0;
	}
}

static void	rl_do_end(t_readline *rl)
{
	while (rl->pos < rl->len)
		rl_go_right(rl);
}

static void	rl_do_arrow_up(t_readline *rl)
{
	if (rl->his && rl->hpos > 0)
	{
		rl_do_home(rl);
		ft_ansi_drd(NULL);
		rl->hpos--;
		ft_putstr(rl->his[rl->hpos]);
		rl->len = ft_strlen(rl->his[rl->hpos]);
		rl->pos = rl->len;
		rl->move = 1;
	}
}

static void	rl_do_arrow_down(t_readline *rl)
{
	if (rl->his && rl->hpos < rl->hlen)
	{
		rl_do_home(rl);
		ft_ansi_drd(NULL);
		rl->hpos++;
		if (rl->hpos == rl->hlen)
		{
			ft_putstr(rl->str);
			rl->len = ft_strlen(rl->str);
			rl->pos = rl->len;
			rl->move = 0;
		}
		else
		{
			ft_putstr(rl->his[rl->hpos]);
			rl->len = ft_strlen(rl->his[rl->hpos]);
			rl->pos = rl->len;
			rl->move = 1;
		}
	}
}

void	rl_do_moviments(t_readline *rl)
{
	if (rl->ch == 'A')
		rl_do_arrow_up(rl);
	else if (rl->ch == 'B')
		rl_do_arrow_down(rl);
	else if ((rl->ch == 'D') && (rl->pos > 0))
		rl_go_left(rl);
	else if ((rl->ch == 'C') && (rl->pos < rl->len))
		rl_go_right(rl);
	else if (rl->ch == 'H')
		rl_do_home(rl);
	else if (rl->ch == 'F')
		rl_do_end(rl);
}

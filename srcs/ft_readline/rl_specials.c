/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_specials.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 10:37:55 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 16:36:50 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_do_tab(t_readline *rl)
{
	(void)rl;
	if (ft_rlconfig(1, GETV, 0))
	{
		ft_printf("\t");
	}
}

void	rl_do_backspace(t_readline *rl)
{
	if (rl->pos > 0)
	{
		rl->str = ft_strrem_n(rl->str, rl->pos - 1);
		rl->len--;
		ft_ansi_drd("\033[u");
		ft_putstr((char *)(rl->str));
		rl_go_left(rl);
	}
}

static void	rl_do_insert(t_readline *rl)
{
	rl->ch = '[';
	rl_addchar(rl);
	rl->ch = '2';
	rl_addchar(rl);
	rl->ch = '~';
	rl_addchar(rl);
}

static void	rl_do_delete(t_readline *rl)
{
	if (rl->pos < rl->len)
	{
		rl->str = ft_strrem_n(rl->str, rl->pos);
		rl->len--;
		ft_ansi_drd(NULL);
		ft_putstr((char *)(rl->str + rl->pos++));
		rl_go_left(rl);
	}
}

void	rl_get_specials(t_readline *rl)
{
	if ('[' == (char)ft_getchar())
	{
		rl->ch = ft_getchar();
		if (rl->ch == 'A' || rl->ch == 'B' || rl->ch == 'C' || rl->ch == 'D'
			|| rl->ch == 'H' || rl->ch == 'F')
			rl_do_moviments(rl);
		else if (rl_checkmove(rl) && (rl->ch == '2')
			&& ((char)ft_getchar() == '~'))
			rl_do_insert(rl);
		else if ((rl->ch == '3') && ((char)ft_getchar() == '~'))
			rl_do_delete(rl);
	}
}

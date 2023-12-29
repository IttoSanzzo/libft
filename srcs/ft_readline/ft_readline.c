/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/28 22:55:48 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 08:17:15 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static void	rl_come_back(t_readline *rl)
{
	int	i;

	i = rl->len;
	while (i-- > rl->pos)
		ft_putchar('\b');
}

static void	rl_addchar(t_readline *rl)
{
	rl->str = ft_stradd_n(rl->str, rl->ch, rl->pos);
	ft_putchar(rl->ch);
	ft_putstr((char *)(rl->str + rl->pos + 1));
	rl->pos++;
	rl->len++;
	rl_come_back(rl);
}

static void	rl_do_home(t_readline *rl)
{
	while (rl->pos > 0)
	{
		ft_putstr("\033[D");
		rl->pos--;
	}
}

static void	rl_do_end(t_readline *rl)
{
	while (rl->pos < rl->len)
	{
		ft_putstr("\033[C");
		rl->pos++;
	}
}

static void	rl_do_arrow_down(t_readline *rl)
{
	if (rl->his && rl->hpos < rl->hlen)
	{
		rl_do_home(rl);
		ft_ansi_drl(NULL);
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

static void	rl_do_arrow_up(t_readline *rl)
{
	if (rl->his && rl->hpos > 0)
	{
		rl_do_home(rl);
		ft_ansi_drl(NULL);
		rl->hpos--;
		ft_putstr(rl->his[rl->hpos]);
		rl->len = ft_strlen(rl->his[rl->hpos]);
		rl->pos = rl->len;
		rl->move = 1;
	}
}

static void	rl_do_arrows(t_readline *rl)
{
	if (rl->ch == 'A')
		rl_do_arrow_up(rl);
	else if (rl->ch == 'B')
		rl_do_arrow_down(rl);
	else if ((rl->ch == 'D') && (rl->pos > 0))
	{
		ft_putstr("\033[D");
		rl->pos--;
	}
	else if ((rl->ch == 'C') && (rl->pos < rl->len))
	{
		ft_putstr("\033[C");
		rl->pos++;
	}
	else if (rl->ch == 'H')
		rl_do_home(rl);
	else if (rl->ch == 'F')
		rl_do_end(rl);
}

static void	rl_do_delete(t_readline *rl)
{
	if (rl->pos < rl->len)
	{
		ft_ansi_drl(NULL);
		ft_putstr((char *)(rl->str + rl->pos + 1));
		rl->str = ft_strrem_n(rl->str, rl->pos);
		rl->len--;
		rl_come_back(rl);
	}
}

static void	rl_do_tab(t_readline *rl)
{
	(void)rl;
	if (ft_rlconfig(1, GETV, 0))
	{
		ft_printf("\t");
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

static void	rl_do_backspace(t_readline *rl)
{
	if (rl->pos > 0)
	{
		ft_ansi_drl("\b");
		ft_putstr((char *)(rl->str + rl->pos));
		rl->str = ft_strrem_n(rl->str, rl->pos - 1);
		rl->pos--;
		rl->len--;
		rl_come_back(rl);
	}
}

int	rl_checkmove(t_readline *rl)
{
	if (rl->move)
	{
		ft_free(rl->str);
		rl->str = ft_strdup(rl->his[rl->hpos]);
		rl->hpos = rl->hlen;
		rl->move = 0;
	}
	return (1);
}

static void	rl_get_specials(t_readline *rl)
{
	if ('[' == (char)ft_getchar())
	{
		rl->ch = ft_getchar();
		if (rl->ch == 'A' || rl->ch == 'B' || rl->ch == 'C' || rl->ch == 'D'
			|| rl->ch == 'H' || rl->ch == 'F')
			rl_do_arrows(rl);
		else if (rl_checkmove(rl) && (rl->ch == '2')
				&& ((char)ft_getchar() == '~'))
			rl_do_insert(rl);
		else if ((rl->ch == '3') && ((char)ft_getchar() == '~'))
			rl_do_delete(rl);
	}
}

static char	*rl_init(t_readline *rl, char *prompt)
{
	static char	*str;

	rl->str = str;
	ft_free(rl->str);
	rl->str = (char *)ft_calloc(1, sizeof(char));
	if (!rl->str)
		return (NULL);
	ft_rlconfig(2, PUTV, 0);
	rl->move = 0;
	rl->his = ft_rlhistory(NULL);
	rl->hlen = ft_rlconfig(0, GETV, 0);
	rl->hpos = rl->hlen;
	rl->pos = 0;
	rl->len = 0;
	rl->ch = 0;
	rl->prompt = prompt;
	return (rl->str);
}

static char	*rl_wrap_up(t_readline *rl)
{
	rl_checkmove(rl);
	ft_putchar('\n');
	return (rl->str);
}

static void	rl_cleard(t_readline *rl)
{
	ft_ansi_fclear();
	if (rl->prompt)
		ft_putstr(rl->prompt);
	ft_putstr(rl->str);
	rl_come_back(rl);
}

void	rl_checkreset(t_readline *rl)
{
	if (ft_rlconfig(2, GETV, 0))
		rl_init(rl, rl->prompt);
}

char	*ft_readline(char *prompt)
{
	t_readline	rl;

	if (!rl_init(&rl, prompt))
		return (NULL);
	if (rl.prompt)
		ft_putstr(rl.prompt);
	while (rl.ch != '\n')
	{
		rl.ch = ft_getchar();
		rl_checkreset(&rl);
		if (rl.len == 0 && rl.ch == 4)
			return (ft_free(rl.str));
		else if (rl.ch == '\033')
			rl_get_specials(&rl);
		else if (rl_checkmove(&rl) && rl.ch == '\t')
			rl_do_tab(&rl);
		else if (rl.ch == 127)
			rl_do_backspace(&rl);
		else if (rl.ch == '\f')
			rl_cleard(&rl);
		else if (rl.ch != '\n' && rl.ch != 4)
			rl_addchar(&rl);
	}
	return (rl_wrap_up(&rl));
}

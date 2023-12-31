/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   rl_save_cp.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/31 06:45:03 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/31 06:58:40 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

void	rl_save_home(t_readline *rl)
{
	ft_ansi_getcp(&rl->home[0], &rl->home[1]);
}

void	rl_save_end(t_readline *rl)
{
	ft_ansi_getcp(&rl->end[0], &rl->end[1]);
}

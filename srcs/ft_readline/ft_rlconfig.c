/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_rlconfig.c                                      :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/29 03:53:02 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 17:19:19 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

// ID 0 = HISTORY LEN..: Used to check it's lenght, and defined by history funs;
// ID 1 = TAB FUNCTION..: Uses opendir(), readdir() and closedir();
// ID 2 = Force Reset..: Frees and resets the readline from outside;
// ID 3 = Quotation Test..: Keeps readline up until quotes are closed;
int	ft_rlconfig(int id, size_t act, int val)
{
	static int	save[4];

	if (id < 0 || id > 4 - 1)
		return (0);
	if (act == PUTV)
		save[id] = val;
	return (save[id]);
}

/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/28 00:18:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/29 16:45:19 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

int	ft_getchar(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				c;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	read(STDIN_FILENO, &c, 1);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return (c);
}

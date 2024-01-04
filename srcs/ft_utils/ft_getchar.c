/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   ft_getchar.c                                       :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/28 00:18:20 by marcosv2	       #+#    #+#	      */
/*   Updated: 2024/01/04 02:58:44 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "libft.h"

static int	unicode_read(char c, struct termios oldt)
{
	unsigned char	buffer[4];
	int				num_bytes;
	int				i;
	int				unicode_value;

	buffer[0] = (unsigned char)c;
	unicode_value = buffer[0];
	num_bytes = 1;
	while ((unicode_value & (0x80 >> num_bytes)) != 0)
		++num_bytes;
	i = 0;
	while (++i < num_bytes)
	{
		if (!read(STDIN_FILENO, buffer + i, 1))
		{
			tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
			return (4);
		}
	}
	i = -1;
	while (++i < num_bytes)
		unicode_value = (unicode_value << 8) | buffer[i];
	ft_printc(C_RED, " %s}", buffer);
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return (unicode_value);
}

int	ft_getchar(void)
{
	struct termios	oldt;
	struct termios	newt;
	char			c;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	if (!read(STDIN_FILENO, &c, 1))
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
		return (c);
	}
	if ((c & 0xC0) == 0xC0)
		return (unicode_read(c, oldt));
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	return ((int)c);
}
/*
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
*/

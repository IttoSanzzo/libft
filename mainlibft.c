/* ************************************************************************** */
/*									      */
/*							  :::	   ::::::::   */
/*   mainlibft.c                                        :+:      :+:    :+:   */
/*						      +:+ +:+	      +:+     */
/*   By: marcosv2 <marcosv2@student.42.rio>	    +#+  +:+	   +#+	      */
/*						  +#+#+#+#+#+	+#+	      */
/*   Created: 2023/12/18 14:19:47 by marcosv2	       #+#    #+#	      */
/*   Updated: 2023/12/18 15:06:15 by marcosv2         ###   ########.fr       */
/*									      */
/* ************************************************************************** */

#include "includes/libft.h"

#define GRT_M "ohayou"
#define GRT_L 7
#define DFT_M "default"
#define DFT_L 8

int	test_core(int ac, char **av, char **ep)
{
	(void)ac;
	(void)av;
	(void)ep;
	ft_printf("Running %s test...\n\n", av[0]);













	ft_printf("Ending test...\n");
	return (1);
}

int	main(int ac, char **av, char **ep)
{
	(void)ep;
	if (ac < 2)
		ft_printf("Nothing to be done here...\n");
	if (ac == 2 && !ft_strncmp(av[1], GRT_M, GRT_L))
		ft_printf("Ohayou, Chariot!\n");
	else if (ac == 2 && !ft_strncmp(av[1], DFT_M, DFT_L))
		return (test_core(ac - 1, (char **)(av + 1), ep));
	return (0);
}

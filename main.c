/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:22:09 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/12 20:02:10 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// char	*s = 0;
	// int		i = -5;
	// char	c = 'a';
	// int		lenfake; 
	// int		lenori;
	// int		w = 10;
	// int		p = -20;

	// lenfake = 
	// printf("%5%");
	// printf("\n");
	ft_printf("%%04.3i 42 == |%04.3i|", 42);
	printf("%%04.3i 42 == |%04.3i|", 42);
	// printf("%5%");
	//lenori = ft_printf("%s, %s!\n", "Hello", "world");
	// printf("\n\nLONGITUD FAKE: %d\nLONGITUD ORIG: %d", lenfake, lenori);
	// system("leaks a.out");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 18:22:09 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/15 20:08:06 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	int a01 = 0;
	int a02 = 0;
	int a03 = 0;
	int a04 = 0;
	int a05 = 0;
	int a06 = 0;
	int a07 = 0;
	int a08 = 0;
	int a09 = 0;
	int a10 = 0;
	int a11 = 0;
	int a12 = 0;
	int ret_orig = 0;
	int ret_fake = 0;


	// ft_printf("%32p%32p%32p%32p%32p", &a1, &a2, &a3, &a4, &a5);
	ret_fake = ft_printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	printf("\n\n\n");
	ret_orig = printf("%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p%32p",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
	
	printf("\nReturn fake: %d", ret_fake);
	printf("\nReturn original: %d", ret_orig);
	// system("leaks a.out");
	return (0);
}
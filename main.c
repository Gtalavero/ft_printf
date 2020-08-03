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

#include <limits.h>
#include "ft_printf.h"

int		main(void)
{
	int	n, ret_fake, ret_orig;
	ret_fake = ft_printf("%s %d %i %x %p %3p %% %.0x %.0d %10.0d %10.0x", "Ho\n	ka", INT_MAX, INT_MIN, UINT_MAX, &n, NULL, 0, 0, 0, 0);
	printf("%%\n");
	ret_orig = printf("%s %d %i %x %p %3p %% %.0x %.0d %10.0d %10.0x", "Ho\n	ka", INT_MAX, INT_MIN, UINT_MAX, &n, NULL, 0, 0, 0, 0);

	printf("\nReturn fake: %d", ret_fake);
	printf("\nReturn original: %d", ret_orig);
	//system("leaks a.out");
	return (0);
}
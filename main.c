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
	ft_printf("%p", NULL);
	printf("\n\n\n");
	// printf("\nReturn fake: %d", ret_fake);
	// printf("\nReturn original: %d", ret_orig);
	system("leaks a.out");
	return (0);
}
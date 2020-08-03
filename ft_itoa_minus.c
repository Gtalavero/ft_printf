/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_minus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 19:05:00 by gtalaver          #+#    #+#             */
/*   Updated: 2020/08/03 19:59:18 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	is_neg(long int nb, t_data *x)
{
	x->is_negative = 1;
	return (nb * -1);
}

char		*ft_itoa_minus(int n, t_data *x)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	nb < 0 ? nb = is_neg(nb, x) : 0;
	if (nb != 0)
	{
		i = ft_numlen(nb, 10);
		if (!(str = malloc(i * sizeof(char) + 1)))
			return (0);
		str[i--] = 0;
		while (nb > 0)
		{
			str[i--] = nb % 10 + '0';
			nb = nb / 10;
		}
	}
	else
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = 48;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:09:25 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/07 19:28:53 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_minus(int n, t_data *x)
{
	char		*str;
	int			i;
	long int	nb;

	nb = n;
	if (nb < 0)
	{
		x->is_negative = 1;
		nb = nb * -1;
	}
	i = ft_numlen(nb, 10);
	if (!(str = malloc(i * sizeof(char) + 1)))
		return (0);
	str[i--] = 0;
	if (nb == 0)
	{
		str = ft_calloc(2, sizeof(char));
		str[0] = 48;
	}

	while (nb > 0)
	{
		str[i--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}

void	x_X_p_conversion(t_data *x)
{
	unsigned int		i;
	
	i = 0;
	if (x->type == 'p')
	{
		x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned long int), 16);
		while (x->raw_str[i])
		{
			x->raw_str[i] = ft_tolower(x->raw_str[i]);
			i++;
		}
		x->raw_str = ft_strjoin("0x", x->raw_str);
	}
	if (x->type == 'x' || x->type == 'X')
	{
		x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned int), 16);
		if (x->type == 'x')
			while (x->raw_str[i])
			{
				x->raw_str[i] = ft_tolower(x->raw_str[i]);
				i++;
			}
	}
}

void	d_i_conversion(t_data *x)
{
	int	arg;
	int	raw_str_len;

	arg = va_arg(x->ap,	int);
	x->raw_str = ft_itoa_minus(arg, x);
	raw_str_len = ft_strlen(x->raw_str);
	while (x->precision-- > raw_str_len)
		x->raw_str = ft_strjoin("0", x->raw_str);
	if (x->is_negative == 1)
		x->raw_str = ft_strjoin("-", x->raw_str);
}

void	c_conversion(t_data *x)
{
	char	arg[2];

	if (x->type == '%')
		arg[0] = '%';
	else
		arg[0] = va_arg(x->ap, int);
	arg[1] = '\0';
	x->raw_str = arg;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 19:09:25 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/15 20:37:20 by gtalaver         ###   ########.fr       */
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

void	s_conversion(t_data *x)
{
	x->raw_str = va_arg(x->ap, char *);
	if (x->raw_str)
		x->raw_str_len = (int)ft_strlen(x->raw_str);
	if (x->precision != -1 && x->precision < x->raw_str_len)
		x->raw_str = ft_substr(x->raw_str, 0, x->precision);
}

void	p_conversion(t_data *x)
{
	int		i;

	i = 0;
	x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned long int), 16);
	while (x->raw_str[i])
	{
		x->raw_str[i] = ft_tolower(x->raw_str[i]);
		i++;
	}
	if (x->raw_str[0] == '0' && x->raw_str[i] == '\0' && x->precision == 0)
		x->raw_str = ft_strjoin(x->raw_str, "x");
	else
	{
		if (x->precision > 0 && x->raw_str != NULL)
		{
			i = x->precision - i;
			while(i-- > 0)
				x->raw_str = ft_strjoin("0", x->raw_str);
		}
		x->raw_str = ft_strjoin("0x", x->raw_str);
	}
}

void	x_X_conversion(t_data *x)
{
	int	i;
	
	i = 0;
	if (x->precision != 0)
		x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned int), 16);
	while (x->type == 'x' && x->raw_str[i])
	{
		x->raw_str[i] = ft_tolower(x->raw_str[i]);
		i++;
	}
	i = ft_strlen(x->raw_str);
	while (x->precision > i++)
		x->raw_str = ft_strjoin("0", x->raw_str);
	if (x->is_negative == 1)
		x->raw_str = ft_strjoin("-", x->raw_str);
}

void	d_i_u_conversion(t_data *x)
{
	int		raw_str_len;
	int		i;

	if (x->precision > 0 || x->precision == -1)
	{
		if (x->type == 'd')
			x->raw_str = ft_itoa_minus(va_arg(x->ap, int), x);
		else if (x->type == 'u')
			x->raw_str = ft_itoa_base(va_arg(x->ap, unsigned int), 10);
		raw_str_len = ft_strlen(x->raw_str);
		i = x->precision;
		while (i-- > raw_str_len)
			x->raw_str = ft_strjoin("0", x->raw_str);
	}
}

void	c_conversion(t_data *x)
{
	char	arg[2];

	x->type == '%' ? arg[0] = '%' : (arg[0] = va_arg(x->ap, int));
	arg[1] = '\0';
	if (arg[0] == '\0')
	{
		x->flag == '-' ? write (1, "\0", 1) : 0;
		while(--(x->width) > 0)
		{
			x->flag == '0' ? write(1, "0", 1) : write(1, " ", 1);
			x->len++;
		}
		x->flag != '-' ? write (1, "\0", 1) : 0;
		x->len++;
	}
	x->raw_str = arg;
}


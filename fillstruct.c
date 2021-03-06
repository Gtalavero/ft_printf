/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstruct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 20:58:12 by gtalaver          #+#    #+#             */
/*   Updated: 2020/08/03 20:04:16 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_flag(t_data *x)
{
	while (*x->format == '0' || *x->format == '-')
	{
		if (*x->format == '-')
			x->flag = '-';
		else if (x->flag != '-')
			x->flag = '0';
		x->format++;
	}
}

void	get_width(t_data *x)
{
	if (*x->format == '*')
	{
		x->format++;
		x->width = va_arg(x->ap, int);
		if (x->width < 0)
		{
			x->width *= -1;
			x->flag = '-';
		}
	}
	if (ft_isdigit(*x->format))
	{
		x->width = *x->format++ - 48;
		while (ft_isdigit(*x->format))
			x->width = x->width * 10 + *x->format++ - 48;
	}
}

void	get_precision(t_data *x)
{
	if (*x->format == '.')
	{
		x->format++;
		if (*x->format == '*')
		{
			x->format++;
			x->precision = va_arg(x->ap, int);
			if (x->precision < 0)
				x->precision = -1;
		}
		if (ft_isdigit(*x->format))
		{
			x->precision = *x->format++ - 48;
			while (ft_isdigit(*x->format))
				x->precision = x->precision * 10 + *x->format++ - 48;
		}
	}
	else
		x->precision = -1;
}

void	get_type(t_data *x)
{
	char	conver[10];
	int		i;

	i = 0;
	ft_strlcpy(conver, "cspdiuxX%", sizeof(conver));
	while (conver[i])
	{
		if (*x->format == conver[i])
			x->type = conver[i];
		i++;
	}
	x->type == 'i' ? x->type = 'd' : 0;
}

void	fillstruct(t_data *x)
{
	x->raw_alloc = 0;
	get_flag(x);
	get_width(x);
	get_precision(x);
	get_type(x);
	x->type == 'c' || x->type == '%' ? c_conversion(x) : NULL;
	x->type == 's' ? s_conversion(x) : NULL;
	x->type == 'p' ? p_conversion(x) : NULL;
	x->type == 'x' || x->type == 'X' ? x_conversion(x) : NULL;
	x->type == 'd' || x->type == 'u' ? d_i_u_conversion(x) : NULL;
	fill_final_str(x);
	*x->format != '\0' ? x->format++ : 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:16:33 by gtalaver          #+#    #+#             */
/*   Updated: 2020/08/03 20:02:25 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ini_struct(t_data *x)
{
	x->flag = '\0';
	x->width = 0;
	x->precision = 0;
	x->type = '\0';
	x->raw_str = "\0";
	x->raw_str_len = 0;
	x->final_str = "\0";
	x->is_negative = 0;
	x->raw_alloc = 0;
}

int		ft_printf(const char *format, ...)
{
	t_data	x;

	va_start(x.ap, format);
	x.format = (char *)format;
	ini_struct(&x);
	x.len = 0;
	while (*x.format != '\0')
	{
		if (*x.format == '%')
		{
			ini_struct(&x);
			x.format++;
			fillstruct(&x);
		}
		else
		{
			write(1, x.format, 1);
			x.len++;
			x.format++;
		}
	}
	va_end(x.ap);
	return (x.len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:16:33 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/12 19:11:19 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data	x;

	va_start(x.ap, format);
	x.len = 0;
	// x.format = (char *)format;
	x.format = ft_strjoin((char *)format, "\0");
	x.raw_str = "\0";
	x.final_str = "\0";
	x.raw_str_len = 0;
	x.is_negative = 0;
	x.type = '\0';
	while (*x.format)
	{
		if (*x.format == '%')
		{
			x.format++;
			fillstruct(&x);
		}
		else
		{
			write(1, x.format, 1);
			x.len++;
		}
			x.format++;
	}
	//printf("\n|| FLAG: %c || WIDTH: %d || PRECISION: %d || TYPE: %c", x.flag, x.width, x.precision, x.type);
	return (x.len);
}

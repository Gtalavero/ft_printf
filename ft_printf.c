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

void	ini_struct(t_data *x)
{
	
	x->len = 0;
	x->raw_str = "\0";
	x->flag = '\0';
	x->final_str = "\0";
	x->raw_str_len = 0;
	x->is_negative = 0;
	x->width = 0;
	x->type = '\0';
	x->precision = 0;
}

int		ft_printf(const char *format, ...)
{
	t_data	x;

	va_start(x.ap, format);
	x.format = (char *)format;
	//x.format[ft_strlen(x.format) + 1] = '\0';
	//x.format = ft_strjoin((char *)format, "\0"); //no segfault pero leaks
	//x.format = malloc(sizeof(char) * ft_strlen(format) + 1);
	//x.format = ft_strjoin((char*)format, "\0");
	ini_struct(&x);
	//free((char *)x.format);
	while (*x.format != '\0')
	{
		if (*x.format == '%')
		{
			x.format++;
			fillstruct(&x);
			//x.format++;
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



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:39:32 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/10 20:26:40 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cero_flag(t_data *x)
{
	if (x->flag == '0' && x->type != 's' && x->type != 'c')
	{
		x->final_str = malloc(x->width * sizeof(char) + 1);
		ft_memset(x->final_str, '0', x->width);
	}
	else
	{
		x->final_str = malloc(x->width * sizeof(char) + 1);
		ft_memset(x->final_str, ' ', x->width);
	}
}

void	minus_flag(t_data *x)
{
	int		i;

	if (x->flag == '-')
	{
		i = 0;
		while(x->raw_str_len--)
			x->final_str[i++] = *x->raw_str++;
	}
	else
	{
		i = x->width - x->raw_str_len;
		while (i < x->width)
			x->final_str[i++] = *x->raw_str++;
	}
}

void	fill_final_str(t_data *x)
{
	if (x->type != 'c' && x->type != 'p' && x->type != 'd' && x->type != 'i' 
		&& x->precision > 0)
		x->raw_str = ft_substr(x->raw_str, 0, x->precision);
	if (!(x->raw_str))
		x->raw_str = ft_strdup("(null)"); // Poner simplemente x->raw_str = "(null)";
	x->raw_str_len = ft_strlen(x->raw_str);
	x->width < x->raw_str_len ? x->width = x->raw_str_len : 0;
	cero_flag(x);
	minus_flag(x);
	//ft_putstr_fd(x->final_str, 1);
	while (*x->final_str != '\0')
	{
		if (ft_isprint(*x->final_str))
		{
			ft_putchar_fd(*x->final_str, 1);
		}
		x->final_str++;
	}
	//free(x->final_str);
	x->len += x->width;
}
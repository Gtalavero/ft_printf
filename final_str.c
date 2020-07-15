/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:39:32 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/15 20:06:40 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cero_flag(t_data *x)
{
	if (x->flag == '0' && x->type != 's' && x->type != 'c'
		&& !(x->type == 'd' && x->precision > 0))
	{
		x->final_str = malloc(x->width * sizeof(char) + 1);
		x->final_str[x->width] = '\0';
		ft_memset(x->final_str, '0', x->width);
	}
	else
	{
		x->final_str = malloc(x->width * sizeof(char));
		x->final_str[x->width] = '\0';
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
	if (x->type != 'c' && x->type != 'p' && x->type != 'd')
		x->raw_str = ft_substr(x->raw_str, 0, x->precision);
	if (!(x->raw_str))
	{
		x->raw_str = "(null)";
		x->raw_str = ft_substr(x->raw_str, 0, x->precision);
	}
	x->raw_str_len = ft_strlen(x->raw_str);
	x->width < x->raw_str_len ? x->width = x->raw_str_len : 0;
	cero_flag(x);
	minus_flag(x);
	ft_putstr_fd(x->final_str, 1);
	//free(x->final_str);
	x->len += x->width;
}
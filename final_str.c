/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 21:39:32 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/15 20:34:48 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	cero_flag(t_data *x)
{
	if ((x->type == 'd' || x->type == 'u') && x->flag == '0' && x->precision > 0)
		x->flag = '\0';
	if (x->flag == '0' && x->type != 'c' && x->precision < 0)
	{
		x->final_str = malloc(x->width * sizeof(char) + 1);
		x->final_str[x->width] = '\0';
		ft_memset(x->final_str, '0', x->width);
	}
	else
	{
		x->final_str = malloc(x->width * sizeof(char));
		if (x->is_negative == 1)
			ft_memset(x->final_str, ' ', x->width - 1); //x->width - 1
		else
			ft_memset(x->final_str, ' ', x->width);
		if (x->flag == '-' && x->type == 'd' && x->precision > 0 && x->is_negative
			&& x->width > x->precision)
			x->final_str[x->width - 1] = '\0';
		else
			x->final_str[x->width] = '\0';
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
		// if (x->type == 'd' || x->type == 'u')
		// 	x->final_str[x->width - 1] = '\0';
	}
	else
	{
		i = x->width - x->raw_str_len;
		while (i < x->width)
			x->final_str[i++] = *x->raw_str++;
	}
}

void	d_is_negative(t_data *x)
{
	int		i;
	
	i = 0;
	if (ft_isdigit(x->final_str[0]))
	{
		if (x->flag == '0' && x->final_str[0] == '0')
			x->final_str[0] = '-';
		else
		{
			x->final_str = ft_strjoin("-", x->final_str);
			//x->len++; //fallo aqui en algunas casuisticas
			//x->final_str[ft_strlen(x->final_str)] = '\0'; //
		}
	}
	else 
	{
		while (x->final_str[i] && x->final_str[i] == ' ')
			i++;
		x->final_str[--i] = '-';
	}
}

void	fill_final_str(t_data *x)
{
	//cambiar esta guarrada
	if (x->type != 'c' && x->type != 'p' && x->type != 'd' && x->type != 'u' && x->type != 'x' && x->type != 'X')
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
	if (x->type == 'd' && x->is_negative == 1)
		d_is_negative(x);
	ft_putstr_fd(x->final_str, 1);
	x->len += (int)ft_strlen(x->final_str);
	free(x->final_str);
}
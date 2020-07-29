/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/24 18:48:25 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/15 20:33:40 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_data
{
	va_list	ap;
	char	*format;
	char	flag;
	int		width;
	int		precision;
	int		len;
	char	type;
	char	*raw_str;
	int		raw_str_len;
	char	*final_str;
	int		is_negative;
	int		raw_alloc;

}				t_data;

int				ft_printf(const char *format, ...);
void			fillstruct(t_data *x);
void			s_conversion(t_data *x);
void			c_conversion(t_data *x);
void			s_conversion(t_data *x);
void			d_i_u_conversion(t_data *x);
void			p_conversion(t_data *x);
void			x_X_conversion(t_data *x);
void			fill_final_str(t_data *x);

#endif

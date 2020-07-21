/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaverodev@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:48:00 by gtalaver          #+#    #+#             */
/*   Updated: 2020/07/12 19:18:52 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string "s" to the given file descriptor "fd".
*/

void	ft_putstr_fd(char *s, int fd)
{
	// int		i;	

	// i = 0;
	if (s)
		write(fd, s, ft_strlen(s));
	// while(s[i] && ft_isprint(s[i]))
	// {
	// 	ft_putchar_fd(s[i], fd);
	// 	i++;
	// }
}

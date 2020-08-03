/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtalaver <gtalaver@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 17:48:00 by gtalaver          #+#    #+#             */
/*   Updated: 2019/12/10 14:19:16 by gtalaver         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Outputs the string "s" to the given file descriptor "fd".
*/

void	ft_putstr_fd(char *s, int fd)
{
	int		i;

	i = ft_strlen(s);
	if (s)
		write(fd, s, i);
}

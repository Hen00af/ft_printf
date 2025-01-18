/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:27:05 by shattori          #+#    #+#             */
/*   Updated: 2025/01/18 15:42:57 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr_fd(char *s, int fd, t_tab *tab)
{
	int	len;

	if (!s)
	{
		if (ft_confirm_write(fd, "(null)", 6, tab) == -1)
			return (-1);
		return (6);
	}
	len = 0;
	while (*s)
	{
		if (ft_confirm_write(fd, s++, 1, tab) == -1)
			return (-1);
		len++;
	}
	return (len);
}

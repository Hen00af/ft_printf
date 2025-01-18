/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_confirm_write.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:27:49 by shattori          #+#    #+#             */
/*   Updated: 2025/01/17 17:18:47 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_confirm_write(int fd, const void *buf, int count, t_tab *tab)
{
	int	ret;

	ret = write(fd, buf, count);
	if (ret == -1)
	{
		tab->error_flag = 1;
		return (-1);
	}
	return (ret);
}

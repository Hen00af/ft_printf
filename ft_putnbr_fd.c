/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:35:48 by shattori          #+#    #+#             */
/*   Updated: 2024/12/05 22:53:58 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		len;

	len = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		len = 11;
		return (len);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		len++;
	}
	if (n >= 10)
	{
		len += ft_putnbr_fd(n / 10, fd);
	}
	n %= 10;
	c = n + '0';
	len++;
	write(fd, &c, 1);
	return (len);
}

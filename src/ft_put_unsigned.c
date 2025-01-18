/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:29:08 by shattori          #+#    #+#             */
/*   Updated: 2025/01/17 17:49:53 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_unsigned(unsigned int n, t_tab *tab)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len += ft_put_unsigned(n / 10, tab);
	}
	ft_putchar_fd((n % 10) + '0', 1, tab);
	len++;
	return (len);
}

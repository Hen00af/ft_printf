/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 03:20:12 by shattori          #+#    #+#             */
/*   Updated: 2024/12/13 21:31:01 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexadicimal(va_list ap, int i)
{
	int		len;
	char	*str;

	str = ft_decimal_to_hexadecimal(va_arg(ap, unsigned long long), i);
	len = ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	handle_format(va_list ap, const char *specifier)
{
	int	len;

	if (*specifier == 'd' || *specifier == 'i')
		len = ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*specifier == 'c')
		len = ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (*specifier == 's')
		len = ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*specifier == 'p')
		len = ft_putptr(va_arg(ap, void *));
	else if (*specifier == 'u')
		len = ft_put_unsigned(va_arg(ap, unsigned int));
	else if (*specifier == 'x')
		len = ft_put_hexadicimal(ap, 0);
	else if (*specifier == 'X')
		len = ft_put_hexadicimal(ap, 1);
	else if (*specifier == '%')
		len = ft_putchar_fd('%', 1);
	else
		return (0);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	va_list	ap;
	int		total_len;

	len = 0;
	total_len = 0;
	va_start(ap, str);
	while (str[len])
	{
		if (str[len] == '%' && str[len + 1] != '\0')
		{
			total_len += handle_format(ap, &str[len + 1]);
			len += 2;
		}
		else
		{
			ft_putchar_fd(str[len], 1);
			len++;
			total_len++;
		}
	}
	va_end(ap);
	return (total_len);
}

// int	main(void)
// {
// 	int		num;
// 	char	ptr;

// 	num = ft_printf("%p %p", 0, 0);
// 	printf("\n%d\n", num);
// 	num = printf("%p %p", 0, 0);
// 	printf("\n%d\n", num);
// 	return (0);
// }

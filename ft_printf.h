/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 21:35:47 by shattori          #+#    #+#             */
/*   Updated: 2024/12/13 19:15:41 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_put_unsigned(unsigned int n);
char	*ft_decimal_to_hexadecimal(unsigned int variable, int uppercase);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putptr(void *ptr);
int		ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *in);

#endif // FT_PRINTF_H

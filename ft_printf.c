/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:26:34 by sel-mars          #+#    #+#             */
/*   Updated: 2021/11/16 23:15:03 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ret)
{
	write(1, &c, 1);
	(*ret)++;
}

void	ft_putstr(char *str, int *ret)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr("(null)", ret);
	else
	{
		while (str[i])
			ft_putchar(str[i++], ret);
	}
}

void	ft_putnbr(long long nb, int *ret)
{
	if (nb < 0)
	{
		ft_putchar('-', ret);
		nb *= -1;
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + 48, ret);
	else
	{
		ft_putnbr(nb / 10, ret);
		ft_putnbr(nb % 10, ret);
	}
}

void	ft_printf_ext(char c, va_list args, int *ret)
{
	if (c == '%')
		ft_putchar('%', ret);
	if (c == 'c')
		ft_putchar(va_arg(args, int), ret);
	if (c == 's')
		ft_putstr(va_arg(args, char *), ret);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), ret);
	if (c == 'u')
		ft_putunbr(va_arg(args, unsigned int), ret);
	if (c == 'x')
		ft_puthex(va_arg(args, unsigned int), ret);
	if (c == 'X')
		ft_puthexa(va_arg(args, unsigned int), ret);
	if (c == 'p')
		ft_putptr(va_arg(args, unsigned long), ret);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;

	va_start(args, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%')
			ft_printf_ext(str[++i], args, &ret);
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	va_end(args);
	return (ret);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:26:34 by sel-mars          #+#    #+#             */
/*   Updated: 2021/11/16 23:15:03 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunbr(unsigned int nb, int *ret)
{
	if (nb < 10)
		ft_putchar(nb + 48, ret);
	else
	{
		ft_putunbr(nb / 10, ret);
		ft_putunbr(nb % 10, ret);
	}
}

void	ft_puthex(unsigned int nb, int *ret)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(hexbase[nb], ret);
	else
	{
		ft_puthex(nb / 16, ret);
		ft_puthex(nb % 16, ret);
	}
}

void	ft_puthexa(unsigned int nb, int *ret)
{
	char	*hexbase;

	hexbase = "0123456789ABCDEF";
	if (nb < 16)
		ft_putchar(hexbase[nb], ret);
	else
	{
		ft_puthexa(nb / 16, ret);
		ft_puthexa(nb % 16, ret);
	}
}

void	ft_puthexadecimal(unsigned long nb, int *ret)
{
	char	*hexbase;

	hexbase = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(hexbase[nb], ret);
	else
	{
		ft_puthexadecimal(nb / 16, ret);
		ft_puthexadecimal(nb % 16, ret);
	}
}

void	ft_putptr(unsigned long nb, int *ret)
{
	ft_putstr("0x", ret);
	ft_puthexadecimal(nb, ret);
}
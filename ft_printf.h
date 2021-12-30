/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sel-mars <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 21:26:34 by sel-mars          #+#    #+#             */
/*   Updated: 2021/11/16 23:15:03 by sel-mars         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *str, ...);
void	ft_printf_ext(char c, va_list args, int *ret);
void	ft_putchar(char c, int *ret);
void	ft_putstr(char *str, int *ret);
void	ft_putnbr(long long nb, int *ret);
void	ft_putunbr(unsigned int nb, int *ret);
void	ft_puthex(unsigned int nb, int *ret);
void	ft_puthexa(unsigned int nb, int *ret);
void	ft_puthexadecimal(unsigned long nb, int *ret);
void	ft_putptr(unsigned long nb, int *ret);
#endif
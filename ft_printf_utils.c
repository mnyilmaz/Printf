/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:05:05 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 17:53:03 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_states(t_print print, va_list to_do)
{
	if(print.specifier == 'c')
		return (ft_print_char(va_arg(to_do, int)));
	else if(print.specifier == 's')
		return (ft_print_str(va_arg(to_do, char*)));
	else if(print.specifier == 'p')
		return (ft_print_rest(va_arg(to_do, unsigned long), 16, BASE, P1)); //64 bit garantilemesi
	else if(print.specifier == 'i')
		return (ft_print_rest(va_arg(to_do, int), 10, DEC, P2)); 
	else if(print.specifier == 'u')
		return (ft_print_rest(va_arg(to_do, unsigned int), 10, DEC, P2)); 
	else if(print.specifier == 'd')
		return (ft_print_rest(va_arg(to_do, unsigned int), 10, DEC, P2)); 
	else if(print.specifier == 'x')
		return (ft_print_rest(va_arg(to_do, unsigned int), 16, BASE, P2));
	else if(print.specifier == 'X')
		return (ft_print_rest(va_arg(to_do, unsigned int), 16, BASE_U, P2));
	else if(print.specifier == '%')
		return (ft_print_char('%'));
	return (0);
}

int ft_print_char(char c)
{
	return(write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	t_print print;

	print.point = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s)
	{
		ft_print_char(*s++);
		print.point++;
	}
	return (print.point);
}

int	ft_print_rest(long int num, int len, char *base, int point)
{
	t_print print;
	print.res = 0;
	if (num < 0)
	{
		print.res += ft_print_char('-');
		num *= -1;
	}
	if (num >= len)
	{
		if (point == 1)
		{
			write(1, "0x", 2);
			print.res += ft_print_rest((num / len), len, base, point);
			print.res += ft_print_rest((num % len), len, base, point);
		}
		else if (point == 2)
		{
			print.res += ft_print_rest((num / len), len, base, point);
			print.res += ft_print_rest((num % len), len, base, point);
		}
	}
	else
		print.res += ft_print_char(base[num]);
	return (print.res);
}

void	ft_cleaner(t_print print)
{
	print.i = 0;
	print.len = 0;
	print.res = 0;
	print.point = 0;
	print.specifier = 0;
}

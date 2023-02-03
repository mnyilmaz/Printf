/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:05:05 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 18:56:52 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_states(va_list to_do, t_printf print)
{
	if (print.spec == 'c')
		print.len += ft_print_char(va_arg(to_do, int));
	else if (print.spec == 's')
		print.len += ft_print_str(va_arg(to_do, char*));
	else if (print.spec == 'p')
	{
		write(1, "0x", 2);
		print.len += ft_print_rest(va_arg(to_do, unsigned long), 16, BASE, P1) + 2; //64 bit garantilemesi
	}
	else if (print.spec == 'i')
		print.len += ft_print_rest(va_arg(to_do, int), 10, DEC, P2); 
	else if (print.spec == 'u')
		print.len += ft_print_rest(va_arg(to_do, unsigned int), 10, DEC, P2); 
	else if (print.spec == 'd')
		print.len += ft_print_rest(va_arg(to_do, unsigned int), 10, DEC, P2); 
	else if (print.spec == 'x')
		print.len += ft_print_rest(va_arg(to_do, unsigned int), 16, BASE, P2);
	else if (print.spec == 'X')
		print.len += ft_print_rest(va_arg(to_do, unsigned int), 16, BASE_U, P2);
	else if (print.spec == '%')
		print.len += ft_print_char('%');
	return (print.len);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int slen;

	slen = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s)
	{
		ft_print_char(*s++);
		slen++;
	}
	return (slen);
}

int	ft_print_rest(long long int num, int len, char *base, int point)
{
	int	rlen;

	rlen = 0;
	if (num < 0)
	{
		rlen += ft_print_char('-');
		num *= -1;
	}
	if (num >= len)
	{
		if (point == 1)
		{
			rlen += ft_print_rest((num / len), len, base, point);
			rlen += ft_print_rest((num % len), len, base, point);
		}
		else if (point == 2)
		{
			rlen += ft_print_rest((num / len), len, base, point);
			rlen += ft_print_rest((num % len), len, base, point);
		}
	}
	else
		rlen += ft_print_char(base[num]);
	return (rlen);
}

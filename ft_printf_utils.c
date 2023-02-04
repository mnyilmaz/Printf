/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:05:05 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/04 15:46:13 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_states(char spec, va_list to_do)
{
	if (spec == 'c')
		return (ft_print_char(va_arg(to_do, int)));
	else if (spec == 's')
		return (ft_print_str(va_arg(to_do, char *)));
	else if (spec == 'p')
	{
		write(1, "0x", 2);
		return (ft_print_rest(va_arg(to_do, unsigned long), H_LEN, BASE) + 2);
	}
	else if (spec == 'i' || spec == 'd')
		return (ft_print_int(va_arg(to_do, int)));
	else if (spec == 'u')
		return (ft_print_rest(va_arg(to_do, unsigned int), D_LEN, DEC));
	else if (spec == 'x')
		return (ft_print_rest(va_arg(to_do, unsigned int), H_LEN, BASE));
	else if (spec == 'X')
		return (ft_print_rest(va_arg(to_do, unsigned int), H_LEN, BASE_U));
	else if (spec == '%')
		return (ft_print_char('%'));
	return (0);
}

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (ft_print_str("(null)"));
	while (*s)
	{
		ft_print_char(*s++);
		len++;
	}
	return (len);
}

int	ft_print_rest(size_t num, size_t base_len, char *base)
{
	int	rlen;

	rlen = 0;
	if (num >= base_len)
	{
		rlen += ft_print_rest(num / base_len, base_len, base);
		rlen += ft_print_rest(num % base_len, base_len, base);
	}
	else
		rlen += ft_print_char(base[num]);
	return (rlen);
}

int	ft_print_int(int num)
{
	int	rlen;

	rlen = 0;
	if (num == -__INT_MAX__ - 1)
		return (ft_print_str("-2147483648"));
	if (num < 0)
	{
		rlen += ft_print_char('-');
		rlen += ft_print_int(num * -1);
	}
	else if (num >= 10)
	{
		rlen += ft_print_int(num / 10);
		rlen += ft_print_int(num % 10);
	}
	else
		rlen += ft_print_char(num + '0');
	return (rlen);
}

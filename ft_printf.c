/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:52:14 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 23:57:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	t_printf print;
	va_list to_do;
	char spec;
	int len;

	len = 0;
	va_start(to_do, fmt);
	int i = 0;
	while (*(fmt + i))
	{
		if(*(fmt + i) == '%')
		{
			i++;
			print.spec = *(fmt + i);
			print.result += ft_states(spec, to_do, print);
		}
		else
			print.result += ft_print_char(*(fmt + i));
		i++;
	}
	va_end(to_do);
	return (print.result);
}

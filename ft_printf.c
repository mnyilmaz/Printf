/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:52:14 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 19:13:28 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
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
			spec = *(fmt + i);
			len += ft_states(spec, to_do);
		}
		else
			len += ft_print_char(*(fmt + i));
		i++;
	}
	va_end(to_do);
	return (len);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_printf("%d", 5));
}

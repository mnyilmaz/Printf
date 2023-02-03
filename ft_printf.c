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
	t_printf print;
	va_list to_do;
	//char spec;
	//int len;

	//len = 0;
	va_start(to_do, fmt);
	int i = 0;
	while (*(fmt + i))
	{
		if(*(fmt + i) == '%')
		{
			i++;
			print.spec = *(fmt + i);
			print.result += ft_states(to_do, print);
		}
		else
			print.result += ft_print_char(*(fmt + i));
		i++;
	}
	va_end(to_do);
	return (print.result);
}

#include <stdio.h>
int main(void)
{
	int a = 5;
	int *ptr;
	ptr = &a;

	ft_printf("");
	printf("\n");
	ft_printf("extraordinary");
	printf("\n");
	ft_printf("%c", 's');
	printf("\n");
	ft_printf("%s", "extiraordinary");
	printf("\n");
	ft_printf("%p", ptr);
	printf("\n");
	ft_printf("%i", -8546);
	printf("\n");
	ft_printf("%d", 294830);
	printf("\n");
	ft_printf("%u", 0257);
	printf("\n");
	ft_printf("%x", 99);
	printf("\n");
	ft_printf("%X", 256);
	printf("\n");
	ft_printf("%%");

	//printf("%d\n", ft_printf("%d", 5));
}

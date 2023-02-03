/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:52:14 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 17:51:30 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	t_print print;
	va_list to_do;
	va_start(to_do, fmt);
	int i = 0;
	if(!*fmt)
		return (write(1, "(null)", 6));
	while(*(fmt + i))
	{
		if(*(fmt + i) == '%')
		{
			i++;
			print.specifier = *(fmt + i++);
			ft_states(print, to_do);
		}
		else
			ft_print_char(*(fmt + i));
		i++;
	}
	return (i);
}

#include <stdio.h>
int main(void)
{
	int a = 6;
	int *ptr;
	
	ptr = &a;
	printf("ORG: merhaba %p\n", ptr);
	ft_printf("MY: merhaba %p", ptr);
	printf("\n");
	ft_printf("MY: merhaba %x", 99);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:52:14 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/04 15:29:59 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	va_list to_do;
	char spec;
	int len;
	int result;

	result = 0;
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
#include <limits.h>
#include <stdio.h>
int main(void)
{
	int	a = 5;
	int	*ptr = &a;
	printf("%d\n", ft_printf( " %d ", -1));
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
	printf("%d\n", printf("%X\n", 87787));
	ft_printf("%d ", ft_printf("%X ", 87787));
	printf("\n");
	ft_printf("%%");
	printf("\n");
	printf("\n");

	ft_printf(": %d", ft_printf("extraordinary"));
	printf("\n");
	ft_printf("%d", ft_printf("%c: ", 's'));
	printf("\n");
	ft_printf("%d", ft_printf("%s: ", "extiraordinary"));
	printf("\n");
	ft_printf("%d", ft_printf("%p: ", ptr));
	printf("\n");
	ft_printf("%d", ft_printf("%i: ", -8546));
	printf("\n");
	ft_printf("%d", ft_printf("%d: ", 294830));
	printf("\n");
	ft_printf("%d", ft_printf("%u: ", 0257));
	printf("\n");
	ft_printf("%d", ft_printf("%%: "));
	printf("\n");
	printf("\n");

	printf(": %d\n", ft_printf("extraordinary"));
	printf("%d\n", ft_printf("%c: ", 's'));
	printf("%d\n", ft_printf("%s: ", "extiraordinary"));
	printf("%d\n", ft_printf("%p: ", ptr));
	printf("%d\n", ft_printf("%i: ", -8546));
	printf("%d\n", ft_printf("%d: ", 294830));
	printf("%d\n", ft_printf("%u: ", 0257));
	printf("%d\n", ft_printf("%%: "));
}

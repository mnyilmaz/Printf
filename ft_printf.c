/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:52:14 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/04 15:42:31 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	va_list	to_do;
	char	spec;
	int		len;
	int		i;

	len = 0;
	i = 0;
	va_start(to_do, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
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

int sum(int amount, ...)
{
	va_list to_do;
	va_start(to_do, amount);
	int sum = 0;
	int i = 0;
	
	while (i < amount)
	{
		sum += va_arg(to_do, int);
		i++;
	}
	va_end(to_do);
	return(sum);
}

int max(int amount, ...)
{
	va_list to_do;
	va_start(to_do, amount);
	int max = 0;
	int i = 0;
	int current = 0;

	while (i < amount)
	{
		current = va_arg(to_do, int);
		if (current > max)
		{
			max = current;
			current = va_arg(to_do, int);
		}
		else
			max = va_arg(to_do, int);
		i++;
	}
	va_end(to_do);
	return(max);
}

int min(int amount, ...)
{
	va_list to_do;
	va_start(to_do, amount);
	int min = 99999;
	int i = 0;
	int current = 0;

	while (i < amount)
	{
		current = va_arg(to_do, int);
		if (current < min)
			min = current;
		i++;
	}
	va_end(to_do);
	return(min); 
}

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
	
	ft_printf("Sum is: %d\n", sum(2, 1,2,2,3));
	ft_printf("Max is: %d\n", max(2, 5,4,8,10));
	ft_printf("Min is: %d\n", min(2, 1,4,8,10));
}

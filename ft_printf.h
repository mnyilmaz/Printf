/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:32 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 23:55:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

#define BASE "0123456789abcdef"
#define BASE_U "0123456789ABCDEF"
#define DEC "0123456789"
#define LEN 
#define P1  1 //ptr
#define P2  2 //hexa

typedef	struct s_printf
{
	int		len;
	char	spec;
	int		result;
}			t_printf;

int		ft_states(char spec, va_list to_do, t_printf print);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_rest(long long int num, int len, char *base, int point);

#endif

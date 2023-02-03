/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:32 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 14:21:21 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

#define BASE "0123456789abcdef"
#define BASE_U "0123456789ABCDEF"
#define DEC "0123456789"
#define P1  1 //ptr
#define P2  2 //hexa

typedef struct s_print // norma göre s ve t
{
	int		i;
	int		len; //length
	int		res;
	int		point;
	char	specifier;
}				t_print;

int		ft_normal(const char *fmt, va_list to_do, t_print print);
void	ft_states(t_print print, va_list to_do);
int		ft_print_char(char c);
int		ft_print_str(char *s);
int		ft_print_rest(long int num, int len, char *base, int point);
void	ft_cleaner(t_print print);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:01:32 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/04 15:28:45 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

#define BASE "0123456789abcdef"
#define BASE_U "0123456789ABCDEF"
#define DEC "0123456789"
#define MIN -2147483648
#define H_LEN 16
#define D_LEN 10

int		ft_states(char spec, va_list to_do);
int		ft_print_char(char c);
int		ft_strlen(char *s);
int		ft_print_str(char *s);
int    	ft_print_rest(size_t num, size_t base_len, char *base);
void 	ft_cleaner(t_print *print);
int		ft_printf(const char *fmt, ...);
int		ft_print_int(int num);

#endif

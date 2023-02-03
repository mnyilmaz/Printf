/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mervyilm <mervyilm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:52:14 by mervyilm          #+#    #+#             */
/*   Updated: 2023/02/03 14:21:45 by mervyilm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int ft_printf(const char *fmt, ...)
{
	t_print print;
	va_list to_do;

	va_start(to_do, fmt);
	ft_cleaner(print);
	ft_normal(fmt, to_do, print);
	va_end(to_do);
}
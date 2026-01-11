/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:42:44 by souaouri          #+#    #+#             */
/*   Updated: 2023/12/12 10:42:44 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		print_digit(int nb);
int		print_string(char *str);
int		print_character(int c);
int		print_unsigned_int(long n);
int		print_hex_lower(unsigned long n, int base);
int		print_hex_upper(int long n, int base);
int		print_format(char wisthelett, va_list ap);

#endif

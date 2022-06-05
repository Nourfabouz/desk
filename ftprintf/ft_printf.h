/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:26:54 by fabou-za          #+#    #+#             */
/*   Updated: 2022/02/27 15:11:32 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putstr_fd(char *str, int fd);
void	ft_putchar(char c);
int		ft_putnbrunsigned(unsigned int n);
int		ft_putnbr(int n);
int		pointer(unsigned long int n);
int		hexadecimal(unsigned int n, char c);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *s);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:02:33 by fabou-za          #+#    #+#             */
/*   Updated: 2022/05/19 16:02:42 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include<signal.h>
# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_atoi(const char *str);
void	ft_putnbr(unsigned int n);

#endif

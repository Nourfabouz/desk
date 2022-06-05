/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 16:41:58 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/11 18:25:39 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

void ft_putchar_fd(char c, int fd){
	write(fd, &c, 1);
}

int main()
{
	int fd = open("./tst", O_WRONLY | O_CREAT);
	ft_putchar_fd('f', fd);
}

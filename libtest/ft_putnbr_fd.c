#include <unistd.h>
#include <fcntl.h>
#include "libft.h"

void ft_putchar_fd(char c, int fd){
    write(fd, &c, 1);
}

void    ft_putnbr_fd(int n, int fd)
{
    int    sign;

    sign = 1;
    if (n < -9  || n > 9)
        ft_putnbr_fd(n / 10, fd);
    if (n < 0 && n >= -9)
        ft_putchar_fd('-', fd);
    if (n < 0)
        sign = -1;
    ft_putchar_fd((n % 10) * sign + 48, fd);
}

int main(){
	int fd = open("./t", O_WRONLY | O_CREAT);
	int n = -2147483648;
	ft_putnbr_fd(n, fd);
}

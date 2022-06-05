#include <unistd.h>
#include "libft.h"
#include <fcntl.h>

void ft_putendl_fd(char *s, int fd){
	int i;

	i = 0;
	while (s[i]){
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

int main()
{
	char s[] = "abou";
	int n;
	n = open("./str", O_RDWR | O_CREAT);
	ft_putendl_fd(s, n);
}

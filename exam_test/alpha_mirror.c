#include <unistd.h>

int main(int ac, char **av)
{
	int i;
	int count;

	if (ac == 2)
	{
		i = 0;
		while (av[1][i])
		{
			count = 0;
			if (av[1][i] >= 'a' && av[1][i] <= 'm')
			{
				count = av[1][i] - 'a';
				av[1][i] = 'z' - count;
			}
			else if(av[1][i] >= 'n' && av[1][i] <= 'z')
			{
				count = av[1][i] - 'n';
				av[1][i] = 'm' - count;
			}
			if (av[1][i] >= 'A' && av[1][i] <= 'M')
            {
                count = av[1][i] - 'A';
                av[1][i] = 'Z' - count;
            }
			else if(av[1][i] >= 'N' && av[1][i] <= 'Z')
            {
                count = av[1][i] - 'N';
                av[1][i] = 'M' - count;
            }
			write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}

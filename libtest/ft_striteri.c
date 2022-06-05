#include <stdio.h>
#include "libft.h"

void funplus(unsigned int n, char *s){
	*s += n;
}

void ft_striteri(char *s, void (*f)(unsigned int, char	*)){
	
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i]){
		f(i, &s[i]);
		i++;
	}
}

int main(){
	char s[] = "0123ab";
	ft_striteri(s, funplus);
	printf("%s", s);
}

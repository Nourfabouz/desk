# include"libft.h"

int ft_isalnum(int n){
	if ((n>='0' && n<= '9') || (n>= 'A' && n<= 'Z') || (n>= 'a' && n<= 'z'))
		return 1;
	else
		return 0; 
}

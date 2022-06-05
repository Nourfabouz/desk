/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabou-za <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:09:49 by fabou-za          #+#    #+#             */
/*   Updated: 2021/12/08 18:11:36 by fabou-za         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len);
int rowscal(char *s, char c);

char *ft_substr(char const *s, unsigned int start, size_t len){
	char *ptr;
	unsigned long i;
	unsigned long j;

	if (!s || start >= strlen(s))
		return NULL;
	ptr = (char *) malloc((len + 1) * sizeof(char));
	if ( ptr == NULL)
		return NULL;
	i = start;
	j = 0;
	while (j < len && s[i] != '\0'){
		ptr[j] = s[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

int rowscal(char *s, char c)
{
	int i;
	int rows;

	i = 0;
	rows = 0;
	while (s[i])
	{
		if ((s[i] != c && s[i]) && (s[i+1] == c || s[i+1] =='\0'))
			rows += 1;
		i++;
	}
	return (rows);
}

char *storestring(char *s, char c, int *incr)
{
	char	*pt;
	int		cols;
	int 	pos;
	//int 	j;

	cols = 0;
	pos = *incr;
	//j = *incr;
	while (s[*incr] != c && s[*incr])
	{
		cols++;
		//j++;
		(*incr)++;
	}
	pt = ft_substr(s, pos, cols);
	return (pt);
}
char	**checker(char **p)
{
	int i;
	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char **ft_split(char const *s, char c){
	char **ptr;
	int i;
	int j;
	int rows;

	rows = rowscal((char *) s, c);
	printf("rows are %d\n", rows);
	ptr = (char **) malloc((rows + 1) * sizeof(char *));
	if (ptr == NULL)
		return NULL;
	i = 0;
	j = 0;
	while (i < rows)
	{
		while (s[j] == c)
			j++;
		ptr[i] = storestring((char *) s, c, &j);
		if (ptr[i] == NULL)
		{
			//i = 0;
			//while (ptr[i])
			//{
			//	free(ptr[i]);
			//	i++;
			//}
		//	checker(ptr);
			return (checker(ptr));
		}
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

int main(){
	char	**ptr;
	int		i;
	char s[] = "split   ||this|for|me!";
	char c = '|';

	ptr = ft_split(s, c);
	i = 0;
	while (ptr && ptr[i])
	{
		printf("%s\n", ptr[i]);
		i++;
	}
}

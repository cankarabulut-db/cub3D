#include "cub3d.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if(!s1 || !s2)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

int ft_exist(char *str,char a)
{
	int i = 0;
	while(str[i])
	{
		if(str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

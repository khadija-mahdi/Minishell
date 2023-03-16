#include "exec.h"

int ft_strcmp(char *s1, char *s2)
{
	int i = 0;
	
	while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{	
		i++;
	}
	return (s1[i] - s2[i]);

}

void	exit_msg(char *msg, int i)
{
	printf("%s", msg);
	exit(i);
}
void	ft_swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int	f_isdigit(int c)
{
	if (c >= '0' && c <= '8')
		return (1);
	return (0);
}

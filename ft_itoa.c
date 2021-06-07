#include "libft.h"
#include <stdlib.h>

static int	ft_nlen(int n)
{
	int		x;

	x = 0;
	if (n <= 0)
		x++;
	while (n != 0)
	{
		n /= 10;
		x++;
	}
	return (x);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		l;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_nlen(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	str[l] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n)
	{
		l--;
		str[l] = (n % 10) + 48;
		n /= 10;
	}
	return (str);
}

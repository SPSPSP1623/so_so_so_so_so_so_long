#include "so_long.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		s++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n < 0 && n != -2147483648)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	if (n != -2147483648)
		ft_putchar_fd((n % 10) + '0', fd);
}

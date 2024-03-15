/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:34:55 by pepaloma          #+#    #+#             */
/*   Updated: 2023/02/14 21:34:56 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (!(n < 10 && n >= 0))
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}
/*
int	main(void)
{
	int	fd;
	int	n = 9;

	fd = open("a1.txt", O_RDWR);
	if (fd == -1)
	{
		printf("OH FUCK\n");
		printf("%d", errno);
		return (-1);
	}
	ft_putnbr_fd(n, fd);
	close(fd);
	return (0);
}
*/

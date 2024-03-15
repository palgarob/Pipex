/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:50:29 by pepaloma          #+#    #+#             */
/*   Updated: 2023/10/25 16:50:31 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_dec(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		write_dec(n / 10);
	write(1, &DECIMAL[n % 10], 1);
}

int	ft_print_dec(int n)
{
	int	i;

	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	write_dec(n);
	if (n < 0)
		i = 1;
	else
		i = 0;
	while (n / 10)
	{
		i++;
		n /= 10;
	}
	return (i + 1);
}

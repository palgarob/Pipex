/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:15:03 by pepaloma          #+#    #+#             */
/*   Updated: 2023/10/24 16:15:04 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_hex_lo(unsigned long long n)
{
	if (n >= 16)
		write_hex_lo(n / 16);
	write(1, &HEXADECIMAL_LO[n % 16], 1);
}

int	ft_print_ptr(void *ptr)
{
	unsigned long long	p;
	int					i;

	i = 0;
	p = (unsigned long long)ptr;
	write(1, "0x", 2);
	write_hex_lo(p);
	while (p / 16)
	{
		p /= 16;
		i++;
	}
	return (i + 3);
}

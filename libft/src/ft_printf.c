/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepaloma <pepaloma@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:10:25 by pepaloma          #+#    #+#             */
/*   Updated: 2023/10/06 18:10:35 by pepaloma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_arg(va_list ptr, char *pc)
{
	if (*(pc + 1) == 'c')
		return (ft_print_char(va_arg(ptr, int)));
	if (*(pc + 1) == 's')
		return (ft_print_str(va_arg(ptr, char *)));
	if (*(pc + 1) == 'x')
		return (ft_print_hex(va_arg(ptr, int), 0));
	if (*(pc + 1) == 'X')
		return (ft_print_hex(va_arg(ptr, int), 1));
	if (*(pc + 1) == 'p')
		return (ft_print_ptr(va_arg(ptr, void *)));
	if (*(pc + 1) == 'd' || *(pc + 1) == 'i')
		return (ft_print_dec(va_arg(ptr, int)));
	if (*(pc + 1) == 'u')
		return (ft_print_uns(va_arg(ptr, unsigned int)));
	if (*(pc + 1) == '%')
	{
		write(1, "\%", 1);
		return (1);
	}
	else
		return (0);
}

static int	write_format(const char *format, va_list ptr)
{
	int		n;
	char	*pc;

	n = 0;
	pc = ft_strchr(format, '%');
	while (pc)
	{
		n += pc - format;
		write(1, format, pc - format);
		n += print_arg(ptr, pc);
		format = pc + 2;
		pc = ft_strchr(format, '%');
	}
	write(1, format, ft_strlen(format));
	n += ft_strlen(format);
	return (n);
}

int	ft_printf(char const *format, ...)
{
	va_list	ptr;
	int		n;

	n = 0;
	if (ft_strchr(format, '%'))
	{
		va_start(ptr, format);
		n = write_format(format, ptr);
		va_end(ptr);
	}
	else
	{
		write(1, format, ft_strlen(format));
		n = ft_strlen(format);
	}
	return (n);
}

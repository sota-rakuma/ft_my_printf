/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:36:31 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/09 20:44:59 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_vprintf(char const *format, va_list ap)
{
	int		rv;
	char	*buff;
	char	*first;

	buff = (char *)malloc(sizeof(char *) * BUFFER_SIZE);
	if (!buff)
		return (-1);
	first = buff;
	rv = 0;
	while (*format && rv != -1)
	{
		if (*format == '%')
			rv = ft_proc_per(&format, ap, &buff, first);
		else
			*(buff++) = *(format++);
		if (buff - first == BUFFER_SIZE)
			rv = ft_flush(&buff, first, rv);
	}
	*buff = '\0';
	if (rv != -1)
		rv += write(1, first, buff - first);
	free(first);
	return (rv);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	int		rv;

	va_start(ap, format);
	rv = ft_vprintf(format, ap);
	va_end(ap);
	return (rv);
}

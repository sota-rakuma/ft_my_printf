/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_transision_of_integer.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 17:59:49 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/09 18:34:19 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	int				digit;
	int				i;
	unsigned int	tmp;
	char			*ptr;

	tmp = 1;
	digit = ft_count_digit((long int)num, 10);
	ptr = (char *)malloc(sizeof(char) * digit + 1);
	if (!ptr)
		return (NULL);
	ptr[digit] = '\0';
	while (digit-- > 1)
		tmp *= 10;
	i = 0;
	while (tmp)
	{
		ptr[i++] = num / tmp + '0';
		num %= tmp;
		tmp /= 10;
	}
	return (ptr);
}

char	*ft_xtoa(long int num, char *nbr)
{
	int			digit;
	int			i;
	long int	tmp;
	char		*ptr;

	tmp = 1;
	digit = ft_count_digit(num, 16);
	ptr = (char *)malloc(sizeof(char) * digit + 1);
	if (!ptr)
		return (NULL);
	ptr[digit] = '\0';
	while (digit-- > 1)
		tmp *= 16;
	i = 0;
	while (tmp)
	{
		if (num / tmp - 10 < 0)
			ptr[i++] = (num / tmp) + '0';
		else
			ptr[i++] = nbr[num / tmp - 10];
		num %= tmp;
		tmp /= 16;
	}
	return (ptr);
}

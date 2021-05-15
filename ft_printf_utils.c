/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:14:24 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/09 18:36:10 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flush(char **buff, char *first, int len)
{
	int	tmp;

	*buff = first;
	tmp = len;
	len += (int)write(1, first, BUFFER_SIZE);
	if (len < tmp)
		return (-1);
	return (len);
}

int	ft_fmtchr(char const *str, char c, t_format *f_format)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] == c)
		{
			if (*str == 'c')
				f_format->specifier[i] = 1;
			else
				f_format->flag[i] = 1;
			return (1);
		}
	}
	return (0);
}

int	ft_count_digit(long int num, int base)
{
	int	digit;

	digit = 0;
	if (num <= 0)
		digit++;
	while (num)
	{
		digit++;
		num /= base;
	}
	return (digit);
}

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*proc_field(char *str, char ch, int diff, int flag)
{
	char	*tmp;
	char	*heap;

	tmp = str;
	heap = (char *)malloc(sizeof(char) * diff + 1);
	if (!heap)
		return (NULL);
	ft_memset(heap, ch, diff);
	if (ch == '0' && *str == '-')
		ft_swap(heap, str);
	heap[diff] = '\0';
	if (flag)
		str = ft_strjoin(heap, tmp);
	else
		str = ft_strjoin(tmp, heap);
	free(heap);
	return (str);
}

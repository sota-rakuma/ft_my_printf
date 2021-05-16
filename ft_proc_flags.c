/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:21:29 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/16 15:20:45 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_proc_char_field(t_format *f_spec, char obj, int len, char ch)
{
	char	*str;
	char	*tmp;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	tmp = str;
	if (f_spec->flag[0])
	{
		*tmp++ = obj;
		while (len-- > 1)
			*tmp++ = ch;
	}
	else
	{
		while (len-- > 1)
			*tmp++ = ch;
		*tmp = obj;
	}
	return (str);
}

char	*ft_tailgate(t_format *f_spec, char *str, int diff)
{
	char	*tmp;

	tmp = str;
	if (f_spec->specifier[0] && f_spec->flag[4])
		str = ft_proc_char_field(f_spec, *tmp, f_spec->width, '0');
	else if (f_spec->specifier[0])
		str = ft_proc_char_field(f_spec, *tmp, f_spec->width, ' ');
	else if (f_spec->flag[0])
		str = proc_field(tmp, ' ', diff, 0);
	else if (f_spec->flag[4])
		str = proc_field(tmp, '0', diff, 1);
	else
		str = proc_field(tmp, ' ', diff, 1);
	free(tmp);
	return (str);
}

int	ft_relay_tailgate(t_format *f_spec, char **str)
{
	size_t	len;
	int		diff;

	if (!f_spec->specifier[0])
		len = ft_strlen(*str);
	else
		len = 1;
	diff = f_spec->width - len;
	if (diff <= 0)
		return ((int)len);
	*str = ft_tailgate(f_spec, *str, diff);
	return ((int)(len + diff));
}

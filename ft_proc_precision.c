/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 18:21:09 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/14 21:16:52 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_proc_num_prcn(char *str, t_format *f_spec)
{
	char	*tmp;
	int		diff;

	diff = f_spec->prcn - (int)ft_strlen(str);
	if (*str == '-')
		diff++;
	if (str && 0 < diff)
		str = proc_field(str, '0', diff, 1);
	if (f_spec->prcn != -1)
		f_spec->flag[4] = 0;
	if (f_spec->specifier[2])
	{
		tmp = str;
		str = ft_strjoin("0x", tmp);
		free(tmp);
	}
	return (str);
}

static char	*get_int(t_format *f_spec, long int num)
{
	char	*str;

	if (num == 0 && f_spec->prcn == 0)
	{
		f_spec->flag[4] = 0;
		if (f_spec->specifier[2])
			return (ft_strdup("0x"));
		return (ft_strdup(""));
	}
	else if (f_spec->specifier[3] || f_spec->specifier[4])
		str = ft_itoa((int)num);
	else if (f_spec->specifier[5])
		str = ft_utoa((unsigned int)num);
	else if (f_spec->specifier[2] || f_spec->specifier[6])
		str = ft_xtoa(num, "abcdef");
	else
		str = ft_xtoa(num, "ABCDEF");
	str = ft_proc_num_prcn(str, f_spec);
	return (str);
}

static char	*ft_proc_str_prcn(va_list ap, t_format *f_spec)
{
	char	*str;
	char	*tmp;
	int		len;

	if (f_spec->specifier[0])
	{
		str = (char *)ft_calloc(2, sizeof(char));
		str[0] = (char)va_arg(ap, int);
		return (str);
	}
	str = (void *)va_arg(ap, void *);
	if (!str)
		str = ft_strdup("(null)");
	else
		str = ft_strdup((char *)str);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	if (f_spec->prcn != -1 && f_spec->prcn < (int)len)
	{
		tmp = str;
		str = ft_substr(tmp, 0, (size_t)f_spec->prcn);
		free(tmp);
	}
	return (str);
}

char	*ft_get_str_with_prcn(va_list ap, t_format *f_spec)
{
	char	*str;

	if (f_spec->specifier[8])
		return (ft_strdup("%"));
	else if (f_spec->specifier[0] || f_spec->specifier[1])
		str = ft_proc_str_prcn(ap, f_spec);
	else
		str = get_int(f_spec, (long int)va_arg(ap, long int));
	return (str);
}

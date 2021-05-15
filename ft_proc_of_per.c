/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_proc_of_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:11:23 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/16 00:41:48 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_init_t_fmt(t_format *f_spec)
{
	int			i;
	int			j;

	i = -1;
	while (++i < 5)
		f_spec->flag[i] = 0;
	f_spec->width = 0;
	f_spec->prcn = -1;
	j = -1;
	while (++j < 9)
		f_spec->specifier[j] = 0;
}

static int	ft_get_num_in_fmt(const char **fmt, va_list ap, t_format *f_spec)
{
	int	num;
	int	flag;

	num = 0;
	flag = 0;
	if (*(*fmt) == '.')
	{
		flag = 1;
		(*fmt)++;
	}
	while (ft_isdigit(*(*fmt)))
	{
		num = num * 10 + (*(*fmt) - '0');
		(*fmt)++;
	}
	if (flag && num > 0 && *(*fmt) == '*')
		f_spec->width = num;
	if (*(*fmt) == '*')
	{
		num = (int)va_arg(ap, int);
		(*fmt)++;
	}
	return (num);
}

static int	store_data(t_format *f_spec, char **buff, char *first, va_list ap)
{
	int		rv;
	char	*str;
	char	*tmp;
	int		len;

	rv = 0;
	str = ft_get_str_with_prcn(ap, f_spec);
	if (f_spec->width < 0)
	{
		f_spec->flag[0] = 1;
		f_spec->width *= -1;
	}
	len = ft_relay_tailgate(f_spec, &str);
	if (!str)
		return (-1);
	tmp = str;
	while (len-- > 0)
	{
		if (*buff - first == BUFFER_SIZE)
			rv = ft_flush(buff, first, rv);
		*((*buff)++) = *str++;
	}
	free(tmp);
	return (rv);
}

int	ft_proc_per(char const **format, va_list ap, char **buff, char *first)
{
	int			rv;
	t_format	f_spec;

	rv = 0;
	ft_init_t_fmt(&f_spec);
	(*format)++;
	while (ft_fmtchr("-+ #0", *(*format), &f_spec))
		(*format)++;
	while (ft_isdigit(*(*format)) || *(*format) == '*')
		f_spec.width = ft_get_num_in_fmt(format, ap, &f_spec);
	if (*(*format) == '.')
	{
		f_spec.prcn = ft_get_num_in_fmt(format, ap, &f_spec);
		if (f_spec.prcn < -1)
			f_spec.prcn = -1;
	}
	if (!ft_fmtchr("cspdiuxX%", *((*format)++), &f_spec))
		return (-1);
	rv = store_data(&f_spec, buff, first, ap);
	return (rv);
}

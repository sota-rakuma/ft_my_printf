/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 17:37:22 by srakuma           #+#    #+#             */
/*   Updated: 2021/05/14 21:20:45 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 1024 //in stdio.h

# endif

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <float.h>
# include "libft/libft.h"

typedef struct s_format
{
	int	flag[5];
	int	width;
	int	prcn;
	int	specifier[9];
}				t_format;

int		ft_printf(char const *format, ...);
int		ft_proc_per(char const **format, va_list ap, char **buff, char *first);
int		ft_flush(char **buff, char *first, int len);
int		ft_fmtchr(char const *str, char c, t_format *f_format);
int		ft_count_digit(long int num, int base);
char	*ft_utoa(unsigned int num);
char	*ft_xtoa(long int num, char *nbr);
int		ft_relay_tailgate(t_format *f_spec, char **str);
char	*ft_get_str_with_prcn(va_list ap, t_format *f_spec);
void	ft_swap(char *a, char *b);
char	*proc_field(char *str, char ch, int diff, int flag);

#endif
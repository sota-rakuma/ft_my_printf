/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srakuma <srakuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:10:54 by srakuma           #+#    #+#             */
/*   Updated: 2021/04/28 00:05:00 by srakuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = ft_strlen(s) + 1;
	ch = (char)c;
	while (i-- > 0)
	{
		if (*s == ch)
			return ((char *)s);
		s++;
	}
	return (0);
}

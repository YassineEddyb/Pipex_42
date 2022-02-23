/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:43:14 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/18 19:57:33 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	a;

	if (!s)
		return (NULL);
	i = 0;
	a = c;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == a)
			return (&((char *)s)[i]);
		i++;
	}
	return (0);
}

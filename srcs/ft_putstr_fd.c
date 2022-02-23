/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:31:00 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/18 11:41:22 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.h"

void	ft_putstr_fd(char *str, int fd)
{
	int		index;

	if (!str)
		return ;
	index = 0;
	while (str[index] != '\0')
	{
		ft_putchar_fd(str[index], fd);
		index++;
	}
}

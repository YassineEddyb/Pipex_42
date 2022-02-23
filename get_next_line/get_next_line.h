/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 10:25:50 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/18 11:53:35 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../srcs/lib.h"
# include<stdlib.h>
# include<unistd.h>

char	*ft_str_join(char *s1, char *s2);
int		has_new_line(char *s);
char	*get_next_line(int fd);

#endif

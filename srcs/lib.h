/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 19:58:12 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/21 15:07:49 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_putchar_fd(char c, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_replace(char *s, char rm, char rp);

#endif
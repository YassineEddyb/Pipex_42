/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:56:42 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/21 14:31:20 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "srcs/lib.h"
# include "get_next_line/get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_cmd {
	char	*path;
	char	**args;
	int		p[2];
	int		pid;
}	t_cmd;

typedef struct s_data {
	char	**arr;
	char	*input;
	char	*output;
	char	*limit;
	int		p[2];
	int		size;
}	t_data;

void	ft_putstr_fd(char *str, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	close_unused_pipes(t_cmd *cmd, int process_index, int size);
void	close_all_pipes(t_cmd *cmd, int size);
void	wait_all_child_processors(t_cmd *cmd, int size);
void	get_path(t_cmd *cmd, char **arr, char *command, int i);
void	read_form_stdout(char *limit, int fd);
void	handle_input(t_data *data, t_cmd *cmd, int i);
int		compare_strings(char *s1, char *s2);
void	check_path(t_cmd *cmd, int i);
int		look_for_paths_index(char **env);
void	get_args(t_cmd *cmd, char **av, int i);

#endif
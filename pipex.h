/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:56:42 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/12 19:43:11 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
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

void	close_unused_pipes(t_cmd *cmd, int process_index, int size);
void	close_all_pipes(t_cmd *cmd, int size);
void	wait_all_child_processors(t_cmd *cmd, int size);
void	get_path(t_cmd *cmd, char **arr, char *command, int i);
void	read_form_stdout(char *limit, int *p);
void	handle_input(t_data *data, t_cmd *cmd, int i);
int		open_file(char *path);
int		compare_strings(char *s1, char *s2);

#endif
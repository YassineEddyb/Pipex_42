/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:46:47 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/12 19:41:16 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	read_form_stdout(char *limit, int *p)
{
	char	*line;

	while (ft_strncmp(limit, line, ft_strlen(line)))
	{
		write(p[1], line, ft_strlen(line));
		line = get_next_line(1);
	}
}

void	close_unused_pipes(t_cmd *cmd, int process_index, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != process_index - 1)
			close(cmd[i].p[0]);
		if (i != process_index)
			close(cmd[i].p[1]);
		i++;
	}
}

void	close_all_pipes(t_cmd *cmd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		close(cmd[i].p[0]);
		close(cmd[i].p[1]);
		i++;
	}
}

void	wait_all_child_processors(t_cmd *cmd, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		waitpid(cmd[i].pid, 0, 0);
		i++;
	}
}

void	get_path(t_cmd *cmd, char **arr, char *command, int i)
{
	int		j;
	int		a;
	char	*path;

	if (!arr)
		return ;
	j = 0;
	while (arr[j])
	{
		path = ft_strjoin(arr[j], command);
		a = access(path, F_OK);
		if (a == 0)
		{
			cmd[i].path = path;
			break ;
		}
		free(path);
		j++;
	}
	if (!cmd[i].path)
		cmd[i].path = cmd[i].args[0];
}

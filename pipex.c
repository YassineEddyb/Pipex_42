/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:46:52 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/12 19:43:02 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path_and_args(t_cmd *cmd, char **av, t_data *data)
{
	int		i;
	char	*command;

	if (compare_strings(av[1], "here_doc"))
	{
		data->size--;
		data->limit = ft_strjoin(av[2], "\n");
		av++;
	}
	av += 2;
	i = 0;
	while (i < data->size)
	{
		pipe(cmd[i].p);
		cmd[i].args = ft_split(av[i], ' ');
		command = ft_strjoin("/", cmd[i].args[0]);
		get_path(cmd, data->arr, command, i);
		free(command);
		i++;
	}
}

void	dup_all(t_cmd *cmd, t_data *data, int i)
{
	int	fd;

	pipe(data->p);
	if (i == 0)
	{
		handle_input(data, cmd, i);
	}
	else if (i == data->size - 1)
	{
		fd = open(data->output, O_RDWR | O_CREAT, 0777);
		if (fd < 0)
		{
			perror("Error: ");
			exit(1);
		}
		dup2(cmd[i - 1].p[0], 0);
		dup2(fd, 1);
	}
	else
	{
		dup2(cmd[i - 1].p[0], 0);
		dup2(cmd[i].p[1], 1);
	}
}

int	look_for_paths_index(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH=", env[i], 5) == 0)
			break ;
		i++;
	}
	return (i);
}

void	execute_commands(t_data *data, t_cmd *cmd, char **env)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		cmd[i].pid = fork();
		if (cmd[i].pid == 0)
		{
			close_unused_pipes(cmd, i, data->size);
			dup_all(cmd, data, i);
			if (execve(cmd[i].path, cmd[i].args, env) == -1)
				perror("Error");
			exit(1);
		}
		i++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_cmd	*cmd;
	t_data	data;
	int		i;
	char	*path;
	char	*str;

	str = ft_substr(env[look_for_paths_index(env)], 5, ft_strlen(env[6]));
	data.arr = ft_split(str, ':');
	data.input = av[1];
	data.output = av[ac - 1];
	data.size = ac - 3;
	cmd = malloc((ac - 3) * sizeof(t_cmd));
	get_path_and_args(cmd, av, &data);
	execute_commands(&data, cmd, env);
	close_all_pipes(cmd, ac - 3);
	wait_all_child_processors(cmd, ac - 3);
}

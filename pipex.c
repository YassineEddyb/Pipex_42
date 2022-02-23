/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:46:52 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/21 18:36:21 by yed-dyb          ###   ########.fr       */
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
		av++;
	}
	av += 2;
	i = 0;
	while (i < data->size)
	{
		pipe(cmd[i].p);
		get_args(cmd, av, i);
		command = ft_strjoin("/", cmd[i].args[0]);
		get_path(cmd, data->arr, command, i);
		free(command);
		i++;
	}
}

void	dup_all(t_cmd *cmd, t_data *data, int i)
{
	int	fd;

	if (i == 0)
		handle_input(data, cmd, i);
	else if (i == data->size - 1)
	{
		if (!compare_strings(data->input, "here_doc"))
			fd = open(data->output, O_CREAT | O_RDWR | O_TRUNC, 0664);
		else
			fd = open(data->output, O_RDWR | O_CREAT | O_APPEND, 0664);
		if (fd < 0)
		{
			perror("./pipex");
			exit(1);
		}
		dup2(cmd[i - 1].p[0], 0);
		dup2(fd, 1);
		close(cmd[i].p[1]);
	}
	else
	{
		dup2(cmd[i - 1].p[0], 0);
		dup2(cmd[i].p[1], 1);
	}
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
			check_path(cmd, i);
			if (execve(cmd[i].path, cmd[i].args, env) == -1)
				perror("./pipex");
			exit(1);
		}
		i++;
	}
}

void	here_doc(t_data *data, char **av)
{
	int	fd;

	if (compare_strings(data->input, "here_doc"))
	{
		data->limit = ft_strjoin(av[2], "\n");
		fd = open("/tmp/.temp", O_RDWR | O_CREAT | O_TRUNC, 0664);
		read_form_stdout(data->limit, fd);
		free(data->limit);
		close(fd);
	}
}

int	main(int ac, char **av, char **env)
{
	t_cmd	*cmd;
	t_data	data;
	char	*str;

	if (ac < 5)
		exit(1);
	str = ft_substr(env[look_for_paths_index(env)], 5, ft_strlen(env[6]));
	data.arr = ft_split(str, ':');
	free(str);
	data.input = av[1];
	data.output = av[ac - 1];
	data.size = ac - 3;
	cmd = malloc((data.size) * sizeof(t_cmd));
	if (!cmd)
		return (1);
	here_doc(&data, av);
	get_path_and_args(cmd, av, &data);
	execute_commands(&data, cmd, env);
	close_all_pipes(cmd, data.size);
	wait_all_child_processors(cmd, data.size);
}

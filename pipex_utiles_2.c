/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utiles_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yed-dyb <yed-dyb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:37:10 by yed-dyb           #+#    #+#             */
/*   Updated: 2022/02/12 19:43:14 by yed-dyb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_input(t_data *data, t_cmd *cmd, int i)
{
	int	fd;

	if (compare_strings(data->input, "here_doc"))
	{
		read_form_stdout(data->limit, data->p);
		dup2(data->p[0], 0);
		close(data->p[1]);
	}
	else
	{
		fd = open_file(data->input);
		dup2(fd, 0);
	}
	dup2(cmd[i].p[1], 1);
}

int	open_file(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY, 0777);
	if (fd < 0)
	{
		perror("Error: ");
		exit(1);
	}
	return (fd);
}

int	compare_strings(char *s1, char *s2)
{
	int	len;

	if (ft_strlen(s1) > ft_strlen(s2))
		len = ft_strlen(s1);
	else
		len = ft_strlen(s2);
	if (!ft_strncmp(s1, s2, len))
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:23:25 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/06 12:21:42 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	return (envp[i] + 5);
}

char	*get_command(char **env_paths, char *cmd)
{
	char	*temp;
	char	*command;

	while (*env_paths)
	{
		temp = ft_strjoin(*env_paths, "/");
		command = ft_strjoin(temp, cmd);
		free(temp);
		if (access(command, F_OK | X_OK) == 0)
			return (command);
		free(command);
		env_paths++;
	}
	return (NULL);
}

void	free_parent(t_ppx *ppx)
{
	int	i;

	i = 0;
	close(ppx->infile_fd);
	close(ppx->outfile_fd);
	while (ppx->cmd_paths[i])
	{
		free(ppx->cmd_paths[i]);
		i++;
	}
	free(ppx->cmd_paths);
}

void	close_ends(t_ppx *ppx)
{
	close(ppx->end[1]);
	close(ppx->end[0]);
}

void	ppx_error(char *err)
{
	perror(err);
	exit(EXIT_FAILURE);
}

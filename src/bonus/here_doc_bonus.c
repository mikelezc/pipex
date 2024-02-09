/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:48:48 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/08 18:46:25 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

int	args_eval(char *argv, t_bnsppx *bppx)
{
	if (ft_strncmp(argv, "here_doc", 8) == 0)
	{
		bppx->heredoc = 1;
		return (6);
	}
	else
	{
		bppx->heredoc = 0;
		return (5);
	}
}

void	here_doc(char *argv, t_bnsppx *bppx)
{
    int		temp_fd;
    int		stdin_fd;
	char	*line;

	temp_fd = open(".heredoc.temp", O_TRUNC | O_CREAT | O_WRONLY, 0644);
	stdin_fd = dup(STDIN_FILENO);
	if (temp_fd < 0)
		ppx_exit_error(ERROR_HRD);
	line = "";
	while(1)
	{
		ft_putstr_fd("here_doc> ", 1);
		line = get_next_line(stdin_fd);
		if (line == NULL)
			break ;
		if (!ft_strncmp(argv, line, ft_strlen(argv + 1)))
			close(stdin_fd);
		else 
			ft_putstr_fd(line, temp_fd);
		free(line);
	}
	close(temp_fd);
}
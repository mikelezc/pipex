/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:05:33 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/09 12:50:51 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	get_infile(char **argv, t_bnsppx *bppx)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		here_doc(argv[2]);
		bppx->infile = open(".heredoc.temp", O_RDONLY);
		if (bppx->infile < 0)
		{
			unlink(".heredoc.temp");
			ppx_exit_error(ERROR_HRD);
		}
	}
	else
	{
		bppx->infile = open(argv[1], O_RDONLY);
		if (bppx->infile < 0)
			ppx_exit_error(ERROR_INF);
	}
}

void	get_outfile(char *argv, t_bnsppx *bppx)
{
	if (bppx->heredoc)
		bppx->outfile = open(argv, O_APPEND | O_CREAT | O_WRONLY, 0644);
	else
		bppx->outfile = open(argv, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (bppx->outfile < 0)
		ppx_exit_error(ERROR_OUT);
}

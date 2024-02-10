/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:20:25 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/10 13:24:28 by mlezcano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//libraries
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"
# include "../libft/inc/get_next_line.h"

//error message macros
# define ERROR_ARG "Error: incorrect number of arguments\n"
# define ERROR_CMD "Error: Command not found\n"
# define ERROR_EXE "Execve Error\n"
# define ERROR_FRK "Fork Error\n"
# define ERROR_INF "Infile Error\n"
# define ERROR_OUT "Outfile Error\n"
# define ERROR_PIP "Pipe Error\n"
# define ERROR_HRD "Here_doc Error\n"
# define ERROR_ENV "Enviroment Error\n"

//storage structure
typedef struct s_ppxbonus
{
	int		infile_fd;
	int		outfile_fd;
	int		here_doc;
	char	*path;
	char	**cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_nbs;
	int		pipe_nbs;
	int		*end;
	int		index;
	pid_t	pid;
}	t_bnsppx;

//pipex_bppx (main)
void	bppx_welding_pipes(t_bnsppx *bppx);
void	bppx_close_end(t_bnsppx *bppx);

//utils_bppx
char	*bppx_search_paths(char **envp);
char	*get_command(char **env_paths, char *cmd);
void	bppx_exit_error(char *err);

//childs_bppx
void	bppx_dup2(int zero, int one);
void	bppx_born_child(t_bnsppx bppx, char **argv, char **envp);

//in_out_bppx
void	bppx_infile_fd(char **argv, t_bnsppx *bppx);
void	bppx_outfile_fd(char *argv, t_bnsppx *bppx);

//here_doc_bppx
int		bppx_is_here_doc(char *argv, t_bnsppx *bppx);
void	bppx_here_doc(char *argv);

//free_bppx
void	bppx_final_pipe(t_bnsppx *bppx);
void	free_child(t_bnsppx *bppx);
void	bppx_final_parent(t_bnsppx *bppx);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:20:25 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/17 11:54:19 by mlezcano         ###   ########.fr       */
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
	char	*raw_cmd_paths;
	char	**cut_cmd_paths;
	char	**cmd_args;
	char	*cmd;
	int		cmd_amnt;
	int		pipe_ends_amnt;
	int		*pipe_ends_fd;
	pid_t	pid;
}	t_bnsppx;

//bppx_pipex (main)
int		bppx_valid_argc(char *argv, t_bnsppx *bppx);

//bppx_fd_handling
void	bppx_outfile_fd(char *outfile, t_bnsppx *bppx);
void	bppx_infile_fd(char **argv, t_bnsppx *bppx);
void	bppx_fd_handling(int argc, char **argv, t_bnsppx *bppx);

//bppx_fd_handling
void	bppx_here_doc(char *limiter);
int		bppx_here_doc_create_tmp(void);

//bppx_cmds
void	bppx_dup2(int std_in, int std_out);
char	*bppx_polish_cmd(char **env_paths, char *cmd);
void	bppx_born_child(char **argv, char **envp, t_bnsppx bppx, int i);
void	bppx_search_paths(char **envp, t_bnsppx *bppx);
void	bppx_cmds(char **argv, char **envp, t_bnsppx bppx);

//bppx_pipe
void	bppx_make_pipes(t_bnsppx *bppx);
void	bppx_cut_pipes(t_bnsppx *bppx);

//bppx_ends
void	bppx_exit_error(char *err);
void	bppx_free_pipe(t_bnsppx *bppx);
void	bppx_free_child(t_bnsppx *bppx);
void	bppx_free_parent(t_bnsppx *bppx);

#endif
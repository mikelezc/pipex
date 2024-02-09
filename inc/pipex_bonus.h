/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlezcano <mlezcano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:20:25 by mlezcano          #+#    #+#             */
/*   Updated: 2024/02/08 19:06:07 by mlezcano         ###   ########.fr       */
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
	int		infile;
	int		outfile;
	int		heredoc;
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

//pipex_bonus (main)
void	close_ends(t_bnsppx *bppx);

//utils_bonus
char	*get_path(char **envp);
char	*get_command(char **env_paths, char *cmd);
void	ppx_exit_error(char *err);

//child_bonus
void	child(t_bnsppx bppx, char **argv, char **envp);

//files_bonus
void	get_infile(char **argv, t_bnsppx *bppx);
void	get_outfile(char *argv, t_bnsppx *bppx);

//here_doc_bonus
int		args_eval(char *argv, t_bnsppx *bppx);
void	here_doc(char *argv, t_bnsppx *bppx);

//free_bonus
void	free_pipe(t_bnsppx *bppx);
void	free_child(t_bnsppx *bppx);
void	free_parent(t_bnsppx *bppx);

#endif
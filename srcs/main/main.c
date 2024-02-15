/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:00:47 by yrio              #+#    #+#             */
/*   Updated: 2024/02/15 13:37:03 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		**args_split;
	char		*line;

	(void)argc;
	(void)argv;
	malloc_env(&minishell, env);
	write(0, "minishell$ ", 11);
	line = get_next_line(0);
	while (line)
	{	
		args_split = ft_split(line, ' ');
		if (!ft_strncmp(args_split[0], "cd", 2) && \
			(ft_strlen(args_split[0]) == ft_strlen("cd") || \
			ft_strlen(args_split[0]) - 1 == ft_strlen("cd")))
			ft_cd(args_split, &minishell);
		if (!ft_strncmp(args_split[0], "env", 3) && \
			ft_strlen(args_split[0]) - 1 == ft_strlen("env"))
			ft_env(&minishell);
		if (!ft_strncmp(args_split[0], "ls", 2) && \
			ft_strlen(args_split[0]) - 1 == ft_strlen("ls"))
			ls_cmd();
		if (!ft_strncmp(args_split[0], "pwd", 3) && \
			ft_strlen(args_split[0]) - 1 == ft_strlen("pwd"))
			ft_pwd();
		if (!ft_strncmp(args_split[0], "export", 6) && \
			(ft_strlen(args_split[0]) == ft_strlen("export") || \
			ft_strlen(args_split[0]) - 1 == ft_strlen("export")))
			ft_export(args_split, &minishell);
		if (!ft_strncmp(args_split[0], "unset", 5) && \
			ft_strlen(args_split[0]) == ft_strlen("unset"))
			ft_unset(args_split, &minishell);
		if (!ft_strncmp(args_split[0], "echo", 4) && \
			(ft_strlen(args_split[0]) == ft_strlen("echo") || \
			ft_strlen(args_split[0]) - 1 == ft_strlen("echo")))
			ft_echo(args_split);
		if (!ft_strncmp(args_split[0], "exit", 4) && \
			ft_strlen(args_split[0]) - 1 == ft_strlen("exit"))
		{
			free(line);
			free_split(args_split);
			break ;
		}
		free(line);
		free_split(args_split);
		write(0, "minishell$ ", 11);
		line = get_next_line(0);
	}
	lstclear(minishell.lst_envs);
	return (0);
}

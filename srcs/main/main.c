/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:00:47 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 11:30:04 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	main(int argc, char **argv, char **env)
{
	t_minishell	minishell;
	char		*line;

	(void)argc;
	malloc_env(&minishell, env);
	write(0, "minishell$ ", 11);
	line = get_next_line(0);
	while (line)
	{	
		if (!ft_strncmp(line, "cd libft", 8) && \
			ft_strlen(line) - 1 == ft_strlen("cd libft"))
			cd_builtins(argv, &minishell);
		if (!ft_strncmp(line, "env", 3) && \
			ft_strlen(line) - 1 == ft_strlen("env"))
			env_builtins(&minishell);
		if (!ft_strncmp(line, "ls", 2) && \
			ft_strlen(line) - 1 == ft_strlen("ls"))
			ls_cmd();
		if (!ft_strncmp(line, "exit", 4) && \
			ft_strlen(line) - 1 == ft_strlen("exit"))
		{
			free(line);
			break ;
		}
		free(line);
		write(0, "minishell$ ", 11);
		line = get_next_line(0);
	}
	lstclear(minishell.lst_envs);
	return (0);
}

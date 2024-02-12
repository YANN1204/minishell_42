/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:00:47 by yrio              #+#    #+#             */
/*   Updated: 2024/02/12 17:57:02 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	**path_split;
	char	*line;

	path_split = get_paths(env);
	write(0, "minishell$ ", 11);
	line = get_next_line(0);
	while (line)
	{	
		if (!ft_strncmp(line, "cd libft", 8) && \
			ft_strlen(line) - 1 == ft_strlen("cd libft"))
			cd_builtins(argv, env);
		if (!ft_strncmp(line, "env", 3) && \
			ft_strlen(line) - 1 == ft_strlen("env"))
			env_builtins(env);
		if (!ft_strncmp(line, "ls", 2) && \
			ft_strlen(line) - 1 == ft_strlen("ls"))
			ls_cmd();
		write(0, "minishell$ ", 11);
		line = get_next_line(0);
	}
	return (0);
}

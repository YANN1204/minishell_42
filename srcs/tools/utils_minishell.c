/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:37:47 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 07:40:24 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

void	ls_cmd(void)
{
	char *dir_path;
	DIR* rep;
	struct dirent* fichierLU;

	dir_path = NULL;
	rep = NULL;
	fichierLU = NULL;
	dir_path = getcwd(dir_path, PATH_MAX);
	rep = opendir(dir_path);
	if (!rep)
		exit(1);
	fichierLU = readdir(rep);
	while (fichierLU)
	{
		ft_putstr_fd(fichierLU->d_name, 1);
		ft_putchar(' ');
		fichierLU = readdir(rep);
	}
	ft_putchar('\n');
	if (closedir(rep) == -1)
		exit(-1);
}

char	**get_paths(char **env)
{
	char	**path_split;
	char	*path;
	int		tmp;

	tmp = 0;
	path = NULL;
	path_split = NULL;
	while (env[tmp])
	{
		if (!ft_strncmp(env[tmp], "PATH=", 5))
		{
			path = ft_substr(env[tmp], 5, ft_strlen(env[tmp]) - 5);
			if (!path)
				exit(0);
		}
		tmp++;
	}
	path_split = ft_split(path, ':');
	if (!path_split)
		exit(0);
	free(path);
	return (path_split);
}

char	**free_split(char **char_tab)
{
	int	tmp;

	tmp = 0;
	while (char_tab[tmp])
		free(char_tab[tmp++]);
	free(char_tab);
	return (NULL);
}

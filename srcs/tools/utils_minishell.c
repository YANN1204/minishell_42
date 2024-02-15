/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:37:47 by yrio              #+#    #+#             */
/*   Updated: 2024/02/15 07:48:09 by yrio             ###   ########.fr       */
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
	free(dir_path);
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

void	malloc_env(t_minishell *minishell, char **env)
{
	t_envlist	*new;
	t_envlist	*lst;
	int			tmp;
	int			tmp2;

	tmp = 0;
	while (env[tmp])
		tmp++;
	lst = lst_new(env[0]);
	lst->index = 0;
	minishell->lst_envs = lst;
	tmp2 = 1;
	while (tmp2 < tmp)
	{
		new = lst_new(env[tmp2]);
		new->index = tmp2;
		lstadd_back(new, lst);
		tmp2++;
	}
}

// Je vais faire une liste chaine avec tout les elements de env qui sont 
// malloc et je vais split la chaine en 2 avec le '=' et il y aura un attribut
// 'key' et un attribut 'value' dans chaque element de ma liste chaine
// Pour la key 'DBUS_SESSION_BUS_ADDRESS' de l'environnement il y a deux egal
// et donc cela pose un probleme avec le split

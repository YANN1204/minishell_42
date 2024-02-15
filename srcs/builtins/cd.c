/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:25:33 by yrio              #+#    #+#             */
/*   Updated: 2024/02/15 07:46:00 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

void	check_args(char **args_split, t_minishell *minishell)
{
	if (args_split[1])
	{
		if (args_split[2] && args_split[2][0] != '\n')
		{
			ft_putendl_fd("bash: cd: too many arguments", 2);
			exit(0);
		}
	}
	if (!check_env_key(minishell, "PWD"))
	{
		ft_putendl_fd("minishell : cd: PWD not set", 2);
		exit(0);
	}
	if (!check_env_key(minishell, "OLDPWD"))
	{
		ft_putendl_fd("minishell : cd: OLDPWD not set", 2);
		exit(0);
	}
	if (!check_env_key(minishell, "HOME"))
	{
		ft_putendl_fd("minishell : cd: HOME not set", 2);
		exit(0);
	}
}

char	*particular_path(t_minishell *minishell, char *dir_path, int option)
{
	char	*home_path;
	char	*prev_path;
	char	*new_dir_path;
	int		tmp;

	home_path = get_value_env(minishell, "HOME");
	if (option)
	{
		tmp = ft_strlen(dir_path);
		while (tmp > 0)
		{
			if (dir_path[tmp] == '/')
				break ;
			else
				tmp--;
		}
		prev_path = ft_substr(dir_path, 0, tmp);
		new_dir_path = ft_strdup(prev_path);
		new_dir_path[ft_strlen(new_dir_path)] = '\0';
		free(prev_path);
	}
	else
		new_dir_path = ft_strdup(home_path);
	return (new_dir_path);
}

int	go_to_folder(char *dir_path, char *new_dir_path, char **args_split)
{
	DIR				*rep;
	struct dirent	*fichierlu;

	if (args_split[1] && args_split[1][0] != '\n' && args_split[1][0] != '~')
	{
		rep = opendir(dir_path);
		if (!rep)
			exit(1);
		fichierlu = readdir(rep);
		if (ft_strchr(args_split[1], '\n'))
			args_split[1][ft_strlen(args_split[1]) - 1] = '\0';
		while (!ft_strncmp(fichierlu->d_name, args_split[1], \
			ft_strlen(args_split[1])) && fichierlu)
			fichierlu = readdir(rep);
		if (chdir(args_split[1]) != 0)
		{
			free(dir_path);
			return (free(new_dir_path), free(rep), perror("chdir"), 0);
		}
		free(rep);
	}
	else
		if (chdir(new_dir_path) != 0)
			return (perror("chdir "), 0);
	return (1);
}

void	update_pwds(char *dir_path, char *new_dir_path, \
					char **args_split, t_minishell *minishell)
{
	char		*home_path;
	t_envlist	*list_envs;	

	home_path = get_value_env(minishell, "HOME");
	list_envs = minishell->lst_envs;
	while (list_envs != NULL)
	{
		if (!ft_strncmp(list_envs->key, "PWD", 3))
		{
			if (args_split[1] && !ft_strncmp(args_split[1], ".", 1) && \
				(ft_strlen(args_split[1]) - 1 == ft_strlen(".") || \
				ft_strlen(args_split[1]) == ft_strlen(".")))
				return (free(new_dir_path));
			free(list_envs->splitting[1]);
			list_envs->splitting[1] = new_dir_path;
			list_envs->value = new_dir_path;
		}
		if (!ft_strncmp(list_envs->key, "OLDPWD", 6))
		{
			free(list_envs->splitting[1]);
			list_envs->splitting[1] = dir_path;
			list_envs->value = dir_path;
		}
		list_envs = list_envs->next;
	}
}

void	ft_cd(char **args_split, t_minishell *minishell)
{
	char			*dir_path;
	char			*dir_path_tmp;
	char			*new_dir_path;

	check_args(args_split, minishell);
	dir_path = NULL;
	dir_path = getcwd(dir_path, PATH_MAX);
	new_dir_path = NULL;
	if (!args_split[1] || args_split[1][0] == '\n' || \
		args_split[1][0] == '~')
		new_dir_path = particular_path(minishell, dir_path, 0);
	else if (!ft_strncmp(args_split[1], "..", 2) && (ft_strlen(args_split[1]) \
	- 1 == ft_strlen("..") || ft_strlen(args_split[1]) == ft_strlen("..")))
		new_dir_path = particular_path(minishell, dir_path, 1);
	if (args_split[1] && ft_strncmp(args_split[1], "..", 2) && \
		args_split[1][0] != '\n' && ft_strncmp(args_split[1], "~", 1))
	{
		dir_path_tmp = ft_strjoin(dir_path, "/");
		new_dir_path = ft_strjoin(dir_path_tmp, args_split[1]);
		free(dir_path_tmp);
		if (!ft_strchr(args_split[2], '\n'))
			new_dir_path[ft_strlen(new_dir_path) - 1] = '\0';
	}
	if (go_to_folder(dir_path, new_dir_path, args_split))
		update_pwds(dir_path, new_dir_path, args_split, minishell);
}

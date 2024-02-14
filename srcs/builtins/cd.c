/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:25:33 by yrio              #+#    #+#             */
/*   Updated: 2024/02/14 08:33:31 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

void	check_unset(t_minishell *minishell)
{
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

char	*go_to_home(t_minishell *minishell)
{
	char	*home_path;
	char	*new_dir_path;
	
	home_path = get_value_env(minishell, "HOME");
	if (chdir(home_path) != 0)
		perror("chdir");
	home_path[ft_strlen(home_path)] = '\0';
	new_dir_path = ft_strdup(home_path);
	return (new_dir_path);
}

char	*previous_path(char *dir_path)
{
	char	*prev_path;
	char	*new_dir_path;
	int		tmp;

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
	free(prev_path);
	return (new_dir_path);
}

char	*go_to_folder(char *dir_path, char **args_split)
{
	DIR*			rep;
	struct dirent*	fichierLU;
	char			*dir_path_tmp;
	char			*new_dir_path;

	rep = NULL;
	fichierLU = NULL;
	dir_path_tmp = ft_strjoin(dir_path, "/");
	new_dir_path = ft_strjoin(dir_path_tmp, args_split[1]);
	free(dir_path_tmp);
	rep = opendir(dir_path);
	if (!rep)
		exit(1);
	fichierLU = readdir(rep);
	args_split[1][ft_strlen(args_split[1]) - 1] = '\0';
	while (!ft_strncmp(fichierLU->d_name, args_split[1], \
		ft_strlen(args_split[1])) && fichierLU)
		fichierLU = readdir(rep);
	if (chdir(args_split[1]) != 0)
		perror("chdir ");
	free(rep);
	return (new_dir_path);
}

void	update_pwds(char *dir_path, char *new_dir_path, t_minishell *minishell)
{
	char		*home_path;
	env_list	*list_envs;	

	home_path = get_value_env(minishell, "HOME");
	list_envs = minishell->lst_envs;
	while (list_envs != NULL)
	{
		if (!ft_strncmp(list_envs->key, "PWD", 3))
		{
			free(list_envs->splitting[1]);
			list_envs->splitting[1] = new_dir_path;
			list_envs->value =  new_dir_path;
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
	char			*new_dir_path;

	check_unset(minishell);
	dir_path = NULL;
	dir_path = getcwd(dir_path, PATH_MAX);
	new_dir_path = NULL;
	if (!args_split[1])
		new_dir_path = go_to_home(minishell);
	else if (!ft_strncmp(args_split[1], "..", 2) && \
		ft_strlen(args_split[1]) - 1 == ft_strlen(".."))
	{
		if (chdir("..") != 0)
			perror("chdir ");
		new_dir_path = previous_path(dir_path);
		new_dir_path[ft_strlen(new_dir_path) - 1] = '\0';
	}
	else if (args_split[1])
	{
		new_dir_path = go_to_folder(dir_path, args_split);
		new_dir_path[ft_strlen(new_dir_path) - 1] = '\0';
	}
	update_pwds(dir_path, new_dir_path, minishell);
}

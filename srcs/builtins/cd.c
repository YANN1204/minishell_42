/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:25:33 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 11:57:56 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

void	update_pwds(char *dir_path, char *new_dir_path, env_list *list_envs)
{
	char	*old_pwd;
	int		tmp;
	int		tmp2;

	tmp = 0;
	tmp2 = 0;
	old_pwd = NULL;
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

void	cd_builtins(char **argv, t_minishell *minishell)
{
	DIR* rep;
	struct dirent* fichierLU;
	char	*dir_path;
	char	*dir_path_tmp;
	char	*new_dir_path;

	(void)argv;
	dir_path = NULL;
	dir_path = getcwd(dir_path, PATH_MAX);
	rep = NULL;
	fichierLU = NULL;
	rep = opendir(dir_path);
	if (!rep)
		exit(1);
	fichierLU = readdir(rep);
	while (!ft_strncmp(fichierLU->d_name, "libft", 5) && fichierLU)
		fichierLU = readdir(rep);
	dir_path_tmp = ft_strjoin(dir_path, "/");
	new_dir_path = ft_strjoin(dir_path_tmp, "libft");
	chdir("libft");
	update_pwds(dir_path, new_dir_path, minishell->lst_envs);
	free(dir_path_tmp);
	free(rep);
}

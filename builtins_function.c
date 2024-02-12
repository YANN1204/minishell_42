/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:52:13 by yrio              #+#    #+#             */
/*   Updated: 2024/02/12 17:39:02 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	update_pwds(char *dir_path, char *new_dir_path, char **env)
{
	char	*old_pwd;
	char	*current_pwd;
	int		tmp;
	int		tmp2;
	
	tmp = 0;
	tmp2 = 0;
	old_pwd = NULL;
	current_pwd = malloc(sizeof(new_dir_path));
	while (env[tmp])
	{
		if (!ft_strncmp(env[tmp], "PWD=", 4))
		{
			new_dir_path = ft_strjoin("PWD=", new_dir_path);
			env[tmp] =  new_dir_path;
		}
		if (!ft_strncmp(env[tmp], "OLDPWD=", 7))
		{
			dir_path = ft_strjoin("OLDPWD=", dir_path);
			env[tmp] = dir_path;
		}
		tmp++;
	}
}

void	cd_builtins(char **argv, char **env)
{
	DIR* rep;
	struct dirent* fichierLU;
	char	*dir_path;
	char	*new_dir_path;

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
	new_dir_path = ft_strjoin(ft_strjoin(dir_path, "/"), "libft");
	chdir("libft");
	update_pwds(dir_path, new_dir_path, env);
}

void	env_builtins(char **env)
{
	int	tmp;
	int	tmp2;
	
	tmp = 0;
	while (env[tmp])
	{
		tmp2 = 0;
		while (env[tmp][tmp2])
		{
			ft_putchar(env[tmp][tmp2]);
			tmp2++;
		}
		ft_putchar('\n');
		tmp++;
	}
}

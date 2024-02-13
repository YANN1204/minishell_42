/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:26:19 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 13:14:40 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

void	ft_env(t_minishell *minishell)
{
	env_list	*list_envs;
	
	list_envs = minishell->lst_envs;
	while (list_envs != NULL)
	{
		ft_putstr_fd(list_envs->key, 1);
		ft_putchar_fd('=', 1);
		ft_putstr_fd(list_envs->value, 1);
		ft_putchar_fd('\n', 1);
		list_envs = list_envs->next;
	}
}

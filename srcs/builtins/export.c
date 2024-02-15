/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:45:08 by yrio              #+#    #+#             */
/*   Updated: 2024/02/15 09:19:16 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	ft_export(char	**args_split, t_minishell *minishell)
{
	t_envlist	*lst_envs;
	t_envlist	*new;

	lst_envs = minishell->lst_envs;
	while (lst_envs->next)
		lst_envs = lst_envs->next;
	args_split[1][ft_strlen(args_split[1]) - 1] = '\0';
	new = lst_new(args_split[1]);
	if (!new || !new->value)
		return (free_split(new->splitting), free(new), 0);
	lst_envs->next = new;
	return (1);
}
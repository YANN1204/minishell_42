/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:38 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 11:48:21 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

env_list	*lst_new(char *str)
{
	env_list	*new;
	char		**splitting;

	new = malloc(sizeof(env_list));
	if (!new)
		exit(0);
	splitting = ft_split(str, '=');
	if (!splitting)
		exit(0);
	new->key = splitting[0];
	if (splitting[0])
		new->value = splitting[1];
	else
		new->value = NULL;
	new->splitting = splitting;
	new->next = NULL;
	return (new);
}

void	lstadd_back(env_list *new, env_list *lst)
{
	env_list	*tmp;

	tmp = lst;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = new;
}

void	lstclear(env_list *lst)
{
	env_list	*first;
	env_list	*second;

	if (lst == NULL)
		return ;
	first = lst;
	while (first != NULL)
	{
		second = first;
		first = first -> next;
		free_split(second->splitting);
		free(second);
	}
	lst = NULL;
}


env_list	*lst_index(env_list *lst, int index)
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (lst->index == index)
			return (lst);
		lst = lst -> next;
	}
	return (NULL);
}


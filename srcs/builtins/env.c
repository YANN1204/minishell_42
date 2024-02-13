/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:26:19 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 07:40:10 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../minishell.h"

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

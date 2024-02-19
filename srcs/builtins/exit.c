/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 17:45:55 by yrio              #+#    #+#             */
/*   Updated: 2024/02/19 11:56:39 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	check_out_of_range(unsigned long long value, int *error)
{
	if (value > LONG_MAX || value > -(unsigned long)LONG_MIN)
		*error = 1;
	return (*error);
}

long int	ft_atoi_long(const char *str, int *error)
{
	unsigned long long	result;
	size_t				i;
	size_t				neg;

	i = 0;
	neg = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
				neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		if (check_out_of_range(result, error))
			break;
		i++;
	}
	return ((result * neg) % 256);
}

int	is_digit(char *arg)
{
	int	tmp;

	tmp = 0;
	if  (arg[tmp] == '-' ||	arg[tmp] == '+')
		tmp++;
	while (arg[tmp])
	{
		if ((arg[tmp] < 48 || arg[tmp] > 57))
			return (0);
		tmp++;
	}
	return (1);
}

void	ft_exit(char **args_split)
{	
	int	exit_code;
	int error;
	int	tmp;

	error = 0;
	ft_putendl_fd("exit", STDOUT_FILENO);
	if (!args_split[1])
		exit_code = 0;
	if (args_split[1] && args_split[2])
		return (ft_putendl_fd("bash: exit: too many arguments", STDERR_FILENO));
	else if (args_split[1])
	{
		args_split[1][ft_strlen(args_split[1]) - 1] = '\0';
		tmp = 0;
		while (args_split[1][tmp] == ' ')
			tmp++;
		if (!is_digit(args_split[1] + tmp))
			printf("bash: exit: %s: numeric argument required", args_split[1]);
		exit_code = ft_atoi_long(args_split[1], &error);
		if (error)
			printf("bash: exit: %d: numeric argument required", exit_code);
	}
	free_split(args_split);
	exit(exit_code);
}

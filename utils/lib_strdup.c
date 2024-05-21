/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_strdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:46:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/16 15:13:31 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <stdlib.h>

char	*lib_strdup(char *str)
{
	size_t	i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (str_len(str) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i++])
		new_str[i] = str[i];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*strup_to(char *str, int n)
{
	int		i;
	char	*new_str;

	if (!str || n < 0)
		return (NULL);
	i = -1;
	new_str = malloc(sizeof(char) * (n + 1));
	if (!new_str)
		return (NULL);
	while (str[++i] && i < n)
		new_str[i] = str[i];
	new_str[i] = '\0';
	return (new_str);
}

char	*lib_strup(char *str)
{
	size_t	i;
	char	*new_str;

	if (!str)
		return (NULL);
	new_str = malloc(sizeof(char) * (str_len(str) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\0')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

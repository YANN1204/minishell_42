/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_len.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 16:22:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/04/16 14:43:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <stddef.h>

size_t	sent_len(char **sent)
{
	size_t	i;

	i = 0;
	if (!sent)
		return (0);
	while (sent[i])
		i++;
	return (i);
}

int	str_len(char *str)
{
	size_t	i;

	i = 0;
	if (!str || str[0] == 0)
		return (0);
	while (str[i])
		i++;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrio <yrio@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 08:01:00 by yrio              #+#    #+#             */
/*   Updated: 2024/02/13 11:30:56 by yrio             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <dirent.h>
# include <readline/history.h>
# include <errno.h>
# include <stdlib.h>
# include <linux/limits.h>
# include "libft/libft.h"

typedef struct t_list {
	int				index;
	char			*key;
	char			*value;
	char			**splitting;
	struct t_list	*next;
}				env_list;

typedef struct s_minishell
{
	struct t_list	*lst_envs;
}			t_minishell;


char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);

void		cd_builtins(char **argv, t_minishell *minishell);
void		env_builtins(t_minishell *minishell);

env_list	*lst_new(char *str);
void		lstadd_back(env_list *new, env_list *lst);
void		lstclear(env_list *lst);
env_list	*lst_index(env_list *lst, int index);

void		ls_cmd(void);
char		**get_paths(char **env);
char		**free_split(char **char_tab);
void		malloc_env(t_minishell *minishell, char **env);

#endif

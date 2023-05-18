/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lsts_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:14:47 by max               #+#    #+#             */
/*   Updated: 2023/02/22 17:16:28 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_free_shell(t_shell *lst)
{
	t_shell	*tmp;
	t_shell	*end;

	end = lst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->data);
		free(tmp);
	}
	lst = end;
	lst->next = NULL;
	return (0);
}

void	ft_free(t_tabs *lst)
{
	int		i;
	t_tabs	*tmp;

	i = 0;
	tmp = lst;
	while (tmp->cmds[i])
		free(tmp->cmds[i++]);
	free(tmp->cmds);
	i = 0;
	while (tmp->paths[i])
		free(tmp->paths[i++]);
	free(tmp->paths);
	i = 0;
	while (tmp->redop[i])
		free(tmp->redop[i++]);
	free(tmp->redop);
}

int	ft_free_tabs(t_tabs *lst)
{
	t_tabs	*end;
	t_tabs	*tmp;

	end = lst;
	lst = lst->next;
	while (lst != NULL)
	{
		tmp = lst;
		ft_free(lst);
		lst = lst->next;
		free(tmp);
	}
	lst = end;
	lst->next = NULL;
	return (0);
}

void	ft_free_lst(t_shell *shell, t_tabs *tabs, char *input, int index)
{
	free(input);
	if (index > 0)
	{
		ft_free_shell(shell);
		if (index == 2)
		{
			ft_free_tabs(tabs);
			free(tabs);
		}
	}
}

void	ft_free_var(t_var var)
{
	int	i;

	i = 0;
	while (var.env[i])
		free(var.env[i++]);
	free(var.env);
	i = 0;
	while (var.exp[i])
		free(var.exp[i++]);
	free(var.exp);
}

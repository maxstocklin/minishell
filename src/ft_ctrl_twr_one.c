/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_twr_one.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstockli <mstockli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 23:27:44 by max               #+#    #+#             */
/*   Updated: 2023/03/20 17:37:02 by mstockli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_ctrl_prs(t_shell **shell, t_var *var, char *input, t_tabs *tabs)
{
	if (parsing_quotations(shell, input) == FALSE)
	{
		write (2, "minishell: error: quote not finished\n", 37);
		g_status = 1;
		ft_free_lst(*shell, tabs, input, 1);
		return (FALSE);
	}
	(*shell) = parsing_spaces(shell);
	(*shell) = parsing_pipes(*shell);
	(*shell) = parsing_redops(shell);
	(void)var;
	(*shell) = parsing_spaces(shell);
	(*shell) = ft_space_redops(shell);
	if (ft_check_op(*shell) == FALSE)
	{
		ft_free_lst(*shell, tabs, input, 1);
		return (FALSE);
	}
	return (TRUE);
}

int	ft_ctrl_cmd(t_tabs **tabs, t_shell **shell, t_var *var)
{
	*tabs = ft_regroup(shell, var);
	ft_redops(tabs);
	ft_pars_dollar(tabs, var);
	ft_reparse_spaces(tabs);
	ft_check_ambiguity(tabs);
	ft_trim_quotes(tabs);
	ft_paths(*var, tabs);
	return (TRUE);
}

void	ft_ctrl_twr(t_var *var)
{
	t_shell	*shell;
	t_tabs	*tabs;
	char	*input;

	shell = malloc(sizeof(t_shell));
	if (!shell)
		exit (EXIT_FAILURE);
	shell->next = NULL;
	while (1)
	{
		input = ft_prompt(var);
		if (ft_check_spaces(input) == TRUE)
			ft_free_lst(shell, tabs, input, 0);
		else
		{
			if (ft_ctrl_prs(&shell, var, input, tabs) == TRUE)
			{
				ft_ctrl_cmd(&tabs, &shell, var);
				ft_execution(tabs, var);
				ft_free_lst(shell, tabs, input, 2);
			}
		}
		ft_signals(TRUE);
		var->tmp_g = g_status;
	}
}

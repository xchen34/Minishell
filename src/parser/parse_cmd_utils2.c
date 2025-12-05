/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leochen <leochen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 19:12:23 by yu-chen           #+#    #+#             */
/*   Updated: 2024/07/01 18:13:54 by leochen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	replace_inquote_pipe(char *s)
{
	char	quote;

	quote = 0;
	while (*s)
	{
		if ((*s == '\"' || *s == '\'') && !quote)
			quote = *s;
		else if (*s == quote)
			quote = 0;
		else if (*s == '|' && quote)
			*s = '\x01';
		s++;
	}
}

void	reset_inquote_pipe(char **splited_cmds)
{
	char	*cmd;

	while (*splited_cmds)
	{
		cmd = *splited_cmds;
		while (*cmd)
		{
			if (*cmd == '\x01')
				*cmd = '|';
			cmd++;
		}
		splited_cmds++;
	}
}

char	**split_all_cmds(char *cmd_line)
{
	char	*cmd_copy;
	char	**splited_cmds;

	cmd_copy = ft_strdup(cmd_line);
	replace_inquote_pipe(cmd_copy);
	splited_cmds = ft_split(cmd_copy, '|');
	reset_inquote_pipe(splited_cmds);
	free(cmd_copy);
	return (splited_cmds);
}

char	**split_one_arg(char *cmd)
{
	char	**args;

	if (!has_quote(cmd))
		return (ft_split(cmd, ' '));
	replace_inquote_spaces(cmd);
	remove_quotes(cmd);
	args = ft_split(cmd, ' ');
	reset_spaces(args);
	return (args);
}

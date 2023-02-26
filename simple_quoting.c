/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_quoting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:03:32 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 19:35:02 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_ert	_squoting_process_ep(void);

t_ert	squoting_process(t_token *voided, t_token *token, t_token **end_of_quot_pt)
{
	(void)voided;
	while(token->token != EOL && token->sign_char != '\'')
	{
		token->esec = SECURED;
		token = token->next;
	}
	*end_of_quot_pt = token;
	if (token->token == EOL)
		return (_squoting_process_ep());
	return (SUCCESS);
}

static t_ert	_squoting_process_ep(void)
{
	write(2, "syntax error near newline.\nLine can't end with open simple quote\n", 65);
	return (FAILURE);
}
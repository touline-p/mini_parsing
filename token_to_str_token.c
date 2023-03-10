/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_to_str_token.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 00:53:13 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/03/10 01:41:35 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_ert	_get_str_token_on_and_reset_pin(t_string_token **str_tok_pt, t_token **pin_pt);
static void		*_token_lst_to_str_token_ep(t_token *trash);

t_string_token *token_lst_to_str_token(t_token *tok)
{
	t_string_token	*str_token_list;
	t_token 		*pin;

	if (string_token_creator_on(&str_token_list) != SUCCESS)
		return (_token_lst_to_str_token_ep(tok));
	str_token_list->token = START;
	while (pin->token != EOL)
	{
		if (_get_str_token_on_and_reset_pin(&str_token_list->next, &pin) != SUCCESS)
			return (_token_lst_to_str_token_ep(tok));
		str_token_list = str_token_list->next;
	}
	str_token_list->next = NULL;
	token_lst_clear(tok);
	return (str_token_list);
}

static t_ert	_get_str_token_on_and_reset_pin(t_string_token **str_tok_pt, t_token **pin_pt)
{
	if (string_token_creator_on(str_tok_pt) != SUCCESS)
		return (FAILURE);
	(void)pin_pt;
	return (SUCCESS);
}

static void		*_token_lst_to_str_token_ep(t_token *trash)
{
	(void)trash;
	return (NULL);
}

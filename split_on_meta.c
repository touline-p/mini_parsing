/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_meta.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 17:27:20 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/26 17:36:40 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_parsing.h"

static t_token	*_ret_next_word(t_token *tok);
static t_token	*_ret_next_meta(t_token *tok);

t_token	*split_on_meta(t_token *tok)
{
	t_token	*ret_val;

	ret_val = tok;
	while(tok != NULL)
	{
		if (tok->token == LETTER)
			tok->next_word = _ret_next_meta(tok);
		else
			tok->next_word = _ret_next_word(tok);
		tok = tok->next_word;
	}
	return (ret_val);
}

static t_token	*_ret_next_word(t_token *tok)
{
//	t_token *pin;
	(void)tok;
	return (NULL);
}

static t_token	*_ret_next_meta(t_token *tok)
{

	(void)tok;
	return (NULL);

}